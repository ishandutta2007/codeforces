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

	int r = nxt(), c = nxt();
	if (r == 1 && c == 1) {
		puts("0");
		return 0;
	}
	vector<int> a(r), b(c);
	for (int i = 0; i < r; ++i) {
		a[i] = i + 1;
	}
	for (int j = 0; j < c; ++j) {
		b[j] = r + j + 1;
	}
	if (c == 1) {
		for (int j = 0; j < c; ++j) {
			b[j] = j + 1;
		}
		for (int i = 0; i < r; ++i) {
			a[i] = c + i + 1;
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%d ", lcm(a[i], b[j]));
		}
		printf("\n");
	}

	return 0;
}