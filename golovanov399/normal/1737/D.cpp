#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int to;
	int w;
};

const int N = 505;
int qq[N];
int ql = 0, qr = 0;

int front() {
	return qq[ql++];
}

void push(int x) {
	qq[qr++] = x;
}

#define is_empty huempty

bool is_empty() {
	return ql == qr;
}

void clear() {
	ql = qr = 0;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<Edge>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	auto get_distances = [&](int from) {
		vector<int> d(n, -1);
		d[from] = 0;
		clear();
		push(from);
		while (!is_empty()) {
			int v = front();
			for (auto e : a[v]) {
				int x = e.to;
				if (d[x] == -1) {
					d[x] = d[v] + 1;
					push(x);
				}
			}
		}
		return d;
	};
	vector<vector<int>> ds(n);
	for (int i = 0; i < n; ++i) {
		ds[i] = get_distances(i);
	}
	long long ans = 1e18;
	for (int i = 0; i < n; ++i) {
		for (auto [j, w] : a[i]) {
			ans = min(ans, 1ll * w * (ds[0][i] + 1 + ds[n - 1][j]));
		}
		if (a[i].empty()) {
			continue;
		}
		int min_w = 2e9;
		for (auto e : a[i]) {
			min_w = min(min_w, e.w);
		}
		for (int j = 0; j < n; ++j) {
			ans = min(ans, min_w * 1ll * (ds[i][j] + ds[0][j] + ds[n - 1][j] + 2));
		}
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