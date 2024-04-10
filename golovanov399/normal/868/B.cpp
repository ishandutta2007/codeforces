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

int main() {
	double h = nxt() % 12 * 5, m = nxt(), s = nxt(), t1 = nxt() % 12 * 5, t2 = nxt() % 12 * 5;
	m += s / 60;
	h += m / 60;

	if (t1 > t2) {
		swap(t1, t2);
	}

	bool up = true, down = true;
	double a[3] = {h, m, s};
	for (int i = 0; i < 3; ++i) {
		if (a[i] > t1 && a[i] < t2) {
			up = false;
		}
		if (a[i] < t1 || a[i] > t2) {
			down = false;
		}
	}

	puts((up || down) ? "YES" : "NO");

	return 0;
}