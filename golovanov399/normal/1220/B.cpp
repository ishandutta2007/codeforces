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

long long isqrt(long long x) {
	long long y = sqrtl(x);
	while ((y + 1) * (y + 1) <= x) {
		++y;
	}
	return y;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<vector<long long>> a(n, vector<long long>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = nxt();
		}
	}
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		int k = (i + 2) % n;
		cout << isqrt(a[i][j] * a[i][k] / a[j][k]) << " ";
	}
	cout << "\n";

	return 0;
}