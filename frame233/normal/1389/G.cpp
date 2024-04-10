// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=300005;
bool mark[N];
ll C[N],w[N],val[N];
int E[N][3];
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt=-1;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
int dfn[N],low[N],tree_id;
int st[N],top,bel[N],col;
int key_pt[N];
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tree_id;st[++top]=x;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if((i^fa)==1) continue;
		int v=c[i].v;
		if(!dfn[v]) tarjan(v,i),chmin(low[x],low[v]);
		else if(!bel[v]) chmin(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		while(st[top]!=x) bel[st[top--]]=col;
		--top;
	}
}
ll qwq[N];
ll dp[N],sum[N];
int cnt[N],s,__[N];
ll tot;
void dfs1(int x,int fa)
{
	dp[x]=qwq[x];
	sum[x]=val[x];
	__[x]=cnt[x]=mark[x];
	for(int i=front[x];~i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		qwq[v]=val[v]-c[i].w;
		dfs1(v,x);
		cnt[x]+=cnt[v];
		__[x]+=!!cnt[v];
		sum[x]+=sum[v];
		if(!cnt[v]) dp[x]+=max(0ll,sum[v]);
		else dp[x]+=max(0ll,dp[v]);
	}
}
int root;
void dfs2(int x,int fa,int w)
{
	if(x!=root)
	{
		if(__[x]==0) dp[x]=dp[fa];
		else
		{
			if(cnt[x]==s) dp[x]=dp[x]-qwq[x]+val[x]+max(0ll,(tot-sum[x]));
			else
			{
				if(!cnt[x]) dp[x]=dp[x]-qwq[x]+val[x]+max(0ll,dp[fa]-max(0ll,sum[x])-w);
				else dp[x]=dp[x]-qwq[x]+val[x]+max(0ll,dp[fa]-max(dp[x],0ll)-w);
			}
		}
	}
	for(int i=front[x];~i;i=c[i].nxt) if(c[i].v!=fa) dfs2(c[i].v,x,c[i].w);
}
int main()
{
	memset(front,255,sizeof(front));
	int n,m,k;read(n,m,k);
	for(int i=1;i<=k;++i) read(key_pt[i]);
	for(int i=1;i<=n;++i) read(C[i]);
	for(int i=1;i<=m;++i) read(E[i][2]);
	for(int i=1;i<=m;++i)
	{
		read(E[i][0],E[i][1]);
		addedge(E[i][0],E[i][1],0);
		addedge(E[i][1],E[i][0],0);
	}
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(1,inf);
	memset(front,255,sizeof(front)),edge_cnt=-1;
	for(int i=1;i<=m;++i)
	{
		int x=E[i][0],y=E[i][1],w=E[i][2];
		if(bel[x]!=bel[y]) addedge(bel[x],bel[y],w),addedge(bel[y],bel[x],w);
	}
	for(int i=1;i<=k;++i) mark[bel[key_pt[i]]]=true;
	for(int i=1;i<=n;++i) val[bel[i]]+=C[i],tot+=C[i];
	for(int i=1;i<=col;++i) if(mark[i]) ++s,root=i;
	qwq[root]=val[root];
	dfs1(root,0);
	dfs2(root,0,0);
	for(int i=1;i<=n;++i) printf("%lld ",dp[bel[i]]);
	printf("\n");
	return 0;
}