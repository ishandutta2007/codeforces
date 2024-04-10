#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	int a[2], b[2], c[2];
	for (int i = 0; i < 2; ++i) {
		b[i] = nxt();
	}
	for (int i = 0; i < 2; ++i) {
		a[i] = nxt();
	}
	for (int i = 0; i < 2; ++i) {
		c[i] = nxt();
	}

	for (int i = 0; i < 2; ++i) {
		if ((a[i] > b[i]) != (c[i] > b[i])) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}