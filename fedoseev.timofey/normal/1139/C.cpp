#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += md;
}

int power(int a, ll b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) res = mul(a, res);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

const int N = 1e5 + 7;

vector <pair <int, int>> g[N];
bool used[N];

int cnt = 0;
int sz[N];

void dfs(int u) {
	used[u] = 1;
	++sz[cnt];
	for (auto p : g[u]) {
		if (p.second == 0 && !used[p.first]) {
			dfs(p.first);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    int ans = power(n, k);
    for (int i = 0; i + 1 < n; ++i) {
    	int u, v, t;
    	cin >> u >> v >> t;
    	--u, --v;
    	g[u].push_back({v, t});
    	g[v].push_back({u, t});
    }
    for (int i = 0; i < n; ++i) {
    	if (!used[i]) {
    		dfs(i);
    		++cnt;
    	}
    }
    for (int i = 0; i < cnt; ++i) {
    	sub(ans, power(sz[i], k));
    }
    cout << ans << '\n';
}