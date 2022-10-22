#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int dp[32][20][20][20][20][2][2];
int n, m;
int a[10], b[10];
int X1[1 << 5], X2[1 << 5], Y1[1 << 5], Y2[1 << 5];

int dfs(int now, int x1, int x2, int y1, int y2, int px, int py) {
	if (now == 30) return x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0 && !px && !py;
	int &res = dp[now][x1][x2][y1][y2][px][py];
	if (~res) return res;
	res = 0;
	int val = m >> now & 1;
	for (int mask = 0; mask < (1 << n); mask++) {
		int nx1 = x1 + X1[mask], nx2 = x2 + X2[mask], ny1 = y1 + Y1[mask], ny2 = y2 + Y2[mask];
		if ((nx1 & 1) != (nx2 & 1) || (ny1 & 1) != (ny2 & 1)) continue;
		int pp = (nx1 & 1) == val ? px : (nx1 & 1) > val, qq = (ny1 & 1) == val ? py : (ny1 & 1) > val;
		ADD(res, dfs(now + 1, nx1 >> 1, nx2 >> 1, ny1 >> 1, ny2 >> 1, pp, qq));
	}
	return res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) {
				if (a[i] > 0) X1[mask] += a[i];
				else X2[mask] -= a[i];
				if (b[i] > 0) Y1[mask] += b[i];
				else Y2[mask] -= b[i];
			}
		}
	}
	cout << (dfs(0, 0, 0, 0, 0, 0, 0) - 1 + mod) % mod << endl;
	return 0;
}