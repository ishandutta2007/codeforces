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
	long long k;
	scanf("%lld", &k);
	vector<int> a(n);
	generate(all(a), nxt);
	k -= 1;
	int mx = *max_element(all(a));
	for (auto& x : a) {
		x = mx - x;
	}
	k %= 2;
	while (k--) {
		int mx = *max_element(all(a));
		for (auto& x : a) {
			x = mx - x;
		}
	}
	for (auto x : a) {
		printf("%d ", x);
	}
	printf("\n");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}