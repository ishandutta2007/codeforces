#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n;
ll a[10001],sum[10001];
ll ans,ans1,ans2,ans3;
inline void solve(int x)
{
	int t1=0,t2=x,t3=0;
	ll mx=-inf;
	For(i,0,t2){if(sum[i]-(sum[x]-sum[i])>mx)	mx=sum[i]-(sum[x]-sum[i]),t1=i;}
	ll mx2=-inf;
	For(i,t2,n){if((sum[i]-sum[t2])-(sum[n]-sum[i])>mx2)	mx2=sum[i]-sum[t2]-sum[n]+sum[i],t3=i;}
	if(mx+mx2>ans)	ans=mx+mx2,ans1=t1,ans2=t2,ans3=t3;
}
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	sum[i]=sum[i-1]+a[i];
	For(i,0,n)
		solve(i);
	cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
}