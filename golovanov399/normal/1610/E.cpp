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
	generate(all(a), nxt);
	int ans = 0;
	int last = -1;

	auto f = [&](int x) {
		int pos = lower_bound(all(a), x) - a.begin();
		int res = 0;
		while (pos < n && a[pos] == x) {
			++pos;
			++res;
		}
		if (pos == n) {
			return res;
		}
		int d = a[pos] - x;
		res += 1;
		while (true) {
			pos = lower_bound(all(a), x + 2 * d) - a.begin();
			if (pos == n) {
				break;
			}
			++res;
			d = a[pos] - x;
		}
		return res;
	};

	for (int x : a) {
		if (x == last) {
			continue;
		}
		ans = max(ans, f(x));
		last = x;
	}
	cout << n - ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}