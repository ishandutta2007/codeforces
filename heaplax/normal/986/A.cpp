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
#define N 100001
#define LL long long
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
int n,m,k,s,top,st[N],a[N],dis[N][101];
int cnt,head[N],nxt[N+N],to[N+N];
int main()
{
	re(n),re(m),re(k),re(s);
	for(int i=1;i<=n;++i)re(a[i]);
	for(int i=1,u,v;i<=m;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(dis,-1,sizeof dis);
	for(int i=1;i<=k;++i)
	{
		top=0;
		for(int j=1;j<=n;++j)
			if(a[j]==i)
				dis[j][i]=0,st[++top]=j;
		for(int j=1;j<=top;++j)
			for(int l=head[st[j]];l;l=nxt[l])
				if(!~dis[to[l]][i])
				{
					dis[to[l]][i]=dis[st[j]][i]+1;
					st[++top]=to[l];
				}
	}
	for(int i=1;i<=n;++i)
	{
		nth_element(dis[i]+1,dis[i]+s,dis[i]+k+1);
		LL sum=0;
		for(int j=1;j<=s;++j)
			sum+=dis[i][j];
		printf("%lld ",sum);
	}
}