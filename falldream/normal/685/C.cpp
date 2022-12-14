#include<iostream>
#include<cstdio>
#define MN 100000
#define INF (ll)4e18
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll X[MN+5],Y[MN+5],Z[MN+5],A,B,C;
int n;
inline void Inter(pair<ll,ll>&s,ll l,ll r)
{
	s.first=max(s.first,l);
	s.second=min(s.second,r);
	if(s.first%2) ++s.first;
	if(s.second%2) --s.second;	
}
bool Solve(ll mid)
{
	for(int r=0;r<2;++r)
	{
		pair<ll,ll> a(-INF,INF),b(-INF,INF),c(-INF,INF),d(-INF,INF);
		for(int i=1;i<=n;++i)
		{
			ll pa=X[i]-Y[i]-Z[i];Inter(a,-pa-mid-r,-pa+mid-r);		
			ll pb=Y[i]-X[i]-Z[i];Inter(b,-pb-mid-r,-pb+mid-r);
			ll pc=Z[i]-X[i]-Y[i];Inter(c,-pc-mid-r,-pc+mid-r);
			ll pd=-X[i]-Y[i]-Z[i];Inter(d,-pd-mid-3*r,-pd+mid-3*r);
		}
		Inter(d,a.first+b.first+c.first,a.second+b.second+c.second);
		if(a.first>a.second||b.first>b.second||c.first>c.second||d.first>d.second) continue;
		ll sa=min(a.second,d.first-b.first-c.first);
		ll sb=min(b.second,d.first-c.first-sa);
		ll sc=d.first-sa-sb;
		A=(sb+sc)/2+r;
		B=(sa+sc)/2+r;
		C=(sa+sb)/2+r;
		return true;
	}
	return false;
}
inline ll Abs(ll x){return x<0?-x:x;}
int main()
{
	for(int T=read();T;--T)
	{
		n=read();
		for(int i=1;i<=n;++i) X[i]=read(),Y[i]=read(),Z[i]=read();
		ll l=0,r=INF,mid,res;		
		while(l<=r)
		{
			mid=l+r>>1;
			if(Solve(mid)) res=mid,r=mid-1;
			else l=mid+1;
		}
		Solve(res);
		printf("%lld %lld %lld\n",A,B,C);
	}
	return 0;
}