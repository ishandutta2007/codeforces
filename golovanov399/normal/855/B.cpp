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

int main() {
	int n = nxt();
	int p = nxt(), q = nxt(), r = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> opt(n + 1);
	opt[n] = (r > 0 ? INT_MIN : INT_MAX);
	for (int i = n - 1; i >= 0; --i) {
		opt[i] = (r > 0) ? max(opt[i + 1], a[i]) : min(opt[i + 1], a[i]);
	}

	long long ans = LLONG_MIN;
	int cur_opt = (p > 0 ? INT_MIN : INT_MAX);
	for (int i = 0; i < n; ++i) {
		cur_opt = (p > 0) ? max(cur_opt, a[i]) : min(cur_opt, a[i]);
		ans = max(ans, 1ll * p * cur_opt + 1ll * q * a[i] + 1ll * r * opt[i]);
	}

	cout << ans << "\n";

	return 0;
}