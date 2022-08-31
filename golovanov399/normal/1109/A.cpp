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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	map<int, int> M[2];
	M[1][0] = 1;
	long long ans = 0;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		cur ^= a[i];
		ans += M[i % 2][cur];
		M[i % 2][cur] += 1;
	}
	cout << ans << "\n";

	return 0;
}