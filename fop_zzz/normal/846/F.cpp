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
ll ANS;
ll n,a[2000001],head[2000001],nxt[2000001];
bool vis[2000001];
inline ll sqr(ll x){return x*x;}
inline void solve(ll x)
{
	ll ans=n*n;
	ll t=head[a[x]];
	ans-=sqr(n-t);
	ll las=t-1;
	if(!nxt[t])	{ans-=sqr(t-1);}
	else
		{
			t=nxt[t];
			while(t)
			{
				ans-=sqr(las-t);
				las=t-1;
				if(!nxt[t])	{ans-=sqr(t-1);break;}
				t=nxt[t];
			}
		}
	ANS+=ans;vis[a[x]]=1;
}
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)
	{
		if(!head[a[i]])	head[a[i]]=i;else nxt[i]=head[a[i]],head[a[i]]=i;
	}
	
	For(i,1,n)
		if(!vis[a[i]])
			solve(i);
	printf("%.10lf",1.0*ANS/(n*n));
}