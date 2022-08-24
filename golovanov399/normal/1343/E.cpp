#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), m = nxt(), va = nxt() - 1, vb = nxt() - 1, vc = nxt() - 1;
	vector<int> p(m);
	generate(all(p), nxt);
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	auto bfs = [&](int v) {
		vector<int> d(n, -1);
		d[v] = 0;
		queue<int> q;
		q.push(v);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int x : a[v]) {
				if (d[x] == -1) {
					d[x] = d[v] + 1;
					q.push(x);
				}
			}
		}
		return d;
	};

	auto da = bfs(va);
	auto db = bfs(vb);
	auto dc = bfs(vc);
	vector<long long> ps(m + 1);
	sort(all(p));
	for (int i = 0; i < m; ++i) {
		ps[i + 1] = ps[i] + p[i];
	}
	long long ans = 1e18;
	for (int i = 0; i < n; ++i) {
		if (da[i] + db[i] + dc[i] > m) {
			continue;
		}
		ans = min(ans, ps[db[i]] + ps[da[i] + db[i] + dc[i]]);
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}