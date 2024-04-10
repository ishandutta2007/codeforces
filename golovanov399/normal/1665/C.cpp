#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> d(n);
	for (int i = 1; i < n; ++i) {
		d[nxt() - 1] += 1;
	}
	sort(all(d));
	reverse(all(d));
	while (!d.back()) {
		d.pop_back();
	}
	d.push_back(1);

	auto can = [&](int cnt) {
		if (cnt < (int)d.size()) {
			return false;
		}
		int need = 0;
		for (int i = 0; i < (int)d.size(); ++i) {
			need += max(0, i + d[i] - cnt);
		}
		return need + (int)d.size() <= cnt;
	};

	int l = 0, r = n;
	while (r > l + 1) {
		int m = (l + r) / 2;
		(can(m) ? r : l) = m;
	}
	cout << r << "\n";
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