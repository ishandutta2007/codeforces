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
	int t = nxt();
	while (t--) {
		long long p, q, b;
		scanf("%lld%lld%lld", &p, &q, &b);
		if (p == 0) {
			puts("Finite");
			continue;
		}
		q /= gcd(p, q);
		while (gcd(q, b) > 1) {
			long long d = gcd(q, b);
			while (q % d == 0) {
				q /= d;
			}
		}
		puts(q > 1 ? "Infinite" : "Finite");
	}

	return 0;
}