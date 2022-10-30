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
	
// #define N 100005
// #define N 2050
// int a[N];
// int n;
// int p[N];
// int sp;
// int b[N];
// int K;
#define N 100050
int fa[N],n,m,need[N],is[N],aa[N];
int rtis[N],ans[N],K,head[N],to[N<<1],nxt[N<<1],val[N<<1],cnt;
int siz[N],mx;
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
struct E {
	int x,y,z;
	bool operator < (const E &u) const {
		return z<u.z;
	}
}a[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int x,int y) {
	int i; siz[x]=rtis[x];
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		dfs(to[i],x);
		siz[x]+=siz[to[i]];
		if(siz[to[i]]&&siz[to[i]]<K) mx=max(mx,val[i]);
	}
}
int main(){

	Scape_Goat_Tree::init();
	SA::init();

	int i;
	scanf("%d%d%d",&n,&m,&K);	
	for(i=1;i<=K;i++) {
		scanf("%d",&aa[i]); rtis[aa[i]]=1;
	}
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+m+1);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++) {
		int dx=find(a[i].x),dy=find(a[i].y);
		if(dx!=dy) {
			fa[dx]=dy; need[i]=1; add(a[i].x,a[i].y,a[i].z); add(a[i].y,a[i].x,a[i].z);
		}
	}
	dfs(1,0);
	for(i=1;i<=K;i++) printf("%d ",mx);
}