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

	int n = nxt(), m = nxt();
	int x = 1, y = 1;
	for (int i = 0; i < n * m / 2; ++i) {
		cout << x << " " << y << "\n";
		cout << n + 1 - x << " " << m + 1 - y << "\n";
		++y;
		if (y > m) {
			y = 1;
			++x;
		}
	}
	if (n * m % 2) {
		cout << x << " " << y << "\n";
	}

	return 0;
}