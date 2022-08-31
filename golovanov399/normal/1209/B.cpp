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

	int n = nxt();
	string s;
	cin >> s;
	vector<int> st(n);
	for (int i = 0; i < n; ++i) {
		st[i] = (s[i] == '1');
	}
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt(), a[i].second = nxt();
	}

	int ans = accumulate(all(st), 0);
	for (int i = 1; i < 150; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i >= a[j].second && i % a[j].first == a[j].second % a[j].first) {
				st[j] ^= 1;
			}
		}
		ans = max(ans, accumulate(all(st), 0));
	}
	printf("%d\n", ans);

	return 0;
}