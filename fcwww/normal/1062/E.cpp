#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <vector>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef double f2;
typedef long double f3;
#define N 100050
#define OUTSIZE 1050
#define rep(n) for(i=1;i<=n;i++)
#define per(n) for(i=n;i;i--)
char buf[100000],*p1,*p2;
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd() {
	int x=0; char s=nc();
	while(s<'0'||s>'9') s=nc();
	while(s>='0'&&s<='9') x=(((x<<2)+x)<<1)+s-'0',s=nc();
	return x;
}
namespace SA {
	int n,ws[OUTSIZE],wa[OUTSIZE],wb[OUTSIZE],rk[OUTSIZE],height[OUTSIZE],sa[OUTSIZE];
	char w[OUTSIZE];
	void build(int m) {
		int i,j,p,*x=wa,*y=wb;
		rep(m)ws[i]=0;
		rep(n)ws[x[i]=w[i]]++;
		rep(m)ws[i]+=ws[i-1];
		per(n)sa[ws[x[i]]--]=i;
		for(j=1;j<n;j<<=1) {
			for(p=0,i=n;i>n-j;i--) y[++p]=i;
			rep(n)if(sa[i]>j) y[++p]=sa[i]-j;
			rep(m)ws[i]=0;
			rep(n)ws[x[i]]++;
			rep(m)ws[i]+=ws[i-1];
			per(n)sa[ws[x[y[i]]]--]=y[i];
			swap(x,y);
			m=1;
			rep(n)x[sa[i]]=y[sa[i]+j]==y[sa[i+1]+j]&&y[sa[i]]==y[sa[i+1]]?m:m++;
			if(m>n) break;
		}
		rep(n)rk[sa[i]]=i; 
		p=0;
		rep(n)if(rk[i]!=n) {
			j=rk[i]+1;
			for(;w[i+p]==w[sa[j]+p];p++) ;
			height[rk[i]]=p;
			if(p) p--;
		}
	}
	void init() {
		n=6; w[1]='a'; w[2]='b'; w[3]='a'; w[4]='b'; w[5]='b'; w[6]='a';
		build(128);
	}
}
namespace Scape_Goat_Tree {
	#define ls ch[p][0]
	#define rs ch[p][0]
	int ch[OUTSIZE][2],val[OUTSIZE],siz[OUTSIZE],tot[OUTSIZE],ex[OUTSIZE],S[OUTSIZE],V[OUTSIZE],tp,koishi;
	int root,f[OUTSIZE],cnt;
	f2 AL=0.75;
	void pushup(int p) {
		siz[p]=siz[ls]+siz[rs]+ex[p];
		tot[p]=tot[ls]+tot[rs]+1;
	}
	int GG(int p) {
		return tot[p]*AL<max(tot[ls],tot[rs]);
	}
	int newnode(int v) {int p=++cnt; siz[p]=tot[p]=ex[p]=1; val[p]=v; return p;}
	void insert(int &p,int v,int fa) {
		if(!p) {p=newnode(v); f[p]=fa; return ;}
		insert(ch[p][v>val[p]],v,p);
		pushup(p); if(GG(p)) koishi=p;
	}
	void init() {
		insert(root,1,0); insert(root,2,0); insert(root,3,0);
		insert(root,4,0); insert(root,5,0);
	}
	#undef ls
	#undef rs
}
#undef N
#define N 100050
int n,head[N],to[N],nxt[N],cnt,m;
int fa[N],top[N],son[N],siz[N],dep[N],dfn[N];
int f[20][N],g[20][N],Lg[N];
int cmp1(int x,int y) {
	if(!x||!y) return x+y;
	return dfn[x]<dfn[y]?x:y;
}
int cmp2(int x,int y) {
	if(!x||!y) return x+y;
	return dfn[x]>dfn[y]?x:y;
}
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void df1(int x) {
	int i; siz[x]=1; dfn[x]=++dfn[0];
	for(i=head[x];i;i=nxt[i]) {
		dep[to[i]]=dep[x]+1;
		df1(to[i]); 
		siz[x]+=siz[to[i]];
		if(siz[to[i]]>siz[son[x]]) son[x]=to[i];
	}
}
void df2(int x,int t) {
	top[x]=t;
	if(son[x]) df2(son[x],t);
	int i;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=son[x]) df2(to[i],to[i]);
}
int lca(int x,int y) {
	if(!x||!y) return x+y;
	for(;top[x]!=top[y];y=fa[top[y]]) if(dep[top[x]]>dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int get_min(int l,int r) {
	if(l>r) return 0;
	int len=Lg[r-l+1];
	return cmp1(f[len][l],f[len][r-(1<<len)+1]);
}
int get_max(int l,int r) {
	if(l>r) return 0;
	int len=Lg[r-l+1];
	return cmp2(g[len][l],g[len][r-(1<<len)+1]);
}
int main() {
	Scape_Goat_Tree::init();
	SA::init();

	scanf("%d%d",&n,&m);
	int i,j;
	for(i=2;i<=n;i++) {
		scanf("%d",&fa[i]); add(fa[i],i);
	}
	df1(1); df2(1,1);
	Lg[0]=-1;
	for(i=1;i<=n;i++) Lg[i]=Lg[i>>1]+1;
	for(i=1;i<=n;i++) f[0][i]=g[0][i]=i;
	for(i=1;(1<<i)<=n;i++) {
		for(j=1;j<=n-(1<<i)+1;j++) {
			f[i][j]=cmp1(f[i-1][j],f[i-1][j+(1<<(i-1))]);
			g[i][j]=cmp2(g[i-1][j],g[i-1][j+(1<<(i-1))]);
		}
	}
	while(m--) {
		int l,r;
		scanf("%d%d",&l,&r);
		int x=get_min(l,r),y=get_max(l,r),ans1=0,ans2=0;
		int lx=get_min(l,x-1),rx=get_min(x+1,r);
		ans1=lca(cmp1(lx,rx),y);
		int ly=get_max(l,y-1),ry=get_max(y+1,r);
		ans2=lca(cmp2(ly,ry),x);

		if(dep[ans1]>dep[ans2]) {
			printf("%d %d\n",x,dep[ans1]);
		}else {
			printf("%d %d\n",y,dep[ans2]);
		}
	}

	return 0;
}