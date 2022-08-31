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
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	set<int> good;
	multiset<int> bad;
	for (int x : a) {
		if (x <= n && !good.count(x)) {
			good.insert(x);
		} else {
			bad.insert(x);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (good.count(i)) {
			continue;
		}
		++ans;
		auto it = bad.upper_bound(2 * i);
		if (it != bad.end()) {
			bad.erase(it);
		} else {
			auto oit = good.upper_bound(2 * i);
			if (oit == good.end()) {
				cout << "-1\n";
				return;
			} else {
				good.erase(oit);
			}
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