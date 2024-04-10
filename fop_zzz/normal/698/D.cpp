#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c==' '||c=='\n')	c=getchar();
	if(c=='-')	f=-1,c=getchar();
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
struct poi
{
	ll x,y;
} st[10],ms[2001];
ll tim,k,n,gg[2001],que[10],alr,ans;
vector<ll> mp[10][1101];
bool vis[10];
ll operator *(const poi &x,const poi &y){return x.x*y.y-x.y*y.x;}
poi operator -(const poi &x,const poi &y){static poi tmp;tmp.x=x.x-y.x;tmp.y=x.y-y.y;return tmp;}
ll operator ^(const poi &x,const poi &y){return x.x*y.x+x.y*y.y;}
inline bool check(const poi &x,const poi &a,const poi &b)
{
	if((x-a)*(x-b)!=0)	return 0;
	if(a.y==b.y)	return (x.x)<max(a.x,b.x)&&(x.x)>min(a.x,b.x);
		else return (x.y)<max(a.y,b.y)&&(x.y)>min(a.y,b.y);
}
inline bool kill(ll x)
{
	alr++;	
	if(alr==k+1)	return 0;
	if(mp[que[alr]][x].empty())	{gg[x]=tim;return 1;}
	ll gd=alr;
	for(ll i=0;i<mp[que[gd]][x].size();++i)
	{
		ll t=mp[que[gd]][x][i];
		if(gg[t]!=tim)	if(!kill(t))	return 0;
	}
	gg[x]=tim;return 1;
}
inline bool dfs(ll to,ll x)
{
	if(x==k+1)	{alr=0;tim++;return kill(to);}
	bool flag=0;
	For(i,1,k)
	{
		if(!vis[i])
		{
			vis[i]=1;que[x]=i;
			flag|=dfs(to,x+1);
			vis[i]=0;
			if(flag)	return 1;
		}
	}
	return flag;
}
int  main()
{
	k=read();n=read();
	For(i,1,k)	st[i].x=read(),st[i].y=read();
	For(i,1,n)	ms[i].x=read(),ms[i].y=read();
	For(i,1,k)
		For(j,1,n)
		{
			For(k,1,n)
				if(k!=j&&check(ms[k],st[i],ms[j]))	mp[i][j].push_back(k);
		}
	For(i,1,n)	
	{
		memset(vis,0,sizeof vis);
		if(dfs(i,1))	ans++;	
	}
	cout<<ans<<endl;
}
/*
2 102
748806 -110958
748077 -111444
748563 -111039
748257 -111552
748644 -111012
748959 -111111
748239 -111318
748734 -110958
749292 -112173
748797 -110958
748416 -111264
748239 -111390
749184 -111399
748725 -112011

*/