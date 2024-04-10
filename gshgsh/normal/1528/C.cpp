#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(k) k<<1
#define rs(k) k<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define pb push_back
#define MAXN 300001
int T,N,fa[MAXN][20],tot,dfn[MAXN],siz[MAXN],sum[MAXN*4],tg[MAXN*4],cnt,ans;vector<int>E1[MAXN],E2[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),0:0,sum[k]=tg[k]=0;}
void pt(int k,int l,int r,int v){sum[k]+=v*(r-l+1),tg[k]+=v;}void dwn(int k,int l,int r){pt(ls(k),l,R,tg[k]),pt(rs(k),L,r,tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k,l,r),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),sum[k]=sum[ls(k)]+sum[rs(k)]:(pt(k,l,r,v),0):0;}
int ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?dwn(k,l,r),ask(ls(k),l,R,x,y)+ask(rs(k),L,r,x,y):sum[k]:0;}
void dfs1(int u){For(i,1,19)fa[u][i]=fa[fa[u][i-1]][i-1];dfn[u]=++tot,siz[u]=1;for(auto v:E2[u])dfs1(v),siz[u]+=siz[v];}
void dfs2(int u)
{
	int y=ask(1,1,N,dfn[u],dfn[u]+siz[u]-1),pre=0,now=0;
	if(!y)upd(1,1,N,dfn[u],dfn[u]+siz[u]-1,1),now=1,cnt++,ans=max(ans,cnt);
	else if(y==siz[u]){int x=u;FOR(i,19,0)if(fa[x][i]&&ask(1,1,N,dfn[fa[x][i]],dfn[fa[x][i]]+siz[fa[x][i]]-1)==siz[fa[x][i]])x=fa[x][i];upd(1,1,N,dfn[x],dfn[x]+siz[x]-1,-1),upd(1,1,N,dfn[u],dfn[u]+siz[u]-1,1),pre=x,now=1;}
	for(auto v:E1[u])dfs2(v);if(now)upd(1,1,N,dfn[u],dfn[u]+siz[u]-1,-1),cnt--;if(pre)upd(1,1,N,dfn[pre],dfn[pre]+siz[pre]-1,1),cnt++;
}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)E1[i].clear(),E2[i].clear(),dfn[i]=siz[i]=0;For(i,2,N)E1[get()].pb(i);For(i,2,N)E2[fa[i][0]=get()].pb(i);
		tot=cnt=ans=0;build(1,1,N);dfs1(1);dfs2(1);cout<<ans<<endl;
	}
	return 0;
}