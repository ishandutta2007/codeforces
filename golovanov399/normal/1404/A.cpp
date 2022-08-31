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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int get(char c) {
	return c == '?' ? 2 : c == '1';
}

void solve() {
	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	int cnt[2] = {0, 0};
	for (int i = 0; i < k; ++i) {
		int mask = 0;
		for (int j = i; j < n; j += k) {
			mask |= 1 << get(s[j]);
		}
		if ((mask & 3) == 3) {
			puts("No");
			return;
		}
		if (mask & 3) {
			cnt[__builtin_ctz(mask)] += 1;
		}
	}
	puts(cnt[0] <= k / 2 && cnt[1] <= k / 2 ? "Yes" : "No");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}