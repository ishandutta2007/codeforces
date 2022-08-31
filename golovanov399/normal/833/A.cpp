#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

vector<long long> v;

bool conts(long long x) {
	auto it = lower_bound(all(v), x);
	return (it != v.end()) && (*it == x);
}

void solve() {
	int x = nxt(), y = nxt();
	int g = __gcd(x, y);
	if (g % (x / g) || g % (y / g)) {
		puts("No");
		return;
	}
	puts(conts(1ll * x * y) ? "Yes" : "No");
}

int main() {
	for (int i = 1; i <= 1111111; ++i) {
		v.push_back(1ll * i * i * i);
	}

	int n = nxt();
	while (n--) {
		solve();
	}

	return 0;
}