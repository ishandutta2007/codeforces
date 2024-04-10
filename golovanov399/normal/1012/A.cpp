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
	vector<int> a(2 * n);
	for (int& x : a) {
		x = nxt();
	}
	sort(all(a));
	long long ans = 1ll * (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	for (int i = 1; i < n; ++i) {
		ans = min(ans, 1ll * (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
	}
	cout << ans << "\n";

	return 0;
}