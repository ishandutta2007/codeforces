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

const int L = 21;
const int N = 1 << L;

struct Max2 {
	int x, y;

	Max2(): x(-1), y(-1) {}

	void refresh(int z) {
		if (z > x) {
			y = x;
			x = z;
		} else if (z > y) {
			y = z;
		}
	}

	void refresh(const Max2& ot) {
		refresh(ot.x);
		refresh(ot.y);
	}
};

Max2 d[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int i = n - 1; i >= 0; --i) {
		d[a[i]].refresh(i);
	}
	for (int j = 0; j < L; ++j) {
		for (int i = N - 1; i >= 0; --i) {
			if (!(i & (1 << j))) {
				d[i].refresh(d[i | (1 << j)]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		int x = 0;
		for (int j = L - 1; j >= 0; --j) {
			if (a[i] & (1 << j)) {
				continue;
			}
			if (d[x | (1 << j)].y > i) {
				x |= 1 << j;
			}
		}
		ans = max(ans, a[i] | x);
	}

	cout << ans << "\n";

	return 0;
}