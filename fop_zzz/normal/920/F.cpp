#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*f;
}
inline void write(ll x){if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
ll pri[2000001],bj[2000001],to[2000001],n,m,a[500001],tot,di[2000001];
inline void Pre()
{
	For(i,2,1000000)
	{
		if(!bj[i])	pri[++tot]=i,di[i]=i;
		For(j,1,tot)
		{
			if(i*pri[j]>1000000)	break;
			bj[i*pri[j]]=1;di[i*pri[j]]=pri[j];
			if(i%pri[j]==0)	break;
		}
	}
	to[1]=1;
	For(i,2,1000000)
	{
		ll now=i,las=-1,tmp=0,ans=1;
		while(1)
		{
			ll t=di[now];
			if(t==las)	tmp++;else ans*=(tmp+1),tmp=1,las=t;
			now/=t;
			if(now==1)	break;
		}
		ans*=(tmp+1);
		to[i]=ans;
	}
}
ll tr[500001],Fa[500001],opt,l,r;
ll ans;
inline void Add(ll x,ll v){for(;x<=n;x+=x&-x)	tr[x]+=v;}
inline ll Ask(ll x){ll sum=0;for(;x;x-=x&-x)	sum+=tr[x];return sum;}
inline ll Get(ll x){return x==Fa[x]?x:Fa[x]=Get(Fa[x]);}
int main()
{
	n=read();m=read();
	For(i,1,n)	a[i]=read();
	Pre();
	For(i,1,n)	Add(i,a[i]);
	For(i,1,n+1)	Fa[i]=i;
	For(i,1,m)
	{
		opt=read();l=read();r=read();
		if(opt==1)
		{
			ll now=Get(l);
			while(now<=r)
			{
				Add(now,-a[now]);
				Add(now,to[a[now]]);
				a[now]=to[a[now]];
				if(a[now]==1||a[now]==2)	Fa[now]=Get(now+1);
				now=Get(now+1);
			}
		}
		else
		{
			ans=Ask(r)-Ask(l-1);
			writeln(ans);
		}
	}
}