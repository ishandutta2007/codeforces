#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

vector <bool> used;
vector <ll> d;
vector <vector <ll>> g;

void dfs(ll v) {
	used[v] = true;
	for (ll u : g[v])
		if (!used[u]) {
			d[u] = d[v] + 1;
			dfs(u);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector <ll> a(n), b(n), c(n);
	g.resize(n), d.resize(n), used.resize(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	for (ll i = 0; i < n; i++)
		cin >> c[i];
	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		v--;
		u--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll root;
	for (ll i = 0; i < n; i++) {
		if (g[i].size() > 2) {
			cout << -1;
			return 0;
		}
		if (g[i].size() == 1)
			root = i;
	}
	dfs(root);
	ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0;
	for (ll i = 0; i < n; i++) {
		if (d[i] % 3 == 0)
			ans1 += a[i];
		if (d[i] % 3 == 1)
			ans1 += b[i];
		if (d[i] % 3 == 2)
			ans1 += c[i];
	}
	for (ll i = 0; i < n; i++) {
		if (d[i] % 3 == 0)
			ans2 += a[i];
		if (d[i] % 3 == 1)
			ans2 += c[i];
		if (d[i] % 3 == 2)
			ans2 += b[i];
	}
	for (ll i = 0; i < n; i++) {
		if (d[i] % 3 == 0)
			ans3 += b[i];
		if (d[i] % 3 == 1)
			ans3 += a[i];
		if (d[i] % 3 == 2)
			ans3 += c[i];
	}
	for (ll i = 0; i < n; i++) {
		if (d[i] % 3 == 0)
			ans4 += b[i];
		if (d[i] % 3 == 1)
			ans4 += c[i];
		if (d[i] % 3 == 2)
			ans4 += a[i];
	}
	for (ll i = 0; i < n; i++) {
		if (d[i] % 3 == 0)
			ans5 += c[i];
		if (d[i] % 3 == 1)
			ans5 += a[i];
		if (d[i] % 3 == 2)
			ans5 += b[i];
	}
	for (ll i = 0; i < n; i++) {
		if (d[i] % 3 == 0)
			ans6 += c[i];
		if (d[i] % 3 == 1)
			ans6 += b[i];
		if (d[i] % 3 == 2)
			ans6 += a[i];
	}
	ll x = 1e18;
	x = min(ans1, x);
	x = min(ans2, x);
	x = min(ans3, x);
	x = min(ans4, x);
	x = min(ans5, x);
	x = min(ans6, x);
	cout << x << endl;
	if (x == ans1) {
		for (ll i = 0; i < n; i++) {
			if (d[i] % 3 == 0)
				cout << 1 << " ";
			if (d[i] % 3 == 1)
				cout << 2 << " ";
			if (d[i] % 3 == 2)
				cout << 3 << " ";
		}
		return 0;
	}
	if (x == ans2) {
		for (ll i = 0; i < n; i++) {
			if (d[i] % 3 == 0)
				cout << 1 << " ";
			if (d[i] % 3 == 1)
				cout << 3 << " ";
			if (d[i] % 3 == 2)
				cout << 2 << " ";
		}
		return 0;
	}
	if (x == ans3) {
		for (ll i = 0; i < n; i++) {
			if (d[i] % 3 == 0)
				cout << 2 << " ";
			if (d[i] % 3 == 1)
				cout << 1 << " ";
			if (d[i] % 3 == 2)
				cout << 3 << " ";
		}
		return 0;
	}
	if (x == ans4) {
		for (ll i = 0; i < n; i++) {
			if (d[i] % 3 == 0)
				cout << 2 << " ";
			if (d[i] % 3 == 1)
				cout << 3 << " ";
			if (d[i] % 3 == 2)
				cout << 1 << " ";
		}
		return 0;
	}
	if (x == ans5) {
		for (ll i = 0; i < n; i++) {
			if (d[i] % 3 == 0)
				cout << 3 << " ";
			if (d[i] % 3 == 1)
				cout << 1 << " ";
			if (d[i] % 3 == 2)
				cout << 2 << " ";
		}
		return 0;
	}
	if (x == ans6) {
		for (ll i = 0; i < n; i++) {
			if (d[i] % 3 == 0)
				cout << 3 << " ";
			if (d[i] % 3 == 1)
				cout << 2 << " ";
			if (d[i] % 3 == 2)
				cout << 1 << " ";
		}
		return 0;
	}
	return 0;
}