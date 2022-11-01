#include <iostream>
#include <vector>

#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll n, k;
ll cnt = 0, siz = 0;
vector <bool> used;
vector <ll> comp_siz, comp_pr;
vector <vector <ll>> g;

void dfs(ll u) {
	used[u] = true;
	comp_pr[u] = cnt;
	siz++;
	for (auto to : g[u])
		if (!used[to])
			dfs(to);
}

int main() {
	cin >> n >> k;
	used.resize(n);
	g.resize(n);
	comp_pr.resize(n);
	for (ll i = 0; i < n - 1; i++) {
		ll u, v, hm;
		cin >> u >> v >> hm;
		if (hm == 1)
			continue;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (ll i = 0; i < n; i++)
		if (!used[i]) {
			siz = 0;
			dfs(i);
			comp_siz.push_back(siz);
			cnt++;
		}
	ll ans = 0;
	for (ll i = 0; i < comp_siz.size(); i++) {
		ll x = 1;
		for (ll j = 0; j < k; j++)
			x = (x * comp_siz[i]) % MOD;
		ans = (ans + x) % MOD;
	}
	ll x = 1;
	for (ll i = 0; i < k; i++)
		x = (n * x) % MOD;
	cout << (x + MOD - ans) % MOD;
	return 0;
}