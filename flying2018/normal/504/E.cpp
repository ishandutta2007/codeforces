#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define N 1000010
#define M 22
#define ll long long
#define P pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define mod 1000000007
P operator +(const P a,const P b){return MP((a.fi+b.fi)%mod,(a.se+b.se)%mod);}
P operator +(const P a,const int b){return MP((a.fi+b)%mod,(a.se+b)%mod);}
P operator -(const P a,const P b){return MP((a.fi-b.fi+mod)%mod,(a.se-b.se+mod)%mod);}
P operator *(const P a,const P b){return MP(1ll*a.fi*b.fi%mod,1ll*a.se*b.se%mod);}
P operator *(const P a,const int b){return MP(1ll*a.fi*b%mod,1ll*a.se*b%mod);}
const P base=MP(233,2333);
P h[N],rh[N],bs[N],iv[N];
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int fa[N][M],f[N][M],lg2[N],dep[N],mdep[N],top[N],fp[N];
int idep[N],tot;
int son[N],pos[N];
vector<int>up[N],dn[N];
char str[N];
int kth_fa(int u,int k)
{
	if(!k) return u;
	u=fa[u][lg2[k]];
	k-=(1<<lg2[k])+dep[u]-dep[top[u]];
	u=top[u];
	return k>0?up[u][k]:dn[u][-k];
}
int LCA(int x,int y)
{
	int l=fp[x],r=fp[y];
	if(l>r) swap(l,r);
	int k=lg2[r-l+1];
	l=f[l][k],r=f[r-(1<<k)+1][k];
	if(idep[l]<=idep[r]) return pos[l];
	else return pos[r];
}
P ksm(P a,int b=mod-2)
{
	P res=MP(1,1);
	for(;b;b>>=1)
	{
		if(b&1) res=res*a;
		a=a*a;
	}
	return res;
}
void dfs1(int u,int pre)
{
	idep[++tot]=mdep[u]=dep[u]=dep[pre]+1;
	pos[tot]=u;
	fa[u][0]=pre;
	fp[u]=tot;
	h[u]=h[pre]*base+(int)(str[u]-'a'+1);
	rh[u]=rh[pre]+bs[dep[pre]]*(int)(str[u]-'a'+1);
	for(int i=1;i<M;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre) continue;
		dfs1(v,u);
		pos[++tot]=u,idep[tot]=dep[u];
		if(mdep[v]>mdep[u]) mdep[u]=mdep[v],son[u]=v;
	}
}
void dfs2(int u,int topp)
{
	top[u]=topp;
	if(u==topp)
	{
		int x=u;
		for(int i=0;i<=mdep[u]-dep[u];i++) up[u].push_back(x),x=fa[x][0];
		x=u;
		for(int i=0;i<=mdep[u]-dep[u];i++) dn[u].push_back(x),x=son[x];
	}
	if(son[u]) dfs2(son[u],topp);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[u][0] || v==son[u]) continue;
		dfs2(v,v);
	}
}
P get_line(int x,int y,int l,int fl)//x->l->y
{
	int d=dep[y]-dep[l];
	P h1=(rh[x]-rh[fl])*iv[dep[fl]],h2=(h[y]-h[l]*bs[d]);
	return (h1*bs[d])+h2;
}
inline int dist(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)]+1;}
inline bool in_dis(int x,int y,int k){return k<=dep[x]-dep[LCA(x,y)];}//k is in the way of x->y
inline int kth_p(int x,int y,int k){return in_dis(x,y,k)?kth_fa(x,k-1):kth_fa(y,dist(x,y)-k);}
int answer(int as,int at,int bs,int bt)
{
	if(str[as]!=str[bs]) return 0;
	int al=LCA(as,at),alf=fa[al][0];
	int bl=LCA(bs,bt),blf=fa[bl][0];
	int l=1,r=min(dist(as,at),dist(bs,bt)),res=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int ax=in_dis(as,at,mid),bx=in_dis(bs,bt,mid),ap=kth_p(as,at,mid),bp=kth_p(bs,bt,mid);
		if(get_line(as,ap,ax?ap:al,ax?fa[ap][0]:alf)==get_line(bs,bp,bx?bp:bl,bx?fa[bp][0]:blf)) l=mid+1,res=mid;
		else r=mid-1;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d%s",&n,str+1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	bs[0]=iv[0]=MP(1,1);
	P inv=ksm(base);
	for(int i=1;i<=n;i++) bs[i]=bs[i-1]*base,iv[i]=iv[i-1]*inv;
	dfs1(1,0);
	dfs2(1,1);
	lg2[0]=-1;
	for(int i=1;i<=tot;i++) lg2[i]=lg2[i>>1]+1,f[i][0]=i;
	for(int j=1;1<<j<=tot;j++)
		for(int i=1;i<=cnt-(1<<j)+1;i++)
		{
			int x=f[i][j-1],y=f[i+(1<<(j-1))][j-1];
			f[i][j]=idep[x]<=idep[y]?x:y;
		}
	int m;
	scanf("%d",&m);
	while(m --> 0)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",answer(a,b,c,d));
	}
	return 0;
}