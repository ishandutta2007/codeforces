#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

double dp[400][1000];
double numZero[400][1000];

double slow(int x, int K, double p) {
	if(K == 0) {
		int res = 0;
		while(x % 2 == 0) {
			x /= 2;
			res++;
		}
		return res;
	}
	return p * slow(x * 2, K - 1, p) + (1 - p) * slow(x + 1, K - 1, p);
}

double go(int x, int K, double p) {
	for(int k = 0; k <= K; k++) {
		for(int m = 0; m < (1 << 9); m++) {
			dp[k][m] = 0;
			numZero[k][m] = 0;
		}
	}

	dp[0][x & ((1 << 9) - 1)] = 1;
	int v = x >> 8;
	if(v % 2) v++;
	if(v) {
		while(v && v % 2 == 0) {
			numZero[0][x & ((1 << 9) - 1)]++;
			v /= 2;
		}
	}

	for(int k = 0; k < K; k++) {
		for(int m = 0; m < (1 << 9); m++) {
			//prob p
			double prob = dp[k][m] * p;
			int nm = (m << 1) & ((1 << 9) - 1);
			dp[k + 1][nm] += prob;
			if(bool(m & (1 << 8)) == bool(m & (1 << 7))) {
				numZero[k + 1][nm] += (numZero[k][m] * p) + 1 * prob;
			} else {
				numZero[k + 1][nm] += 1 * prob;
			}
			prob = dp[k][m] * (1 - p);
			nm = (m + 1) & ((1 << 9) - 1);
			dp[k + 1][nm] += prob;
			numZero[k + 1][nm] += numZero[k][m] * (1 - p);
		}
	}

	double res = 0;
	for(int m = 0; m < (1 << 9); m++) {
		if(m == 0) {
			res += numZero[K][0] + 8 * dp[K][m];
		} else {
			int cnt = 0;
			for(int v = m; v % 2 == 0; v /= 2) {
				cnt++;
			}
			res += cnt * dp[K][m];
		}
		//if(cnt && dp[K][m] > 0) cerr << m << ' ' << cnt << ' ' << dp[K][m] << '\n';
	}
	return res;
}

int main() {
	//we have to store last 8 digits, as well as (number of zeroes in (first bunch) & (first bunch + 1))
	//state: number of steps, last 9 digits, number of zeroes
	
	int x, K;
	double p;
	cin >> x >> K >> p;
	p /= 100;

	double res = go(x, K, p);
	cout << fixed << setprecision(20);
	cout << res << '\n';

	//cerr << fixed << setprecision(20) << slow(x, K, p) << '\n';
	return 0;
}