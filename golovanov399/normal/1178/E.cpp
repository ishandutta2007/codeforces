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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int l = 0, r = (int)s.length() - 1;
	string left;
	while (r - l + 1 >= 6) {
		int x = -1, y = -1;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (i + j <= 2 && s[l + i] == s[r - j]) {
					x = i, y = j;
				}
			}
		}
		assert(x > -1);
		left += s[l + x];
		l += x + 1;
		r -= y + 1;
	}

	string ans = left;
	s = s.substr(l, r - l + 1);
	int n = s.length();
	for (int mask = 1; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) < n / 2) {
			continue;
		}
		string t;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				t += s[i];
			}
		}
		string u = t;
		reverse(all(u));
		if (u == t) {
			ans += t;
			break;
		}
	}
	reverse(all(left));
	ans += left;

	cout << ans << "\n";

	return 0;
}