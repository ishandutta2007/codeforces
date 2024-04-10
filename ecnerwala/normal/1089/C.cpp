#include <bits/stdc++.h>
using namespace std;

int dist[510][510];
vector <int> ve[510];
int ma[510];
char S[110];
int n;
int a[510];
int m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = (i == j ? 0 : 1e9);
	for (int i = 1; i <= m; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
			scanf("%d", &a[j]);
		for (int j = 1; j < k; j++) {
			int x = a[j], y = a[j + 1];
			dist[x][y] = dist[y][x] = 1;
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int T = n;
	while (T--) {
		vector <int> V;
		for (int i = 1; i <= n; i++)
			V.push_back(i);
		while (true) {
			for (int i = 1; i <= n; i++) {
				ma[i] = 0;
				for (auto j: ve[i]) {
					int cnt = 0;
					for (auto k: V)
						if (dist[k][j] < dist[k][i])
							cnt++;
					ma[i] = max(ma[i], cnt);
				}
			}
			// for (auto x: V)
			// 	printf("%d ", x);
			// printf("\n");
			// for (int i = 1; i <= n; i++)
			// 	printf("%d ", ma[i]);
			// printf("\n");
			int mi = 1;
			for (int i = 1; i <= n; i++)
				if (ma[i] < ma[mi])
					mi = i;
			printf("%d\n", mi);
			fflush(stdout);
			scanf("%s", S);
			if (S[0] == 'F') {
				break;
			}else {
				// printf("hehehe\n");
				int xx;
				scanf("%d", &xx);
				vector <int> VV;
				for (auto x: V) {
					// printf("ff %d %d %d\n", x, dist[xx][x], dist[mi][x]);
					if (dist[xx][x] < dist[mi][x]) {
						// printf("%d %d %d %d %d\n",x, xx, mi, dist[xx][x], dist[mi][x]);
						VV.push_back(x);
					}
				}
				V = VV;
			}
		}
	}
}