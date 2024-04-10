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


#define N 300050
#define ls ch[p][0]
#define rs ch[p][1]
typedef long long ll;
int head[N],to[N<<1],nxt[N<<1],n,T;
ll ans[N],cov[N],C[N];
int dfn[N],dep[N],mx[N][2],ch[N][2],mn[N][2],root,now,son[N],cnt;
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
struct Point {
	int p[2];
	bool operator < (const Point &x) const {
		return p[now]==x.p[now]?p[!now]<x.p[!now]:p[now]<x.p[now];
	}
}a[N],b[N];
void pushup(int p,int x) {
	int i;
	for(i=0;i<2;i++) mx[p][i]=max(mx[p][i],mx[x][i]),mn[p][i]=min(mn[p][i],mn[x][i]);
}
int build(int l,int r,int type) {
	int mid=(l+r)>>1; now=type;
	nth_element(a+l,a+mid,a+r+1);
	int i;
	for(i=0;i<2;i++) mx[mid][i]=mn[mid][i]=a[mid].p[i];
	if(l<mid) ch[mid][0]=build(l,mid-1,!type),pushup(mid,ch[mid][0]);
	if(r>mid) ch[mid][1]=build(mid+1,r,!type),pushup(mid,ch[mid][1]);
	return mid;
}
bool judge(int t1,int t2,int t3,int t4) {
	return (t1<t3||t1>t4)&&(t2<t3||t2>t4);
}
void update(int x,int y,int z,int w,int p,int c) {
	if(mn[p][0]>=x&&mx[p][0]<=z&&mn[p][1]>=y&&mx[p][1]<=w) {cov[p]+=c; return ;}
	if(mx[p][0]<x||mn[p][0]>z||mx[p][1]<y||mn[p][1]>w) return ;
	if(a[p].p[0]>=x&&a[p].p[0]<=z&&a[p].p[1]>=y&&a[p].p[1]<=w) C[p]+=c;
	if(ls) update(x,y,z,w,ls,c);
	if(rs) update(x,y,z,w,rs,c);
}
ll query(int x) {
	int p=root;
	now=0;
	while(1) {
		if(b[x]<a[p]) p=ls;
		else if(a[p]<b[x]) p=rs;
		else return C[p];
		now=!now;
	}
}
void dfs(int x,int y) {
	int i;
	dfn[x]=++dfn[0];
	dep[x]=dep[y]+1;
	for(i=head[x];i;i=nxt[i]) {
		if(to[i]!=y) dfs(to[i],x);
	}
	son[x]=dfn[0];
}
void DFS(int p) {
	if(!p) return ;
	C[p]+=cov[p];
	cov[ls]+=cov[p];
	cov[rs]+=cov[p];
	DFS(ls); DFS(rs);
}
void solve() {
	int Q;
	n=rd();
	int i,x,y;
	for(i=2;i<=n;i++) {
		x=rd(); y=rd(); add(x,y); add(y,x);
	}
	Q=rd();
	dfs(1,0);
	for(i=1;i<=n;i++) a[i].p[0]=dfn[i],a[i].p[1]=dep[i],b[i]=a[i];
	root=build(1,n,0);
	int z;

	for(i=1;i<=Q;i++) {
		x=rd(); y=rd(); z=rd();
		update(dfn[x],dep[x],son[x],dep[x]+y,root,z);
	}
	DFS(root);
	for(i=1;i<=n;i++) printf("%lld ",query(i));
}
int main() {
	solve();
}