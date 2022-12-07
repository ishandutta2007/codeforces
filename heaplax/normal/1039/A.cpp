#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 200005
#define INF 3e18
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,t,a[N],x[N],tag[N],sma[N],big[N],b[N];
void add(int l,int r)
{
	++tag[l];--tag[r+1];
}
main()
{
	re(n),re(t);
	for(int i=1;i<=n;++i)
		re(a[i]),a[i]+=t;
	a[n+1]=b[n+1]=INF;
	for(int i=1;i<=n;++i)big[i]=INF;
	for(int i=1;i<=n;++i)
	{
		re(x[i]);
		if(x[i]<x[i-1] || x[i]<i)
		{
			puts("No");
			return 0;
		}
		add(i,x[i]-1);
		big[x[i]]=a[x[i]+1]-1;
	}
	for(int i=1;i<=n;++i)
	{
		tag[i]+=tag[i-1];
		if(tag[i])sma[i]=a[i+1];
		else sma[i]=a[i];
	}
	for(int i=n;i;--i)
	{
		big[i]=min(big[i],b[i+1]-1);
		if(sma[i]<=big[i])
			b[i]=big[i];
		else
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;++i)
		printf("%lld ",b[i]);
}