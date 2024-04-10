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
	vector<int> p(n);
	generate(all(p), nxt);
	vector<int> dec_left(n, 1), dec_right(n, 1), inc_left(n, 1), inc_right(n, 1);
	for (int i = 1; i < n; ++i) {
		if (p[i - 1] < p[i]) {
			dec_left[i] = dec_left[i - 1] + 1;
		} else {
			inc_left[i] = inc_left[i - 1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		if (p[i + 1] < p[i]) {
			dec_right[i] = dec_right[i + 1] + 1;
		} else {
			inc_right[i] = inc_right[i + 1] + 1;
		}
	}

	vector<int> second_moves(n);
	for (int i = 0; i < n; ++i) {
		second_moves[i] = max(inc_left[i], inc_right[i]) - 1;
	}
	vector<int> pref(n + 1), suf(n + 1);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = max(pref[i], second_moves[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = max(suf[i + 1], second_moves[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (dec_left[i] <= 2 || dec_right[i] <= 2) {
			continue;
		}
		if (dec_left[i] - dec_left[i] % 2 - 1 >= dec_right[i] - 1) {
			continue;
		}
		if (dec_right[i] - dec_right[i] % 2 - 1 >= dec_left[i] - 1) {
			continue;
		}
		int opponent = max({pref[i - dec_left[i] + 1], suf[i + dec_right[i]], inc_left[i - dec_left[i] + 1] - 1, inc_right[i + dec_right[i] - 1] - 1});
		ans += (opponent < max(dec_left[i], dec_right[i]) - 1);
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}