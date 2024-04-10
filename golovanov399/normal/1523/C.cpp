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

void solve() {
	int n = nxt();
	vector<int> a = {};
	auto out = [&]() {
		for (int i = 0; i < (int)a.size(); ++i) {
			cout << a[i];
			if (i == (int)a.size() - 1) {
				cout << "\n";
			} else {
				cout << ".";
			}
		}
	};
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		if (x == 1) {
			a.push_back(1);
		} else {
			while (a.back() != x - 1) {
				a.pop_back();
			}
			a.back() += 1;
		}
		out();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}