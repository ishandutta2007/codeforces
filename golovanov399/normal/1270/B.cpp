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
	vector<int> a(nxt());
	generate(all(a), nxt);
	for (int i = 0; i < (int)a.size() - 1; ++i) {
		if (abs(a[i] - a[i + 1]) > 1) {
			puts("YES");
			printf("%d %d\n", i + 1, i + 2);
			return;
		}
	}
	puts("NO");
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}