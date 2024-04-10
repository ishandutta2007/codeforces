#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[105][20005];
int a[105],b[105];
int n,k;
#define geta 10000
int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=0;i<105;i++)for(int j=0;j<20005;j++)dp[i][j]=-100000000;
	dp[0][geta]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=20000;j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			int f=a[i+1]-b[i+1]*k;
			if(j+f<=20000 && j+f>=0) dp[i+1][j+f]=max(dp[i+1][j+f],a[i+1]+dp[i][j]);
		}
	}
	
	cout << (dp[n][geta]<=0?-1:dp[n][geta]) << endl;
}