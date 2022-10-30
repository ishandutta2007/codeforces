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
#define N 600050
int n,m,K,head[N],to[N<<1],nxt[N<<1],val[N<<1],cnt=1,vis[N],kill[N],w[N],fa[N];
ll dis[N];
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
priority_queue<pair<ll,int> >q;
struct A {
	int x,id;
};
vector<A>V[N];
void dij() {
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(make_pair(0,1)) ;
	while(!q.empty()) {
		int x=q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		int i;
		for(i=head[x];i;i=nxt[i]) {
			if(dis[to[i]]+val[i]==dis[x]&&!fa[x]) {
				fa[x]=to[i];
				V[to[i]].push_back((A){x,i>>1});
			}
		}
		for(i=head[x];i;i=nxt[i]) {
            if(dis[to[i]]>dis[x]+val[i]) {
                dis[to[i]]=dis[x]+val[i];
                q.push(make_pair(-dis[to[i]],to[i]));
            }
        }
	}
}
int Q[N],l,r;
int du[N];
int main() {
	Scape_Goat_Tree::init();
	SA::init();
	scanf("%d%d%d",&n,&m,&K);
	if(K==0) {
		puts("0\n"); return 0;
	}
	int i,x,y,z,j;
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
	}
	dij();
	if(K>=n-1) {
		printf("%d\n",n-1);
		for(i=1;i<=n;i++) {
			int lim=V[i].size();
			for(j=0;j<lim;j++) printf("%d ",V[i][j].id);
		}
		return 0;
	}
	printf("%d\n",K);
	memset(head,0,sizeof(head)); cnt=0;
	for(i=1;i<=n;i++) {
		// printf("i=%d \n",i);
		int lim=V[i].size();
		for(j=0;j<lim;j++) {
			// printf("%d %d\n",V[i][j].x,V[i][j].id);
			add(V[i][j].x,i,V[i][j].id); du[i]++; w[ V[i][j].x ]=V[i][j].id; kill[V[i][j].id]=1;
		}
	}
	for(i=1;i<=n;i++) if(!du[i]) Q[r++]=i;
	int tot=0;
	while(l<r) {
		x=Q[l++];
		tot++;
		kill[w[x]]=0;
		if(tot==n-1-K) break;
		for(i=head[x];i;i=nxt[i]) {
			du[to[i]]--;
			if(!du[to[i]]) Q[r++]=to[i];
		}
	}
	for(i=1;i<=m;i++) if(kill[i]) printf("%d ",i);
}