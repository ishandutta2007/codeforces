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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n = nxt();
	string s, t;
	cin >> s >> t;
	vector<int> a(20, 0);
	for (int i = 0; i < n; ++i) {
		if (t[i] < s[i]) {
			cout << "-1\n";
			return;
		}
		if (s[i] < t[i]) {
			a[s[i] - 'a'] |= 1 << (t[i] - 'a');
		}
	}
	for (int i = 0; i < 20; ++i) {
		int x = a[i];
		if (!x) {
			continue;
		}
		a[i] = 1 << __builtin_ctz(x);
		int y = __builtin_ctz(x);
		x ^= a[i];
		while (x) {
			a[y] |= 1 << __builtin_ctz(x);
			y = __builtin_ctz(x);
			x ^= 1 << y;
		}
	}
	int ans = 0;
	for (int i = 0; i < 20; ++i) {
		ans += !!a[i];
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}