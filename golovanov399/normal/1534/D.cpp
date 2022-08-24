#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

vector<int> ask(int v, int n) {
	cout << "? " << v + 1 << endl;
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = nxt();
	}
	return ans;
}

void solve() {
	int n = nxt();
	vector<vector<int>> a(n);
	auto d = ask(0, n);

	auto handle = [&](const vector<int>& d, int v) {
		for (int i = 0; i < n; ++i) {
			if (d[i] == 1) {
				a[v].push_back(i);
			}
		}
	};

	vector<int> par[2];
	for (int i = 1; i < n; ++i) {
		par[d[i] % 2].push_back(i);
	}
	int p = 0;
	if (par[1].size() < par[0].size()) {
		p = 1;
	}
	if (p == 0) {
		handle(d, 0);
	}
	for (int x : par[p]) {
		auto v = ask(x, n);
		handle(v, x);
	}
	cout << "!" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j : a[i]) {
			cout << i + 1 << " " << j + 1 << endl;
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}