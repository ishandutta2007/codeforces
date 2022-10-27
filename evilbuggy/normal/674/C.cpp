#include <bits/stdc++.h>
using namespace std;

const int K = 55;
const int N = 200005;
double t[N], s[N], f[N], g[N], dp[K][N];

inline double cost(int l, int r){
	return g[r] - g[l - 1] - s[l - 1]*(f[r] - f[l - 1]);
}

void compute(int k, int l, int r, int optL, int optR){
	if(l > r)return;
	int m = (l + r)/2;
	double ans = 1e18, optM = optL;
	for(int i = optL; i <= m && i <= optR; i++){
		double val = dp[k - 1][i - 1] + cost(i, m);
		if(val < ans){
			ans = val;
			optM = i;
		}
	}
	dp[k][m] = ans;
	compute(k, l, m - 1, optL, optM);
	compute(k, m + 1, r, optM, optR);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	s[0] = f[0] = g[0] = 0.0;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		s[i] = s[i - 1] + t[i];
		f[i] = f[i - 1] + 1.0/t[i];
		g[i] = g[i - 1] + s[i]/t[i];
	}
	dp[1][0] = 0.0;
	for(int i = 1; i <= n; i++){
		dp[1][i] = cost(1, i);
	}
	for(int i = 2; i <= k; i++){
		dp[i][0] = 0.0;
		compute(i, 1, n, 1, n);
	}
	cout << setprecision(30) << dp[k][n] << '\n';

	return 0;
}