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
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	auto b = a;
	sort(all(b));
	string ans = "";
	for (auto s : a) {
		bool ok = false;
		for (int i = 1; i < (int)s.length(); ++i) {
			if (binary_search(all(b), s.substr(0, i)) && binary_search(all(b), s.substr(i))) {
				ok = true;
				break;
			}
		}
		ans += (char)('0' + ok);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}