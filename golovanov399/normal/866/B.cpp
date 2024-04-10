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
	int n = nxt(), s = nxt();
	vector<pair<int, int>> a(n);
	long long total_s = 0;
	long long total_res = 0;
	for (int i = 0; i < n; ++i) {
		int ss = nxt(), aa = nxt(), bb = nxt();
		total_s += ss;
		total_res += 1ll * aa * ss;
		a[i] = {bb - aa, ss};
	}

	int left = (s - total_s % s) % s;

	// num_of_b % s is in {0} cup [s - left, s)
	// rem % s in [0, left]

	sort(all(a));

	int rem = 0;
	long long ans = total_res;
	while (!a.empty() && a.back().first > 0) {
		if (a.back().second >= rem) {
			a.back().second -= rem;
			total_res += 1ll * a.back().first * rem;
			rem = 0;
		}
		total_res += 1ll * a.back().first * (a.back().second / s) * s;
		a.back().second %= s;

		if (rem <= left) {
			ans = max(ans, total_res);
		}

		if (a.back().second > rem) {
			rem += s;
		}
		total_res += 1ll * a.back().first * a.back().second;
		rem -= a.back().second;

		if (rem <= left) {
			ans = max(ans, total_res);
		}

		a.pop_back();
	}
	while (rem > left) {
		int tmp = min(rem - left, a.back().second);
		total_res += 1ll * a.back().first * tmp;
		a.pop_back();
		rem -= tmp;
	}

	if (rem <= left) {
		ans = max(ans, total_res);
	}
	cout << ans << "\n";

	return 0;
}