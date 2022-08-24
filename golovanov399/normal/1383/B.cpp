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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	for (int l = 30; l >= 0; --l) {
		int cnt[2] = {0, 0};
		for (int x : a) {
			cnt[(x >> l) & 1] += 1;
		}
		if (cnt[1] % 2 == 0) {
			continue;
		}
		if (cnt[1] % 4 == 3 && cnt[0] % 2 == 0) {
			cout << "LOSE\n";
		} else {
			cout << "WIN\n";
		}
		return;
	}
	cout << "DRAW\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}