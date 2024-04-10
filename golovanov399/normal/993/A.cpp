#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int qw(int x, int y, int* ar) {
	int q = 0;
	for (int i = 0; i < 4; ++i) {
		int j = (i + 1) % 4;
		q += abs((ar[2 * i] - x) * (ar[2 * j + 1] - y) - (ar[2 * i + 1] - y) * (ar[2 * j] - x));
	}
	return q;
}

bool isInside(int x, int y, int* ar) {
	return qw(x, y, ar) == qw(ar[0], ar[1], ar);
}

int main() {
	int a[2][8];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 8; ++j) {
			a[i][j] = nxt() * 2;
		}
	}

	for (int i = -300; i <= 300; ++i) {
		for (int j = -300; j <= 300; ++j) {
			if (isInside(i, j, a[0]) && isInside(i, j, a[1])) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";

	return 0;
}