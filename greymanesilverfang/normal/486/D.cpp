#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
int d, n, a[2000], ans;
vector<int> adj[2000];
inline bool chk(int x, int y) { 
	return ((a[x] > a[y] || a[x] == a[y] && x >= y) && a[x] <= a[y] + d); 
}

ll DFS(int cur, int prv, int root) {
	if (!chk(cur, root))
		return 1;
	ll res = 1;
	for (int i : adj[cur])
		if (i != prv)
			(res *= DFS(i, cur, root)) %= MOD;
	return ++res;
}

int main() {
	scanf("%d%d", &d, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v); --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
		(--ans += DFS(i, -1, i)) %= MOD;
	printf("%d", ans);
}