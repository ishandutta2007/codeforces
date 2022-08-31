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
	vector<int> ok(200, 0);
	int m = n;
	while (n--) {
		int k = nxt();
		while (k--) {
			ok[nxt()] += 1;
		}
	}
	for (int i = 0; i < 200; ++i) {
		if (ok[i] == m) {
			cout << i << " ";
		}
	}
	cout << "\n";

	return 0;
}