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
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (s[i] != t[i]);
	}

	int ans = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			if (cnt == 0) {
				cnt += 1;
			} else if (s[i] != s[i - 1]) {
				cnt += 1;
			} else {
				ans += cnt / 2;
				cnt = 1;
			}
		} else {
			ans += cnt / 2;
			cnt = 0;
		}
	}

	ans += cnt / 2;

	cout << accumulate(all(a), 0) - ans << "\n";

	return 0;
}