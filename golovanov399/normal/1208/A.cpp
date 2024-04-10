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

int f(int x, int y, int n) {
	int xx = x, yy = y;
	vector<int> ans = {};
	do {
		ans.push_back(x);
		x ^= y;
		swap(x, y);
	} while (x != xx || y != yy);
	return ans[n % (int)ans.size()];
}

void solve() {
	int a = nxt(), b = nxt(), n = nxt();
	int c = 0;
	for (int i = 0; i < 30; ++i) {
		int x = (a >> i) & 1;
		int y = (b >> i) & 1;
		c |= f(x, y, n) << i;
	}
	cout << c << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}