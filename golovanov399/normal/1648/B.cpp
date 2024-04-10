#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), c = nxt();
	vector<int> p(c + 1);
	for (int i = 0; i < n; ++i) {
		p[nxt()] += 1;
	}
	for (int i = 1; i <= c; ++i) {
		p[i] += p[i - 1];
	}
	auto get = [&](int l, int r) {
		return p[min(c, r - 1)] - p[min(c, l - 1)];
	};
	for (int i = 1; i <= c; ++i) {
		for (int j = 1; i * j <= c; ++j) {
			if (!get(i, i + 1) && get(j, j + 1) && get(i * j, (i + 1) * j)) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
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