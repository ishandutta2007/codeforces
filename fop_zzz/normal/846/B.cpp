#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
ll n,m,t,sum[2001],a[2001],cnt[2001];
ll ans;
int main()
{
	n=read();m=read();t=read();
	For(i,1,m)	a[i]=read();
	sort(a+1,a+m+1);
	For(i,1,m)	sum[i]=sum[i-1]+a[i];
	For(i,0,n)
	{
		ll tans=(m+1)*i;
		ll rest=t-i*sum[m];
		if(rest<0)	break;
		ll have=n-i;
		For(j,1,m)	cnt[j]=have;
		For(j,1,m)	while(cnt[j]&&rest>=a[j])	cnt[j]--,tans++,rest-=a[j];
		ans=max(ans,tans);
	}
	cout<<ans<<endl;
}