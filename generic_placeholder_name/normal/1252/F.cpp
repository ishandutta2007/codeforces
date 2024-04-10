#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int n, int k, vector<int> a, int sd) {
	cout << sd << '\n';

	vector<pair<int, int>> pos;
	for (int i = 0; i < sd; i += 2) {
		for (int j = 1; j < sd; j += 2) {
			pos.emplace_back(i, j);
		}
	}
	for (int i = 0; i < sd; i += 2) {
		for (int j = 0; j < sd; j += 2) {
			pos.emplace_back(i, j);
		}
	}
	for (int i = 1; i < sd; i += 2) {
		for (int j = 0; j < sd; j += 2) {
			pos.emplace_back(i, j);
		}
	}

	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++) {
		p.emplace_back(a[i], i+1);
	}
	sort(p.begin(), p.end(), greater<pair<int, int>>());

	vector<vector<int>> ans(sd, vector<int>(sd));
	int petr = 0;
	for (auto [cnt, val]: p) {
		while (cnt--) {
			auto [x, y] = pos[petr]; petr++;
			ans[x][y] = val;
		}
	}

	for (auto v: ans) {
		for (int u: v) {
			cout << u << ' ';
		}
		cout << '\n';
	}
}

void solve() {
	int k, n; cin >> k >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mx = *max_element(a.begin(), a.end());

	for (int sd = 1; ; sd++) {
		int sq = sd*sd - (sd/2)*(sd/2);
		int id;

		if (sd % 2) id = sd*((sd+1)/2);
		else id = sd*sd/2;

		if (id >= mx && sq >= k) {
			solve(n, k, a, sd);
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}