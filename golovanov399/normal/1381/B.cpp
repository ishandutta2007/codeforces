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

using Bs = bitset<2222>;

void solve() {
	int n = nxt();
	vector<int> a(2 * n);
	generate(all(a), nxt);
	vector<int> cnts;
	int cur = 0;
	for (int x : a) {
		if (x > cur) {
			cur = x;
			cnts.push_back(1);
		} else {
			cnts.back() += 1;
		}
	}
	Bs can = {0};
	can[0] = 1;
	for (int x : cnts) {
		can |= can << x;
	}
	puts(can[n] ? "YES" : "NO");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}