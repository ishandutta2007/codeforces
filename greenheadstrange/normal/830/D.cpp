#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <ctime>
#include <algorithm>
#include <set>
#include <queue>
#define maxn 405
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[maxn][maxn]; // k n 
int main()
{
	dp[1][1] = dp[1][0] = 1;
	int k;
	scanf("%d", &k);
	for(int i = 2; i <= k; i++)
	{
		dp[i][0] = 1;
		for(int j = 1; j < maxn - i; j++)
		{
			// 
			for(int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k] * dp[i - 1][j - k], dp[i][j] %= mod;
			// 
			for(int k = 0; k <= j - 1; k++)
				dp[i][j] += dp[i - 1][k] * dp[i - 1][j - 1 - k], dp[i][j] %= mod;
			//
			for(int k = 0; k <= j; k++)
			{
				ll nans = dp[i - 1][k + 1];
				nans *= (k + 1), nans %= mod;
				nans *= dp[i - 1][j - k], nans %= mod;
				nans *= (j - k);
				nans *= 2; //  
				dp[i][j] += nans, dp[i][j] %= mod;
			}
			// 
			for(int k = 0; k <= j; k++)
			{	// k :  
				ll nans = dp[i - 1][k];
				nans *= dp[i - 1][j - k], nans %= mod;
				nans *= (j - k);
				nans *= 4; //  & 	
				dp[i][j] += nans, dp[i][j] %= mod;
			} 
			//
			for(int k = 0; k <= j; k++)
			{	// k :  
				ll nans = dp[i - 1][k];
				nans *= 2;
				nans *= dp[i - 1][j - k + 1], nans %= mod;
				nans *= (j - k + 1) * (j - k);
				dp[i][j] += nans, dp[i][j] %= mod;
			} 
		}
	}
	printf("%I64d\n", dp[k][1]);
	return 0; 
}