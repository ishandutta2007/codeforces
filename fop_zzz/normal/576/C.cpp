#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define pb push_back
#define inf 1e9
#define maxn 500001
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
ll n,L[2001],R[2001];
struct node{ll x,y,b,num;}	p[1000001];
inline bool cmp(node x,node y){return x.b<y.b;}
inline bool cmp1(node x,node y){return x.y<y.y;}
int main()
{
	n=read();
	For(i,1,n)	p[i].x=read(),p[i].y=read(),p[i].num=i;
	For(i,1,n)	p[i].b=p[i].x/1000;
	sort(p+1,p+n+1,cmp);
	For(i,0,2000)L[i]=inf;
	For(i,1,n)	L[p[i].b]=min(L[p[i].b],i),R[p[i].b]=max(R[p[i].b],i);
	ll now=1;
	For(i,0,1001)
	{
		if(L[i]>R[i])	continue;
		sort(p+L[i],p+R[i]+1,cmp1);
		if(now)	
			For(j,L[i],R[i])	printf("%d ",p[j].num);
			else	Dow(j,L[i],R[i])	printf("%d ",p[j].num);
		now^=1;
	}
}