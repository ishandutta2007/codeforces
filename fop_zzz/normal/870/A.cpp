#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,m,x,mi1=20,mi2=20,t=10,hav[20];
int main()
{
	n=read();m=read();
	For(i,1,n)	x=read(),mi1=min(mi1,x),hav[x]=1;
	For(i,1,m)	{x=read(),mi2=min(mi2,x);if(hav[x])	t=min(t,x);}
	if(t!=10)	return printf("%d\n",t),0;
	printf("%d%d",min(mi1,mi2),max(mi1,mi2));
}