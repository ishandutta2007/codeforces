#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back


using namespace std;

inline ll read()
{
	ll t=0,dp=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

ll mo=1e9+7;
const int N=200005;
ll n,que,a[N],w[N],tr1[N],tr2[N];
inline ll Ask1(ll x)
{
	ll sum=0;for(;x;x-=x&-x)	sum=(sum+tr1[x]+mo)%mo;
	return sum;
}
inline ll Ask2(ll x)
{
	ll sum=0;for(;x;x-=x&-x)	sum+=tr2[x];
	return sum;
}
inline void Insert1(ll x,ll v){for(;x<=n;x+=x&-x)	tr1[x]=(tr1[x]+v%mo+mo)%mo;}
inline void Insert2(ll x,ll v){for(;x<=n;x+=x&-x)	tr2[x]+=v;}
inline ll Query1(ll l,ll r){return (Ask1(r)-Ask1(l-1)+mo)%mo;}
inline ll Query2(ll l,ll r){return Ask2(r)-Ask2(l-1);}

inline bool check(ll l,ll r,ll mid)
{
	ll t1=Query2(l,mid),t2=Query2(mid+1,r);
	return t1>=t2;
}
int main()
{
	n=read();que=read();
	For(i,1,n)	a[i]=read()-i+1;
	For(i,1,n)	w[i]=read();
	For(i,1,n)	Insert1(i,a[i]*w[i]%mo),Insert2(i,w[i]);
	For(i,1,que)
	{	
		ll ql=read(),qr=read();
		if(ql>0)
		{
			ll l=ql,r=qr,ans=r;
			while(l<=r)
			{
				ll mid=l+r>>1;
				if(check(ql,qr,mid))	ans=mid,r=mid-1;else	l=mid+1;
			}
			ll ANS=(Query2(ql,ans)%mo*a[ans]%mo-Query1(ql,ans))%mo;
			ANS+=(-Query2(ans+1,qr)%mo*a[ans]%mo+Query1(ans+1,qr)%mo)%mo;
			ANS=(ANS%mo+mo)%mo;
			writeln(ANS);
		}
		else
		{
			ql=-ql;
			Insert1(ql,a[ql]*(qr-w[ql])%mo);
			Insert2(ql,(qr-w[ql]));
			w[ql]=qr;
		}
	}
}