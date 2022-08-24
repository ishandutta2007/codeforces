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

int mod(int x, int y) {
	return ((x % y) + y) % y;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	if (n == 1) {
		cout << "1 1\n" << -a[0] << "\n1 1\n1\n1 1\n-1\n";
		return 0;
	}

	cout << "1 1\n" << -a[0] << "\n";
	cout << 2 << " " << n << "\n";
	for (int i = 1; i < n; ++i) {
		cout << 1ll * mod(a[i], n) * (n - 1) << " ";
	}
	cout << "\n" << 1 << " " << n << "\n0 ";
	for (int i = 1; i < n; ++i) {
		cout << -(a[i] + 1ll * mod(a[i], n) * (n - 1)) << " ";
	}
	cout << "\n";

	return 0;
}