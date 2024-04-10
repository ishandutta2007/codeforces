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
	int n = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	set<int> S(all(a));
	int cnt = S.size();
	if (cnt == 1) {
		cout << "1\n";
	} else if (k == 1) {
		cout << "-1\n";
	} else {
		cout << (cnt - 1 + (k - 1) - 1) / (k - 1) << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}