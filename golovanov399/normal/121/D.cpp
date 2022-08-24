#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

inline long long nxtll() {
	long long x;
	scanf("%lld", &x);
	return x;
}

bool isLucky(int n) {
	while (n) {
		if (n % 10 == 4 || n % 10 == 7) {
			// pass
		} else {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	int n = nxt();
	long long k = nxtll();
	vector<pair<long long, long long>> a(n);
	long long mind = LLONG_MAX;
	vector<long long> ev;
	for (int i = 0; i < n; ++i) {
		a[i].first = nxtll();
		a[i].second = nxtll();
		mind = min(mind, a[i].second - a[i].first);

		ev.push_back(a[i].first);
		ev.push_back(a[i].second);
	}

	sort(all(ev));
	long long initial = 0;
	long double initial_d = 0;
	for (int i = 0; i < n; ++i) {
		initial += a[i].first;
		initial_d += a[i].first;
	}
	vector<long long> mark(ev.size() + 1);
	int cur = -n;
	auto curr_d = initial_d;
	auto curr = initial;
	mark[0] = (curr_d > 5e18 ? k + 1 : curr);
	long long lst = 0;
	for (int i = 0; i < (int)ev.size(); ++i) {
		curr_d += (long double)(1.0) * (ev[i] - lst) * cur;
		curr += (ev[i] - lst) * cur;
		cur += 1;
		lst = ev[i];
		mark[i + 1] = (curr_d > 5e18 ? k + 1 : curr);
	}

	vector<long long> lucky;
	for (int len = 1; len <= 18; ++len) {
		for (int mask = 0; mask < (1 << len); ++mask) {
			long long num = 0;
			long long cur = 1;
			for (int i = 0; i < len; ++i) {
				if (mask & (1 << i)) {
					num += 3 * cur;
				}
				num += 4 * cur;
				cur *= 10;
			}
			lucky.push_back(num);
		}
	}

	vector<long long> right;
	for (itn i = 0; i < n; ++i) {
		right.push_back(a[i].second);
	}
	sort(all(right));
	vector<long long> sum(n + 1);
	vector<long double> sum_d(n + 1);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + right[i];
		sum_d[i + 1] = sum_d[i] + right[i];
	}

	int ans = 0;
	for (int i = 0; i < (int)lucky.size(); ++i) {
		long long minimal = 0;
		auto x = lucky[i];
		int idx = upper_bound(all(ev), x) - ev.begin();
		if (idx == 0) {
			minimal = (initial_d - 1.0 * x * n > 5e18 ? k + 1 : initial - x * n);
		} else if (idx == 2 * n) {
			if ((long double)mark.back() + 1.0 * (x - ev.back()) * n > 5e18) {
				minimal = k + 1;
			} else {
				minimal = mark.back() + (x - ev.back()) * n;
			}
		} else {
			if (mark[idx] > k && mark[idx + 1] > k){
				minimal = k + 1;
			} else if (mark[idx] <= k && mark[idx + 1] <= k) {
				minimal = mark[idx] + (mark[idx + 1] - mark[idx]) / (ev[idx] - ev[idx - 1]) * (x - ev[idx - 1]);
			} else if (mark[idx] <= k) {
				minimal = ((long double)mark[idx] + 1.0 * (x - ev[idx - 1]) * (idx - 1 - n) > 5e18) ? k + 1 : mark[idx] + (x - ev[idx - 1]) * (idx - 1 - n);
			} else {
				minimal = ((long double)mark[idx + 1] - 1.0 * (ev[idx] - x) * (idx - 1 - n) > 5e18) ? k + 1 : mark[idx] - (ev[idx] - x) * (idx - 1 - n);
			}
		}

		if (minimal > k) {
			continue;
		}

		// cerr << x << ": " << minimal << "\n";

		int l = i, r = upper_bound(all(lucky), x + mind) - lucky.begin();
		int cnt_l = upper_bound(all(right), x) - right.begin();
		while (r > l + 1) {
			int m = (l + r) / 2;
			long long y = lucky[m];
			int cnt_r = upper_bound(all(right), y) - right.begin();
			// cerr << x << " " << y << ": " << cnt_l << " " << cnt_r << "\n";
			long double need = (long double)y * (cnt_r - cnt_l) - sum_d[cnt_r]  + sum_d[cnt_l] + (long double)(y - x) * cnt_l + minimal;
			if (need < 5e18 && y * (cnt_r - cnt_l) - sum_d[cnt_r]  + sum_d[cnt_l] + (y - x) * cnt_l + minimal <= k) {
				l = m;
			} else {
				r = m;
			}
		}
		ans = max(ans, l - i + 1);
	}

	printf("%d\n", ans);

	return 0;
}