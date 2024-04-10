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
	int k = nxt() + nxt();	// fuck ub
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i] -= nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i] = abs(a[i]);
	}

	while (k--) {
		auto it = max_element(all(a));
		if (*it) {
			--*it;
		} else {
			++*it;
		}
	}

	long long ans = 0;
	for (int x : a) {
		ans += 1ll * x * x;
	}
	cout << ans << "\n";

	return 0;
}