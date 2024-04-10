#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
char inp[maxn];
int mp[maxn][maxn], tw[maxn][maxn][2]; 
ll dp[maxn][maxn][2];	
int n, m;
ll gdp(int i, int j, int tp) {
	if (i > n || j > m) return 0;
	if (i == n && j == m) return 1;
	if (i == n && tp == 1) return (tw[i][j][1] == 0);
	if (j == m && tp == 0) return (tw[i][j][0] == 0);
	if (dp[i][j][tp] != -1) return dp[i][j][tp];
	
	ll nans = 0;
	if (tp == 0) {
		nans = gdp(i + 1, j, tp);
		nans = (nans + gdp(i + 1, j, tp ^ 1));
		if (mp[i + 1][j]) nans -= gdp(n + 1 - tw[i][j][0], j, tp ^ 1);
	}
	else {
		nans = gdp(i, j + 1, tp);
		nans = nans + gdp(i, j + 1, tp ^ 1);
		if (mp[i][j + 1]) nans -= gdp(i, m + 1 - tw[i][j][1], tp ^ 1);
	}
	nans %= mod;
	if (nans < 0) nans += mod;
	dp[i][j][tp] = nans;
//	cout << i << ' ' << j << ' ' << tp << ' ' << dp[i][j][tp] << endl;
	return nans;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp + 1);
		for (int j = 1; j <= m; j++)
			if (inp[j] == 'R')
				mp[i][j] = 1;
	}
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--) {
			tw[i][j][0] = tw[i + 1][j][0] + mp[i + 1][j];
			tw[i][j][1] = tw[i][j + 1][1] + mp[i][j + 1];
		}
	memset(dp, -1, sizeof(dp));
	ll ans = 1;
	if(n == 1 && m == 1) ans = 1;
	else ans = (gdp(1, 1, 0) + gdp(1, 1, 1)) % mod;
	cout << ans << endl; 
	return 0;
}
/*
1 2
..
*/