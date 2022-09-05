//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int mod=998244353;
const int proot=3;
ll kissme(ll x,ll k)
{
	ll ans=1;
	while(k)
	{
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
void FFT(int a[],int sz,bool rev)
{
	for(int i=0,j=0;i<sz;i++)
	{
		if(i>j)swap(a[i],a[j]);
		for(int l=sz>>1;(j^=l)<l;l>>=1);
	}
	for(int l=1;l<sz;l<<=1)
	{
		int l2=l<<1,w=kissme(proot,(mod-1)/l2);
		if(rev)w=kissme(w,mod-2);
		for(int i=0;i<sz;i+=l2)
		{
			int ww=1;
			for(int j=0;j<l;j++)
			{
				int tmp=1ll*a[i+j+l]*ww%mod;
				a[i+j+l]=a[i+j]-tmp<0?a[i+j]-tmp+mod:a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp>=mod?a[i+j]+tmp-mod:a[i+j]+tmp;
				ww=1ll*ww*w%mod;
			}
		}
	}
	if(rev)
	{
		int t=kissme(sz,mod-2);
		for(int i=0;i<sz;i++)a[i]=1ll*t*a[i]%mod;
	}
}
const int nn=65536;
int dp[3][nn],n,k;
int cv[3][nn];
int ndp[3][nn];
void Inc()
{
	for(int i=0;i<(nn>>1);i++)
	{
		dp[0][i]=dp[2][i];
		if(i>0)
		{
			dp[0][i]+=dp[2][i-1];
			if(dp[0][i]>=mod)dp[0][i]-=mod;
			dp[0][i]+=dp[1][i-1];
			if(dp[0][i]>=mod)dp[0][i]-=mod;
		}
	}
	swap(dp[0],dp[1]);
	swap(dp[1],dp[2]);
}
void Double()
{
	FFT(dp[0],nn,0);
	FFT(dp[1],nn,0);
	FFT(dp[2],nn,0);
	for(int i=0;i<nn;i++)
	{
		cv[0][i]=1ll*dp[0][i]*dp[0][i]%mod;
		cv[1][i]=1ll*dp[1][i]*dp[1][i]%mod;
		cv[2][i]=1ll*dp[2][i]*dp[2][i]%mod;
	}
	FFT(cv[0],nn,1);
	FFT(cv[1],nn,1);
	FFT(cv[2],nn,1);
	for(int i=0;i<(nn>>1);i++)
	{
		ndp[2][i]=cv[2][i];
		if(i>0)ndp[2][i]=(ndp[2][i]+cv[1][i-1])%mod;
		ndp[0][i]=cv[1][i];
		if(i>0)ndp[0][i]=(ndp[0][i]+cv[0][i-1])%mod;
	}
	for(int i=0;i<(nn>>1);i++)
	{
		ndp[1][i]=ndp[2][i];
		if(i>0)ndp[1][i]=(1ll*ndp[1][i]-1ll*ndp[1][i-1]-1ll*ndp[0][i-1]+mod+mod)%mod;
	}
	for(int i=nn>>1;i<nn;i++)ndp[0][i]=ndp[1][i]=ndp[2][i]=0;
	swap(dp,ndp);
}
int main()
{
	cin>>n>>k;
	dp[0][0]=1;
	dp[1][0]=dp[1][1]=1;
	dp[2][0]=dp[2][2]=1;dp[2][1]=3;
	if(n<=2)
	{
		for(int i=1;i<=k;i++)printf("%d ",dp[n][i]);
		return 0;
	}
	int flag=0;
	for(int i=30;i>=0;i--)
	{
		if(flag)
		{
			if(flag-1)Double();
			if((n>>i)&1)Inc();
			flag++;
		}
		else if((n>>i)&1)flag=1;
	}
	for(int i=1;i<=k;i++)printf("%d ",dp[2][i]);
	return 0;
}