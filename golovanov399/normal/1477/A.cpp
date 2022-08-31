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

void solve() {
	int n = nxt();
	long long k;
	scanf("%lld", &k);
	vector<long long> a(n);
	for (auto& x : a) {
		scanf("%lld", &x);
	}
	long long g = 0;
	sort(all(a));
	for (int i = 1; i < n; ++i) {
		g = gcd(g, a[i] - a[0]);
	}
	puts(abs(k - a[0]) % g ? "NO" : "YES");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}