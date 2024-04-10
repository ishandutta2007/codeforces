#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

#define int long long

int32_t main() {
	int n = nxt(), d = nxt(), need = nxt();
	vector<itn> a(n);
	for (itn i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int left_cnt = (n + 1) / 2;
	int right_cnt = n / 2;

	vector<int> moment(n);
	for (int i = 0; i < n; ++i) {
		moment[i] = min(i, n - 1 - i) + 1;
	}

	auto check = [&](int left, int right) {
		right = n - right;
		// cerr << "\n" << left << ", " << right << "\n";

		auto b = a;
		int idx = 0;
		for (int i = left; i < right; ++i) {
			long long l = i - moment[i] * d;
			long long r = i + moment[i] * d + 1;
			// cerr << l << ", " << r << "; ";

			while (idx < l) {
				++idx;
			}

			int cur = 0;
			while (cur < need && idx < r && idx < n) {
				int x = min(b[idx], need - cur);
				// cerr << i << ", " << idx << ", " << cur << ", " << x << "\n";
				cur += x;
				b[idx] -= x;
				if (b[idx] == 0) {
					++idx;
				}
			}

			if (cur < need) {
				// cerr << "\n";
				return false;
			}
		}
		// cerr << "\n";
		return true;
	};

	int l = -1, r = left_cnt;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (check(min(m, left_cnt), min(m, right_cnt))) {
			r = m;
		} else {
			l = m;
		}
	}

	cout << r << "\n";

	return 0;
}