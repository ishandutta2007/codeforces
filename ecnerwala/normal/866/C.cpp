#include<bits/stdc++.h>
using namespace std;

const double INF = 1e9;

const int MAXN = 60;
const int MAXR = 10000;
int N;
int R;
struct level {
	int F, S;
	double P;
} L[MAXN];

double dp[MAXN][MAXR]; // time left

double go(double guess) {
	for (int i = 0; i <= R; i++) {
		dp[N][i] = 0;
	}
	for (int i = N-1; i >= 0; i--) {
		for (int t = 0; t <= R; t++) {
			if (t < L[i].F) {
				dp[i][t] = INF;
			} else {
				// play it
				dp[i][t] =
					L[i].P * (L[i].F + dp[i+1][t-L[i].F]) +
					(1-L[i].P) * (L[i].S + (L[i].S <= t ? dp[i+1][t - L[i].S] : guess));
			}
			if (i > 0) dp[i][t] = min(dp[i][t], guess);
		}
	}
	return dp[0][R];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> L[i].F >> L[i].S >> L[i].P;
		L[i].P /= 100;
	}
	double mi = 0, ma = INF;
	for (int z = 0; z < 200; z++) {
		double md = (mi + ma) / 2;
		double res = go(md);
		if (res > md) {
			mi = md;
		} else {
			ma = md;
		}
	}
	cout << fixed << setprecision(10) << mi << '\n';
	return 0;
}