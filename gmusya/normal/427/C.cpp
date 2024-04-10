#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll n;
vector <bool> used;
vector <ll> a, order;
vector <vector <ll>> g, gr;
vector <vector <ll>> comps;

void dfs1(ll v) {
	used[v] = true;
	for (ll to : g[v])
		if (!used[to])
			dfs1(to);
	order.push_back(v);
}

void dfs2(ll v, ll pos) {
	used[v] = true;
	for (ll to : gr[v])
		if (!used[to])
			dfs2(to, pos);
	comps[pos].push_back(v);
}

int main() {
	cin >> n;
	a.resize(n), used.resize(n), g.resize(n), gr.resize(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	for (ll i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	used.assign(n, false);
	for (ll i = 0; i < n; i++) {
		if (!used[order[n - i - 1]]) {
			comps.push_back({});
			dfs2(order[n - i - 1], comps.size() - 1);
		}
	}
	ll sum = 0, mult = 1;
	for (vector <ll> arr : comps) {
		ll mi = 1e12;
		for (ll v : arr)
			mi = min(a[v], mi);
		sum += mi;
		ll k = 0;
		for (ll v : arr)
			k += (a[v] == mi);
		mult = (mult * k) % (1000000007);
	}
	cout << sum << " " << mult;
	return 0;
}