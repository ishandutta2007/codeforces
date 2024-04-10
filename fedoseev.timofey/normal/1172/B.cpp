#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

vector <int> g[N];
const int md = 998244353;
int fac[N];
int dp[N];
int sz[N];

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

void dfs(int u, int p) {
	sz[u] = 1;
	int cnt = 0;
	int res = 1;
	for (auto v : g[u]) {
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
			++cnt;
			res = mul(res, dp[v]);
		}
	}
	if (u != 0) dp[u] = mul(cnt + 1, mul(fac[cnt], res));
	else dp[u] = mul(sz[u], mul(fac[cnt], res));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 	int n;
 	cin >> n;
 	for (int i = 0; i + 1 < n; ++i) {
 		int u, v;
 		cin >> u >> v;
 		--u, --v;
 		g[u].push_back(v);
 		g[v].push_back(u);
 	}
 	fac[0] = 1;
 	for (int i = 1; i < N; ++i) fac[i] = mul(fac[i - 1], i);
 	dfs(0, -1);
 	int sum = 0;
 	for (int i = 0; i < n; ++i) sum += sz[i];
 	cout << dp[0] << '\n';
}