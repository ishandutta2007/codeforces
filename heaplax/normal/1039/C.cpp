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
#define N 500001
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
const int mod=1e9+7;
struct node
{
	int u,v,c;
	bool operator < (const node &i)const
	{
		return c<i.c;
	}
}e[N];
int n,m,k,ans,c[N],fa[N],pow2[N];
int top,st[N+N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
main()
{
	pow2[0]=1;
	for(int i=1;i<N;++i)pow2[i]=pow2[i-1]*2%mod;
	re(n),re(m),re(k);
	ans=1ll*pow2[n]*pow2[k]%mod;
	for(int i=1;i<=n;++i)re(c[i]);
	for(int i=1;i<=m;++i)
	{
		re(e[i].u),re(e[i].v);
		e[i].c=c[e[i].u]^c[e[i].v];
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i)fa[i]=i;
	int last=n;
	for(int i=1;i<=m;++i)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)
		{
			--last;
			fa[u]=v;
			st[++top]=u;
			st[++top]=v;
		}
		if(i==m || e[i].c!=e[i+1].c)
		{
			ans+=pow2[last]-pow2[n];
			last=n;
			for(;top;--top)
				fa[st[top]]=st[top];
		}
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
}