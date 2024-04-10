//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
bool np[1000111];
int p[1000111],tot;
int calc(ll x)
{
	int cnt=0;
	for(int i=0;i<tot&&1ll*p[i]*p[i]<=x;i++)
	{
		while(x%p[i]==0)
		{
			x/=p[i];
			cnt++;
		}
	}
	cnt+=x>1;
	return cnt;
}
void conv(int a[],int b[],bool f=0)
{
	for(int i=255;i>=0;i--)
	{
		if(b[i]>mod)continue;
		for(int j=0;j<256;j++)
		{
			if((i&j)==0)
			{
				b[i|j]=min(b[i|j],b[i]+a[j]);
			}
		}
		if(f)b[i]=mod;
	}
}
int n;
ll a[10];
int dp[10][256],ans[256],tdp[256];
int main()
{
	for(int i=2;i<=1000000;i++)
	{
		if(np[i])continue;
		p[tot++]=i;
		for(int j=i+i;j<=1000000;j+=i)
		{
			np[j]=1;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	memset(dp,63,sizeof(dp));
	memset(ans,63,sizeof(ans));
	ans[0]=0;
	int mn=mod;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			if(j>>i)continue;
			ll tmp=a[i];
			for(int k=0;k<n;k++)
			{
				if((j>>k)&1)
				{
					if(tmp%a[k]!=0)tmp=0;
					tmp/=a[k];
				}
			}
			if(tmp==0)continue;
			memset(tdp,63,sizeof(tdp));
			int dlt=calc(tmp);
			tdp[0]=(j>0||dlt>1);
			for(int k=0;k<n;k++)
			{
				if((j>>k)&1)
				{
					conv(dp[k],tdp,1);
				}
			}
			for(int k=0;k<(1<<n);k++)
			{
				dp[i][(1<<i)|k]=min(dp[i][(1<<i)|k],tdp[k]+dlt);
			}
		}
		mn=min(mn,dp[i][(1<<n)-1]);
		conv(dp[i],ans);
	}
	cout<<min(mn,ans[(1<<n)-1]+1)<<endl;
	return 0;
}