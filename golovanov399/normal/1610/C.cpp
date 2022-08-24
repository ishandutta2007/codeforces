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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
		b[i] = nxt();
	}

	auto check = [&](int cnt) {
		int cur = 0;
		for (int i = 0; i < n && cur < cnt; ++i) {
			if (a[i] >= cnt - 1 - cur && b[i] >= cur) {
				++cur;
			}
		}
		return cur == cnt;
	};

	int l = 1, r = n + 1;
	while (r > l + 1) {
		int m = (l + r) / 2;
		(check(m) ? l : r) = m;
	}
	cout << l << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}