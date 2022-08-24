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
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	int bal = 0;
	for (char c : s) {
		bool ltz = (bal < 0);
		if (c == '(') {
			++bal;
		} else {
			--bal;
		}
		ltz |= bal < 0;
		if (ltz) {
			++ans;
		}
	}
	if (bal != 0) {
		ans = -1;
	}
	cout << ans << "\n";

	return 0;
}