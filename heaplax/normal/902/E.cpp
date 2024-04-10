#include<cstdio>
#include<algorithm>
#define N 600001
#define int long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
int n,m,ct,fir[N],fa[N],sy[N],sum[N],sm[N],l[N],r[N];
int cnt,head[N],nxt[N],to[N];
bool vis[N];
void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u],v;i;i=nxt[i])
		if(!vis[v=to[i]])
		{
			fa[v]=u;
			dfs(v);
		}
		else if(v!=fa[u] && !sy[v])
		{
			++ct;
			l[ct]=r[ct]=u;
			sy[u]=ct;
			for(int j=u;j!=v;j=fa[j])	
			{
				sy[fa[j]]=ct;
				l[ct]=min(l[ct],fa[j]),
				r[ct]=max(r[ct],fa[j]);
			}
		}
}
main()
{
	re(n),re(m);
	for(int u,v;m--;)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
			dfs(i);
	for(int i=1;i<=n;++i)sum[i]=n;
	for(int i=1;i<=ct;++i)
		sum[l[i]]=min(sum[l[i]],r[i]-1);
	for(int i=n-1;i;--i)
		sum[i]=min(sum[i],sum[i+1]);
	for(int i=1;i<=n;++i)
		sm[i]=sm[i-1]+sum[i]-i+1;
	for(int i=n;i;--i)
		fir[sum[i]]=i;
	fir[n+1]=n;
	for(int i=n-1;i;--i)
		if(!fir[i])
			fir[i]=fir[i+1];
	int q;re(q);
	while(q--)
	{
		int x,y;
		re(x),re(y);
		int c=max(fir[y+1],x);
		if(c>y)printf("%I64d\n",sm[y]-sm[x-1]);
		else
		{
			int t=y-c+1;
			printf("%I64d\n",sm[c-1]-sm[x-1]+t*(t+1)/2);
		}
	}
}