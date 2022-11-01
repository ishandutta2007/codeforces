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
bool bj[50001];
int pri[50001],T,n,tmp,tmp1,tot;
inline void pre()
{
	For(i,2,40000)
	{
		if(!bj[i])	pri[++tot]=i;
		For(j,1,tot)
		{
			if(i*pri[j]>40000)	break;
			bj[i*pri[j]]=1;
			if(i%pri[j]==0)	break;
		}
	}
}
inline int get(int x)
{
	For(j,1,tot)
	{
		if(x<=pri[j])	return -1;
		if(x%pri[j]==0)	return pri[j];
	}
	return -1;
}
int main()
{
	pre();
	T=read();
	For(i,1,T)
	{
		n=read();
		int ans=0;
		if(n&1)	ans=1,n-=9;
		if(n==0){puts("1");continue;}
		if(n<4)	{puts("-1");continue;}
		ans+=n/4;
		printf("%d\n",ans);
	}
}