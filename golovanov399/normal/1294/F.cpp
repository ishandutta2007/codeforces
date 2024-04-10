#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222222;

vector<int> a[N];
vector<pair<int, int>> depth[N];
int pid[N];
int par[N];

pair<int, int> dfsDown(int v, int p = -1) {
	par[v] = p;
	pid[v] = -1;
	depth[v].resize(a[v].size());
	pair<int, int> res = {-1, v};
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			pid[v] = i;
		} else {
			res = max(res, depth[v][i] = dfsDown(a[v][i], v));
		}
	}
	res.first += 1;
	return res;
}

void dfsUp(int v) {
	int sz = a[v].size();
	vector<pair<int, int>> pref(sz + 1), suf(sz + 1);
	for (int i = 0; i < (int)a[v].size(); ++i) {
		pref[i + 1] = max(pref[i], {depth[v][i].first + 1, depth[v][i].second});
	}
	for (int i = (int)a[v].size() - 1; i >= 0; --i) {
		suf[i] = max(suf[i + 1], {depth[v][i].first + 1, depth[v][i].second});
	}

	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (i == pid[v]) {
			continue;
		}
		depth[a[v][i]][pid[a[v][i]]] = max({pref[i], suf[i + 1], {0, v}});
		dfsUp(a[v][i]);
	}
}

int main() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfsDown(0);
	dfsUp(0);

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < (int)a[i].size(); ++j) {
	// 		cerr << i + 1 << " -> " << a[i][j] + 1 << ": " << depth[i][j].first << "\n";
	// 	}
	// }

	pair<int, vector<int>> ans = {0, {}};
	for (int i = 0; i < n; ++i) {
		sort(all(depth[i]));
		reverse(all(depth[i]));
		if ((int)depth[i].size() >= 3) {
			ans = max(ans, {depth[i][0].first + depth[i][1].first + depth[i][2].first + 3, {depth[i][0].second, depth[i][1].second, depth[i][2].second}});
		}
		if ((int)depth[i].size() >= 2) {
			ans = max(ans, {depth[i][0].first + depth[i][1].first + 2, {depth[i][0].second, depth[i][1].second, i}});
		}
	}
	cout << ans.first << "\n";
	for (int x : ans.second) {
		cout << x + 1 << " ";
	}
	cout << "\n";

	return 0;
}