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

const int dg[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};

const int N = 2222;
int dp[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char c : s) {
			a[i] = a[i] * 2 + (c - '0');
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[n - 1 - i];
		for (int d = 0; d <= 9; ++d) {
			if ((x & dg[d]) != x) {
				continue;
			}
			int c = __builtin_popcount(dg[d] ^ x);
			for (int j = 0; j + c <= k; ++j) {
				if (dp[i][j] != -1) {
					dp[i + 1][j + c] = d;
				}
			}
		}
	}

	if (dp[n][k] == -1) {
		cout << "-1\n";
		return 0;
	}
	for (int i = n; i > 0; --i) {
		cout << dp[i][k];
		k -= __builtin_popcount(dg[dp[i][k]] ^ a[n - i]);
	}
	cout << "\n";

	return 0;
}