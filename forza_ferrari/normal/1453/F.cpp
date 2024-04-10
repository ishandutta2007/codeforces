#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[3001],dp[3001][3001],cnt,sum[3001][3001];
bool vis[3001][3001];
int main()
{
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	for(int i=1;i<=n;++i)
    	{
    		cin>>a[i];
    		for(int j=1;j<=n;++j)
    		{
    			sum[i][j]=sum[i-1][j]+(i+a[i]<=j);
    			dp[i][j]=0;
    		}
    	}
    	dp[1][1]=1;
    	for(int i=1;i<n;++i)
    		if(a[i])
    		{
    			int maxn=dp[i][i];
    			for(int j=i+1;j<=i+a[i];++j)
    			{
    				dp[j][i+a[i]]=max(dp[j][i+a[i]],maxn+sum[j-1][j-1]-sum[i][j-1]+1);
    				maxn=max(maxn,dp[i][j]);
    			}
    		}
    	cout<<n-dp[n][n]<<'\n';
    }
	return 0;
}