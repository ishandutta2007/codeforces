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
#include <set>
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


#define N 200050
#define mod 998244353
int n;
vector<int>V[N];
int head[N],to[N<<1],nxt[N<<1],cnt;
int pri[N],pri_cnt,vis[N],idx[N];
int fa[N],dep[N],top[N],son[N],siz[N];
int S[N],a[N],la,tp,dfn[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void df1(int x,int y) {
    int i; siz[x]=1; fa[x]=y; dep[x]=dep[y]+1; 
    dfn[x]=++dfn[0];
    for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
        df1(to[i],x); siz[x]+=siz[to[i]];
        if(siz[to[i]]>siz[son[x]]) son[x]=to[i];
    }
}
void df2(int x,int t) {
    top[x]=t;
    if(son[x]) df2(son[x],t);
    int i;
    for(i=head[x];i;i=nxt[i]) if(to[i]!=fa[x]&&to[i]!=son[x]) df2(to[i],to[i]);
}
int lca(int x,int y) {
    for(;top[x]!=top[y];y=fa[top[y]]) if(dep[top[x]]>dep[top[y]]) swap(x,y);
    return dep[x]<dep[y]?x:y;
}
inline bool cmp(const int &x,const int &y) {return dfn[x]<dfn[y];}
void sieve() {
	int i,j;
	for(i=2;i<N;i++) {
		if(!vis[i]) {
			pri[++pri_cnt]=i;
		}
		for(j=1;j<=pri_cnt&&i*pri[j]<N;j++) {
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
	for(i=1;i<=pri_cnt;i++) idx[pri[i]]=i;
}
void insert(int x,int id) {
	int i;
	for(i=1;i<=pri_cnt&&pri[i]*pri[i]<=x;i++) {
		if(x%pri[i]==0) {
			V[i].push_back(id);
			while(x%pri[i]==0) x/=pri[i];
		}
	}
	if(x!=1) {
		V[idx[x]].push_back(id);
	}
}
int f[N],ans;
void df3(int x) {
	int i;
	if(vis[x]) f[x]=1,ans=max(ans,1);
	else f[x]=0;
	for(i=head[x];i;i=nxt[i]) {
		df3(to[i]);
		if(vis[x]&&vis[to[i]]) {
			if(dep[to[i]]==dep[x]+1) {
				ans=max(ans,f[x]+f[to[i]]);
				f[x]=max(f[x],f[to[i]]+1);
			}
		}
	}
	head[x]=0;
}
void build() {
	int i; cnt=0;
	for(i=1;i<=la;i++) vis[a[i]]=1;
	sort(a+1,a+la+1,cmp);
    S[tp=1]=1;
    for(i=1;i<=la;i++) {
        int x=a[i],y=lca(x,S[tp]);
        while(dep[y]<dep[S[tp]]) {
            if(dep[y]>=dep[S[tp-1]]) {
                add(y,S[tp]); tp--;
                if(S[tp]!=y) S[++tp]=y;
                break;
            }
            add(S[tp-1],S[tp]); tp--;
        }
        if(S[tp]!=x) S[++tp]=x;
    }
    while(tp>1) add(S[tp-1],S[tp]),tp--;
	df3(1);
	for(i=1;i<=la;i++) vis[a[i]]=0;
}
int main() {

	Scape_Goat_Tree::init();
	SA::init();
	
	sieve();

	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),insert(a[i],i);
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y); add(x,y); add(y,x);
	}
	df1(1,0); df2(1,0);
	memset(head,0,sizeof(head)); cnt=0;
	memset(vis,0,sizeof(vis));
	int j;
	ans=0;
	for(i=1;i<=pri_cnt;i++) {
		int lim=V[i].size();
		if(ans>=lim) continue;
		la=0;
		for(j=0;j<lim;j++) {
			a[++la]=V[i][j];
		}
		build();
	}
	printf("%d\n",ans);

	return 0;
}