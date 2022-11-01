#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int n;
vector<ll> value;
vector<int> odd, even;
vector<ll> func;
vector<vector<int>> g;

void dfs(int v, int p = -1, int d = 0) {
	if (d & 1) {
		++odd[v];
	} else {
		++even[v];
	}
	for (int u : g[v]) {
		if (u != p) {
			dfs(u, v, d + 1);
			odd[v] += odd[u];
			even[v] += even[u];
		}
	}
}

ll pow(ll x, ll p) {
	if (!p) {
		return 1;
	}
	if (p & 1) {
		return x * pow(x, p - 1) % MOD;
	} else {
		ll res = pow(x, p / 2);
		return res * res % MOD;
	}
}

ll inv(ll x) {
	return pow(x, MOD - 2);
}

ll sum(const vector<ll>& a) {
	ll res = 0;
	for (ll x : a) {
		res += x;
		res %= MOD;
	}
	return res;
}

ll sum2(const vector<ll>& a) {
	ll res = 0;
	for (ll x : a) {
		res += x * x;
		res %= MOD;
	}
	return res;
}

ll calc_positive(const vector<ll>& a, const vector<ll>& b) {
	ll sa = sum(a);
	ll sa2 = sum2(a);
	ll res_a = (sa * sa - sa2) % MOD * inv(2) % MOD;
	ll sb = sum(b);
	ll sb2 = sum2(b);
	ll res_b = (sb * sb - sb2) % MOD * inv(2) % MOD;
	ll res_1 = sa;
	ll res = res_a * 2 - res_b * 2 + res_1 * 2 + 1;
	return (res % MOD + MOD) % MOD;
}

void solve(int v, int p = -1, int d = 0) {
	vector<ll> a, b;
	for (int u : g[v]) {
		if (u == p) {
			a.push_back(even[0] - even[v]);
			b.push_back(odd[0] - odd[v]);
		} else {
			solve(u, v, d + 1);
			a.push_back(even[u]);
			b.push_back(odd[u]);
		}
	}
	if (d & 1) {
		swap(a, b);
	}
	ll pos = calc_positive(a, b);
	func[v] = (pos * value[v] % MOD + MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	value.resize(n);
	for (int v = 0; v < n; ++v) {
		cin >> value[v];
	}
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	odd.resize(n);
	even.resize(n);
	func.resize(n);
	dfs(0);
	solve(0);
	ll ans = 0;
	for (ll x : func) {
		ans += x;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}