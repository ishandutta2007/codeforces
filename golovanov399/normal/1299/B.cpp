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

void panic() {
	puts("NO");
	exit(0);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
	}

	if (n % 2) {
		panic();
	}

	int x = a[0].first + a[n / 2].first;
	int y = a[0].second + a[n / 2].second;
	for (int i = 0; i < n / 2; ++i) {
		if (a[i].first + a[i + n / 2].first != x || a[i].second + a[i + n / 2].second != y) {
			panic();
		}
	}
	puts("YES");

	return 0;
}