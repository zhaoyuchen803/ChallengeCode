#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

const int maxn = 1000;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];

int prim(int n) {
	int lowcost[maxn];
	bool vis[maxn];
	int dis[maxn];
	memset(lowcost, 0x3f, sizeof(lowcost));
	memset(vis, false, sizeof(vis));
	int sum = 0;
	for (int j = 0; j < n; j++) lowcost[j] = G[0][j];
	int k = 0;
	vis[0] = true;
	for (int i = 1; i <= n - 1; i++) {
		int min = INF;
		for (int j = 0; j < n; j++) {
			if (min> lowcost[j])
				if (!vis[j]) {
					k = j;
					min = lowcost[j];
				}
		}
		vis[k] = true;
		sum += lowcost[k];
		for (int j = 0; j < n; j++)
			if (G[k][j] < lowcost[j] && !vis[j]) lowcost[j] = G[k][j];
	}
	return sum;
}

int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		memset(G, 0x3f, sizeof(G));
		int u, v, w;
		for (int i = 1; i <= n*(n - 1) / 2; i++) {
			scanf("%d%d%d", &u, &v, &w);
			if(G[u-1][v-1]>w) G[u-1][v-1] = G[v-1][u-1] = w;
		}
		int sum = prim(n);
		printf("%d\n", sum);
	}
	return 0;
}