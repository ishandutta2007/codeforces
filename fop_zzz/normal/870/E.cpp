#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define pb push_back
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
set<ll> S;
map<ll,vector<ll> >e;
ll n,x,y,ans=1,siz,tr,mo=1e9+7;
inline void dfs(ll x)
{
	S.erase(x);
	siz++;
	For(i,0,e[x].size()-1)
	{
		tr++;
		if(S.count(e[x][i]))	dfs(e[x][i]);
	}
}
inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2){if(y&1)	sum=sum*x%mo;x=x*x%mo;}	return sum;}
int main()
{
	n=read();
	For(i,1,n)
	{
		x=read();y=read();
		x*=2;y*=2;y++;
		S.insert(x);S.insert(y);
		e[x].pb(y);e[y].pb(x);
	}
	while(!S.empty())
	{	
		ll x=*S.begin();
		siz=0;tr=0;
		dfs(x);
		if(siz*2-2==tr)	ans*=(ksm(2,siz)-1),ans%=mo;
			else ans*=(ksm(2,siz)),ans%=mo;
	}
	printf("%I64d\n",ans);
}