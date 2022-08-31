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

bool isWonderful(int d) {
	int l = __builtin_ctz(d);
	return d == ((2 << l) - 1) << l;
}

int main() {
	int n = nxt();
	int d = 1;
	for (int i = 2; i <= n; ++i) {
		if (n % i || !isWonderful(i)) {
			continue;
		}
		d = i;
	}
	printf("%d\n", d);

	return 0;
}