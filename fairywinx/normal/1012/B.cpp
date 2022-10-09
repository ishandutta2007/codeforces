#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct dsu {
	vector<int> p, s;
	dsu(int n) {
		s.resize(n, 1);
		p.resize(n);
		for (int i = 0; i < n; ++i)
			p[i] = i;
	}

	int get(int a) {
		if (p[a] == a)
			return a;
		return p[a] = get(p[a]);
	}

	void merge(int a, int b) {
		a = get(a), b = get(b);
		if (a == b)
			return;
		if (s[a] > s[b])
			p[b] = a, s[a] += s[b];
		else
			p[a] = b, s[b] += s[a];
	}
};

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> pos_x(n), pos_y(m);
	if (q == 0) {
		cout << n + m - 1 << '\n';
		return 0;
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		pos_x[a - 1].push_back(b - 1);
		pos_y[b - 1].push_back(a - 1);
	}
	dsu x(n), y(m);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!pos_x[i].size())
			++ans;
		for (int j : pos_x[i])
			y.merge(j, pos_x[i][0]);
	}
	for (int i = 0; i < m; ++i) {
		if (!pos_y[i].size())
			++ans;
		for (int j : pos_y[i])
			x.merge(j, pos_y[i][0]);
	}
	// ans = max(ans - 1, 0);
	set<int> comp_x, comp_y;
	for (int i = 0; i < n; ++i) {
		if (pos_x[i].size())
			comp_x.insert(x.get(i));
	}
	for (int i = 0; i < m; ++i) {
		if (pos_y[i].size())
			comp_y.insert(y.get(i));
	}
	cout << ans + min(max((int) comp_y.size() - 1, 0), max((int) comp_x.size() - 1, 0)) << '\n';
}