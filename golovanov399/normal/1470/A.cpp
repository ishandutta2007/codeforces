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
	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (auto& x : a) {
		x = nxt() - 1;
	}
	vector<int> c(m);
	generate(all(c), nxt);
	long long ans = 0;
	sort(all(a));
	reverse(all(a));
	for (int i = 0, j = 0; i < n; ++i) {
		if (j <= a[i]) {
			ans += c[j++];
		} else {
			ans += c[a[i]];
		}
	}
	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}