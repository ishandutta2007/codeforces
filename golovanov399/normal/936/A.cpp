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
	long long k, d, t;
	cin >> k >> d >> t;

	long long s = k;
	if (s % d) {
		s = s - s % d + d;
	}

	long long one_t = s + k;
	t *= 2;

	long long ans = t / one_t * s;
	t %= one_t;

	long long frac = 0;

	if (t <= 2 * k) {
		ans += t / 2;
		frac = t % 2;
	} else {
		ans += k;
		t -= 2 * k;
		ans += t;
	}

	cout << ans << "." << frac * 5 << "\n";

	return 0;
}