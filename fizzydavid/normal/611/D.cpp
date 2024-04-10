//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll mod=1000000007;
ll dp[5011][5011],pre[5011][5011];
string s;
int n;
int lcp[5011][5011];
bool ifbigger(int xa,int ya,int xb,int yb)
{
	if(lcp[xa][xb]>=ya-xa+1)return false;
	else
	{
		return s[xa+lcp[xa][xb]]>s[xb+lcp[xa][xb]];
	}
}
int main()
{
	cin>>n>>s;
	s=" "+s;
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(s[i]==s[j])
			{
				lcp[i][j]=1;
				if(i<n&&j<n)lcp[i][j]+=lcp[i+1][j+1];
			}
			else lcp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(s[j]=='0')dp[i][j]=0;
			else if(j==1)dp[i][j]=1;
			else
			{
				dp[i][j]=(pre[j-1][j-1]-(j-(i-j)-1<1?0:pre[j-1][j-(i-j)-1])+mod)%mod;
				if(j-(i-j)-1>=1&&ifbigger(j,i,j-(i-j)-1,j-1))
				{
					dp[i][j]=(dp[i][j]+dp[j-1][j-(i-j)-1])%mod;
				}
			}
			pre[i][j]=(pre[i][j-1]+dp[i][j])%mod;
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[n][i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}