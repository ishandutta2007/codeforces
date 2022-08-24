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
	vector<int> a;
	int last = -1;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		if (x != last) {
			a.push_back(0);
			last = x;
		}
		++a.back();
	}
	int g = a[0];
	int i = 1;
	int s = 0, b = 0;
	while (i < (int)a.size() && s <= g) {
		s += a[i++];
	}
	while (i < (int)a.size() && b <= g) {
		b += a[i++];
	}
	while (i < (int)a.size() && (g + s + b + a[i]) * 2 <= n) {
		b += a[i++];
	}
	if (g < s && g < b && (g + s + b) * 2 <= n) {
		printf("%d %d %d\n", g, s, b);
	} else {
		printf("0 0 0\n");
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}