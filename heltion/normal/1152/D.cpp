//Author: Heltion
//Date: 2019-04-24
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 1e9 + 7;
constexpr int maxn = 2400;
int dp[maxn][maxn];
void add(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin >> n;
	dp[0][0] = 1;
	for(int i = 0; i < 2 * n; i += 1)
		for(int j = 0; j < 2 * n; j += 1){
			add(dp[i + 1][j + 1], dp[i][j]);
			if(j) add(dp[i + 1][j - 1], dp[i][j]);
		}
	for(int i = 1; i < 2 * n; i += 2)
		for(int j = 0; j < 2 * n; j += 1)
			if(i + j <= 2 * n) add(ans, dp[i][j]);
	cout << ans;
	return 0;
}