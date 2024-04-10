#include <bits/stdc++.h>

using namespace std;

double dp[205][205][505];

double p[205];
int a[205];
int n,lim,beg;
int main()
{
	cin >> n >> lim >> beg;
	for(int i=1;i<=n;i++) cin >> p[i];
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[0][0][min(n+250,beg+250)] = 1.0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=n+250;k++)
			{
				//if(dp[i][j][k] == 0.0) continue;
				
				if(a[i+1] == -1)
				{
					if(k) dp[i+1][j+1][k-1] += dp[i][j][k]*p[i+1]/100.0;
					dp[i+1][j][k] += dp[i][j][k]*(100-p[i+1])/100.0;
				}
				else
				{
					dp[i+1][j+1][min(n+250,k+a[i+1])] += dp[i][j][k]*p[i+1]/100.0;
					dp[i+1][j][k] += dp[i][j][k]*(100-p[i+1])/100.0;
				}
			}
		}
	}
	double res = 0.0;
	for(int i=lim;i<=n;i++) for(int j=250;j<=n+250;j++) res += dp[n][i][j];
	printf("%.10f\n",res);
}