#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll timer = 0, ans = 0;
vector <bool> used;
vector <ll> a, p, in, out, d;
vector <vector <pair <ll, ll>>> g;

void dfs1(ll v) {
	used[v] = true;
	in[v] = timer++;
	for (auto u : g[v])
		if (!used[u.first])
			dfs1(u.first);
	out[v] = timer++;
}

void dfs2(ll v) {
	used[v] = true;
	for (auto u : g[v]) 
		if (in[u.first] > in[v] && out[u.first] < out[v]) {
			if (!used[u.first])
				dfs2(u.first);
			p[v] += p[u.first] + 1;
		}
}

void dfs3(ll v) {
	used[v] = true;
	for (auto u : g[v])
		if (!used[u.first]) {
			d[u.first] = d[v] + u.second;
			dfs3(u.first);
		}
}

void dfs4(ll v, ll s) {
	used[v] = true;
	for (auto u : g[v]) {
		if (used[u.first])
			continue;
		if (d[u.first] - s > a[u.first]) 
			ans += p[u.first] + 1;
		else
			dfs4(u.first, min(s, d[u.first]));
	}
}

int main() {
	ll n;
	cin >> n;
	a.resize(n), g.resize(n), p.resize(n), used.resize(n), in.resize(n), out.resize(n), d.resize(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 1; i < n; i++) {
		ll v, w;
		cin >> v >> w;
		g[i].push_back({ v - 1, w });
		g[v - 1].push_back({ i, w });
	}
	dfs1(0);
	used.assign(n, false);
	dfs2(0);
	used.assign(n, false);
	dfs3(0);
	used.assign(n, false);
	dfs4(0, 0);
	cout << ans;
	return 0;
}