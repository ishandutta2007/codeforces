#include <cstdio>
#include <cstring>
#include <cctype>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'\n", __LINE__, __FUNCTION__);
const int maxN = 19;
int n, m;
LL f[1 << maxN][maxN];
int least[1 << maxN], log[1 << maxN];
bool G[maxN][maxN];

int main() {
	
	scanf("%d%d", &n, &m);
	memset(G, 0, sizeof(G));
	for(int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		G[x][y] = G[y][x] = 1;
	}
	memset(log, 0, sizeof(log));
	for(int i = 0; i < n; ++i) log[1 << i] = i;
	for(int S = 1; S < (1 << n); ++S) least[S] = log[S ^ (S & (S - 1))];
	for(int i = 0; i < n; ++i) f[1 << i][i] = 1;
	
	LL ans = 0;
	for(int S = 1; S < (1 << n); ++S) {
		for(int u = 0; u < n; ++u) if(S & (1 << u)) {
//			printf("%d %d %lld\n", S, u, f[S][u]);
			if(least[S] != u && G[least[S]][u]) ans += f[S][u];
			for(int v = least[S] + 1; v < n; ++v) if(!(S & (1 << v)) && G[u][v]) {
				f[S | (1 << v)][v] += f[S][u];
			}
		}
	}
	ans -= m;
	printf("%lld\n", ans / 2);
	
	return 0;
}