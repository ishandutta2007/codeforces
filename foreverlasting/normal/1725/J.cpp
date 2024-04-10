#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define gc getchar
#define pli pair<LL,int>
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
inline int rd(){
    int s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
const int N=1e5+10,mxn=1e6+10;
const LL infl=1e18;
int n,id[mxn],fa[mxn];
LL sum,ans,f1[mxn],f2[mxn],g[mxn],F[mxn],G[mxn];
int t,h[mxn];
struct Tre
{
	int to,val,nxt;
}e[mxn<<1];
vector<pli> q[mxn],qq[mxn];
void add(int u,int v,int w)
{
	e[++t]=(Tre){v,w,h[u]};h[u]=t;
	e[++t]=(Tre){u,w,h[v]};h[v]=t;
}
void dfs1(int u)
{
	int v;
	for(int i=h[u];i;i=e[i].nxt)
		if((v=e[i].to)!=fa[u])
		{
			fa[v]=u;dfs1(v);F[u]=max(F[u],F[v]);
			LL mxv=f1[v]+e[i].val;
			if(mxv>f1[u]) f2[u]=f1[u],f1[u]=mxv,id[u]=v;
			else if(mxv>f2[u]) f2[u]=mxv;
		}
	F[u]=max(F[u],f1[u]+f2[u]);
}
void dfs2(int u)
{
	int v;q[u].pb({g[u],fa[u]});
	for(int i=h[u];i;i=e[i].nxt)
		if((v=e[i].to)!=fa[u])
			q[u].pb({f1[v]+e[i].val,v}),
			qq[u].pb({F[v],v});
	sort(q[u].begin(),q[u].end(),greater<pli>());
	sort(qq[u].begin(),qq[u].end(),greater<pli>());
	LL res=0;
	for(int i=0,sz=q[u].size();i<4&&i<sz;++i) res+=q[u][i].fr;
	ans=max(ans,res);
	LL a[2];
	for(int i=h[u];i;i=e[i].nxt)
		if((v=e[i].to)!=fa[u])
		{
			if(v==id[u]) g[v]=max(g[u],f2[u])+e[i].val;
			else g[v]=max(g[u],f1[u])+e[i].val;
			a[0]=a[1]=0;
			for(auto X:q[u])
				if(X.sc!=v)
				{
					if(!a[0]) a[0]=X.fr;
					else {a[1]=X.fr; break;}
				}
			G[v]=max(G[u],a[0]+a[1]);
			if(qq[u][0].sc==v) G[v]=max(G[v],qq[u][1].fr); else G[v]=max(G[v],qq[u][0].fr);
			ans=max(ans,F[v]+G[v]+e[i].val*2);
			dfs2(v);
		}
}
int main(){
	n=rd();int x,y,z;
	for(int i=1;i<n;++i) x=rd(),y=rd(),z=rd(),add(x,y,z),sum+=z*2;
	dfs1(1);dfs2(1);
	printf("%lld\n",sum-ans);
	return 0;
}