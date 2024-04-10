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

void solve() {
	int n = nxt();
	vector<int> a(n);
	vector<int> b(n);
	for (auto& x : a) {
		x = nxt() - 1;
	}
	for (auto& x : b) {
		x = nxt() - 1;
	}

	vector<vector<int>> ac(n);
	for (int i = n - 1; i >= 0; --i) {
		if (i < n - 1 && a[i + 1] == a[i]) {
			ac[a[i]].back() += 1;
		} else {
			ac[a[i]].push_back(1);
		}
	}
	int ai = 0;
	for (int x : b) {
		while (ai < n && (a[ai] != x || ac[x].back() == 0)) {
			int y = a[ai++];
			while (ai < n && a[ai] == y) {
				++ai;
			}
			if (ac[y].back() == 0) {
				ac[y].pop_back();
				continue;
			}
			int c = ac[y].back();
			ac[y].pop_back();
			if (ac[y].empty()) {
				cout << "No\n";
				return;
			}
			ac[y].back() += c;
		}
		if (ai == n) {
			cout << "No\n";
			return;
		}
		ac[x].back() -= 1;
	}
	cout << "Yes\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}