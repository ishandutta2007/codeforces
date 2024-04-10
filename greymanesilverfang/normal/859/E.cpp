#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MOD = 1e9 + 7, N = 2e5 + 5;
int f[N], v[N], r[N]; vector<int> adj[N];

long long bfs(int x) {
	queue<int> Q; int res = 1;
	for (Q.push(x); !Q.empty(); Q.pop())
		for (int i : adj[Q.front()])
			Q.push(i), ++res;
	return res;
}

int main() {
	int n, ans = 1; scanf("%d", &n);
	for (int i = 0, a, b; i < n; adj[f[a] = b].push_back(a), ++i)
		scanf("%d%d", &a, &b);
	for (int i = 1, j; i <= 2 * n; ++i)
		for (r[j = i] = i; v[j] != 2; r[j = f[j]] = i) {
			if (f[j] == 0 || f[j] == j) break;
			if (r[f[j]] && r[f[j]] != i) break;
			if (v[j]++ == 1 && v[f[j]] == 2)
				(ans <<= 1) %= MOD;
		}
	for (int i = 1; i <= 2 * n; ++i) 
		if (!f[i]) ans = bfs(i) * ans % MOD;
	printf("%d", ans);
}