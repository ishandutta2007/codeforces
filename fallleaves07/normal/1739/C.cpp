#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

void solve() {
	int n;
	cin >> n;
	static int c[66][66];
	c[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
		}
	}
	auto C = [&](int n, int m) {
		if (n < 0 || m < 0 || n - m < 0) {
			return 0;
		}
		return c[n][m];
	};
	int win = 0, lose = 0;
	for (int i = 0; i <= n - 2; i += 2) {
		swap(win, lose);
		win = (win + 0ll + C(i, i / 2) + C(i, i / 2 - 1)) % M;
		lose = (lose + C(i, i / 2 + 1)) % M;
	}
	printf("%d %d 1\n", win, lose);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}