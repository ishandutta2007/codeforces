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

const int mod = 998244353;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(), k = nxt();
	vector<int> c = {1};
	for (int i = 1; i < n; ++i) {
		vector<int> d(i + 1);
		d[0] = d[i] = 1;
		for (int j = 1; j < i; ++j) {
			d[j] = (c[j] + c[j - 1]) % mod;
		}
		c.swap(d);
	}
	long long ans = c[k];
	for (int i = 0; i < k; ++i) {
		ans = ans * (m - 1) % mod;
	}
	ans = ans * m % mod;
	cout << ans << "\n";

	return 0;
}