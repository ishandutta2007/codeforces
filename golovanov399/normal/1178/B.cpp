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

	cin.sync_with_stdio(0);
	string s;
	cin >> s;
	long long ans = 0;
	int cnt_ri = 0, cnt_le = 0;
	for (int i = 1; i + 1 < (int)s.length(); ++i) {
		if (s[i] == 'v' && s[i + 1] == 'v') {
			++cnt_ri;
		}
	}
	int n = s.length();
	for (int i = 1; i < n - 1; ++i) {
		if (s[i] == 'v' && s[i + 1] == 'v') {
			--cnt_ri;
		}
		if (s[i] == 'o') {
			ans += 1ll * cnt_le * cnt_ri;
		}
		if (s[i - 1] == 'v' && s[i] == 'v') {
			++cnt_le;
		}
	}
	cout << ans << "\n";

	return 0;
}