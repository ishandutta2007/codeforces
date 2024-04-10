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

int ask(int v) {
	cout << "? " << v + 1 << endl;
	return nxt() - 1;
}

void solve() {
	int n = nxt();
	vector<int> d(n);
	generate(all(d), nxt);
	vector<int> vertices(n);
	iota(all(vertices), 0);
	sort(all(vertices), [&](int i, int j) {
		return d[i] > d[j];
	});
	vector<int> color(n);
	iota(all(color), 0);
	vector<int> sz(n, 1);

	auto unite = [&](int c1, int c2) {
		sz[c1] += sz[c2];
		sz[c2] = 0;
		for (int i = 0; i < n; ++i) {
			if (color[i] == c2) {
				color[i] = c1;
			}
		}
	};

	for (int v : vertices) {
		while (d[v] > sz[color[v]]) {
			int x = ask(v);
			unite(color[v], color[x]);
		}
	}
	cout << "!";
	for (int x : color) {
		cout << " " << x + 1;
	}
	cout << endl;
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}