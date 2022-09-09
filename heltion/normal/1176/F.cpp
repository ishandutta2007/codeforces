//Author: Heltion
//Date: 2019-06-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
LL ss[maxn][8];
LL c[maxn], d[maxn];
LL dps[2][4][4];
LL dp[maxn][10];
void solve(int p){
	int k;
	cin >> k;
	for(int r = 1; ~r; r -= 1)
		for(int s = 3; ~s; s -= 1)
			for(int t = 3; ~t; t -= 1) dps[r][s][t] = -1e18;
	dps[0][0][0] = 0;
	for(int i = 1; i <= k; i += 1){
		LL c, d;
		cin >> c >> d;
		for(int r = 1; ~r; r -= 1)
			for(int s = 3; s; s -= 1)
				for(int t = 3; t; t -= 1)
					if(t >= c) {
						dps[r][s][t] = max(dps[r][s][t], dps[r][s - 1][t - c] + d);
						if(r) dps[r][s][t] = max(dps[r][s][t], dps[r - 1][s - 1][t - c] + d * 2);
					}
	}
	for(int i = 1; i <= 3; i += 1) 
		for(int t = 1; t <= 3; t += 1)
			ss[p][i] = max(ss[p][i], dps[0][i][t]);
	for(int i = 5; i <= 7; i += 1) 
		for(int t = 1; t <= 3; t += 1)
			ss[p][i] = max(ss[p][i], dps[1][i - 4][t]);
	//cout << p << ":\n";
	//for(int i = 0; i < 8; i += 1) cout << ss[p][i] << " ";
	//cout << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) solve(i);
	for(int i = 0; i <= n; i += 1)
		for(int j = 0; j < 10; j += 1)
			dp[i][j] = -1e18;
	dp[0][0] = 0;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < 10; j += 1){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			for(int r = 1; r <= 3; r += 1)if(ss[i + 1][r]){
				if(j + r >= 10) 
					dp[i + 1][j + r - 10] = max(dp[i + 1][j + r - 10], dp[i][j] + ss[i + 1][r + 4]);
				else
					dp[i + 1][j + r] = max(dp[i + 1][j + r], dp[i][j] + ss[i + 1][r]);
			}
		}
	//for(int i = 1; i <= n; i += 1){
	//	cout << i << ":\n";
	//	for(int j = 0; j < 10; j += 1) cout << dp[i][j] << " ";
	//	cout << "\n";
	//}
	cout << *max_element(dp[n], dp[n] + 10);
	return 0;
}