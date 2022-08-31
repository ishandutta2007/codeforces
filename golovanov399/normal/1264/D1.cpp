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

const int N = 2222;
const int mod = 998244353;
long long dp_l[N][N], dp_r[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;
	int n = s.length();
	dp_l[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] != ')') {
			for (int j = 0; j <= i; ++j) {
				dp_l[i + 1][j + 1] += dp_l[i][j];
			}
		}
		if (s[i] != '(') {
			for (int j = 0; j <= i; ++j) {
				dp_l[i + 1][j] += dp_l[i][j];
			}
		}
		for (int j = 0; j <= i; ++j) {
			if (dp_l[i + 1][j] >= mod) {
				dp_l[i + 1][j] -= mod;
			}
		}
	}
	dp_r[n][0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] != '(') {
			for (int j = 0; j <= n - i; ++j) {
				dp_r[i][j + 1] += dp_r[i + 1][j];
			}
		}
		if (s[i] != ')') {
			for (int j = 0; j <= n - i; ++j) {
				dp_r[i][j] += dp_r[i + 1][j];
			}
		}
		for (int j = 0; j <= n - i; ++j) {
			if (dp_r[i][j] >= mod) {
				dp_r[i][j] -= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int d = 0; d <= n; ++d) {
			ans += 1ll * d * dp_l[i][d] % mod * dp_r[i][d] % mod;
		}
	}

	cout << ans % mod << "\n";

	return 0;
}