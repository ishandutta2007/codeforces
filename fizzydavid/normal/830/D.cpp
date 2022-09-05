//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
int n;
ll dp[411][411];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)dp[i][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=j;k++)
			{
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k]%mod*(j*2+1)%mod;
			}
			for(int k=1;k<=j+1;k++)
			{
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k+1]%mod*(k*(j-k+1)+k*(k-1))*2%mod;
			}
			for(int k=0;k<j;k++)
			{
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k-1]%mod;
			}
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n][1]<<endl;
	return 0;
}