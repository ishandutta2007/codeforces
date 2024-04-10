#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int N = 1011111;
int erat[N];
vector<int> primes;

vector<int> g[2 * N];
int color[2 * N];
int curcol = 0;

void add_edge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

void mark_color(int v) {
	color[v] = curcol;
	for (int x : g[v]) {
		if (color[x] == -1) {
			mark_color(x);
		}
	}
}

void solve() {
	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || i * p >= N) {
				break;
			}
			erat[i * p] = p;
		}
	}
	
	int n = nxt(), q = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int i = 0; i < n; ++i) {
		int x = a[i];
		vector<int> ps;
		while (x > 1) {
			ps.push_back(erat[x]);
			x /= erat[x];
		}
		make_unique(ps);
		for (int p : ps) {
			add_edge(p, a[i] + N);
		}
	}

	memset(color, -1, sizeof(color));
	for (int x : a) {
		if (color[x + N] == -1) {
			mark_color(x + N);
			++curcol;
		}
	}

	vector<pair<int, int>> can_connect;
	for (int x : a) {
		if (color[x + N] == color[x + 1 + N]) {
			continue;
		}
		if (color[x + 1 + N] > -1) {
			can_connect.push_back({color[x + N], color[x + 1 + N]});
			continue;
		}
		vector<int> cs = {color[x + N]};
		int y = x + 1;
		while (y > 1) {
			const int p = erat[y];
			y /= p;
			if (color[p] > -1) {
				cs.push_back(color[p]);
			}
		}
		make_unique(cs);
		for (int c1 : cs) {
			for (int c2 : cs) {
				if (c2 == c1) {
					break;
				}
				can_connect.push_back({c2, c1});
			}
		}
	}
	for (auto& [x, y] : can_connect) {
		if (x > y) {
			swap(x, y);
		}
	}
	make_unique(can_connect);

	while (q--) {
		int x = a[nxt() - 1], y = a[nxt() - 1];
		int c1 = color[x + N], c2 = color[y + N];
		if (c1 > c2) {
			swap(c1, c2);
		}
		if (c1 == c2) {
			cout << "0\n";
		} else if (binary_search(all(can_connect), pair{c1, c2})) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}