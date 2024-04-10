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
	vector<int> a(n);
	generate(all(a), nxt);
	puts(a[0] < a[n - 1] ? "YES" : "NO");
}

vector<int> rem(vector<int> a, int i) {
	int x = a[i];
	a.erase(a.begin() + i);
	for (auto& y : a) {
		y -= y > x;
	}
	return a;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	// set<vector<int>> good;
	// good.insert({0});
	// for (int n = 2; n <= 5; ++n) {
	// 	vector<int> perm(n);
	// 	iota(all(perm), 0);
	// 	do {
	// 		bool ok = false;
	// 		for (int i = 0; i < n - 1; ++i) {
	// 			if (perm[i] < perm[i + 1] && (good.count(rem(perm, i)) || good.count(rem(perm, i + 1)))) {
	// 				ok = true;
	// 				break;
	// 			}
	// 		}
	// 		if (ok) {
	// 			good.insert(perm);
	// 			for (int x : perm) {
	// 				cerr << x + 1 << " ";
	// 			}
	// 			cerr << "\n";
	// 		}
	// 	} while (next_permutation(all(perm)));
	// }

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}