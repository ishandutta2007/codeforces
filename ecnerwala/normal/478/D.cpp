#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[int(5e5)];

int main() {
	int R, G; cin >> R >> G;
	int H = 0;
	dp[0] = 1;
	for(int h = 1; H + h <= R + G; h++) {
		H += h;
		for(int i = H; i >= h; i--) {
			dp[i] += dp[i - h];
			if(dp[i] >= MOD) dp[i] -= MOD;
		}
	}

	int res = 0;
	assert(H - G <= R);
	for(int i = H - G; i <= R; i++) {
if(i < 0 || i > H) continue;
		res += dp[i];
		if(res >= MOD) res -= MOD;
	}
	cout << res << '\n';
	return 0;
}