#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	long long s = accumulate(all(a), 0ll);
	if (s == 1) {
		puts("-1");
		return 0;
	}

	vector<long long> divs;
	auto ss = s;
	for (long long d = 2; d * d <= s; ++d) {
		if (s % d == 0) {
			divs.push_back(d);
			while (s % d == 0) {
				s /= d;
			}
		}
	}
	if (s > 1) {
		divs.push_back(s);
	}
	s = ss;

	long long ans = s * n;
	for (auto d : divs) {
		if (d == 1) {
			continue;
		}

		vector<long long> rems(n);
		for (int i = 0; i < n; ++i) {
			rems[i] = a[i] % d;
		}
		long long cur = 0;
		long long h = 0;
		for (int i = 0; i < n - 1; ++i) {
			h += rems[i];
			if (h >= d) {
				h -= d;
			}
			cur += min(h, d - h);
		}
		ans = min(ans, cur);
	}

	cout << ans << "\n";

	return 0;
}