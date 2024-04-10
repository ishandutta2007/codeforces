#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <double, int> pii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

int pw[20];
int S = 15, T = 18, F = 16, E = 17;
double dp[20][30];

int count(int mask) {
	int res = 0;
	while (mask) {
		res += mask % 3;
		mask /= 3;
	}
	return res;
}

double cap(double a, double b, double c, double d) {
	return max(min(b, d) - max(a, c), 0.0);
}

void chmax(double &a, double b) {
	a = max(a, b);
}

int main () {
	pw[0] = 1;
	for (int i = 1; i <= 15; i++) {
		pw[i] = pw[i - 1] * 3;
	}
	int nf, ne, ns; double rf, re, rs; int df, de;
	cin >> nf >> ne >> ns >> rf >> re >> rs >> df >> de;
	rf = sqrt(rf * rf - 1), re = sqrt(re * re - 1), rs = sqrt(rs * rs - 1);
	int n = nf + ne + ns, m = (n + 1) >> 1;
	double ans = 0;
	for (int mask = 0; mask < pw[m]; mask++) {
		if (count(mask) != ns) continue;
		if (mask % 3 > ((n & 1) ? 1 : 2)) continue;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= nf; j++) {
				dp[i][j] = -1e18;
			}
		}
		dp[0][nf] = 0;
		int sum = 0;
		for (int i = 0; i < m; i++) {
			double sf = 2 * rf, se = 2 * re;
			for (int j = 0; j < m; j++) {
				int x = mask / pw[j] % 3;
				sf += x * cap(i - rf, i + rf, j - rs, j + rs);
				se += x * cap(i - re, i + re, j - rs, j + rs);
			}
			sf *= df, se *= de;
			int x = ((n & 1) && !i ? 1 : 2) - mask / pw[i] % 3;
			for (int j = 0; j <= nf; j++) {
				if (dp[i][j] < -1e10) continue;
				int k = ne - (sum - (nf - j));
				if (x <= k) chmax(dp[i + 1][j], dp[i][j] + x * se);
				if (x >= 1 && 1 <= j && x - 1 <= k) chmax(dp[i + 1][j - 1], dp[i][j] + sf + (x - 1) * se);
				if (x == 2 && 2 <= j) chmax(dp[i + 1][j - 2], dp[i][j] + 2 * sf);
			}
			sum += x; 
		}
		ans = max(ans, dp[m][0]);
	}
	printf("%.8f\n", ans);
	return 0;
}