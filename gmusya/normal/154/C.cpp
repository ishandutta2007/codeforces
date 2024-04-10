#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll P = 998244353;

ll P1[1000000];
ll P2[1000000];

struct Hash {
	ll h1 = 0, h2 = 0;

	void operator+=(ll x) {
		h1 += P1[x];
		h1 %= MOD1;
		h2 += P2[x];
		h2 %= MOD2;
	}

	pair<ll, ll>operator-(ll x) const {
		ll res1 = h1 - P1[x];
		if (res1 < 0) {
			res1 += MOD1;
		}
		ll res2 = h2 - P2[x];
		if (res2 < 0) {
			res2 += MOD2;
		}
		return {res1, res2};
	}

	pair<ll, ll> Get() const {
		return {h1, h2};
	}
};

void Init() {
	P1[0] = P2[0] = 1;
	for (int i = 1; i <= 999999; ++i) {
		P1[i] = P1[i - 1] * P % MOD1;
		P2[i] = P2[i - 1] * P % MOD2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Init();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<Hash> arr(n);
	for (int v = 0; v < n; ++v) {
		for (int x : g[v]) {
			arr[v] += x;
		}
	}
	map<pair<ll, ll>, ll> cnt;
	for (int v = 0; v < n; ++v) {
		++cnt[arr[v].Get()];
	}
	ll res = 0;
	for (auto& now : cnt) {
		res += now.second * (now.second - 1) / 2;
	}
	for (int v = 0; v < n; ++v) {
		for (int u : g[v]) {
			if (u < v && arr[v] - u == arr[u] - v) {
				++res;
			}
		}
	}
	cout << res;
	return 0;
}