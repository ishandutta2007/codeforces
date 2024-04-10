#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100050
#define M 500050
#define leaf(x) (x&&(!ls[x])&&(!rs[x]))
int ch[N][26],fa[N],lst=1,cnt=1,len[N];
int f[20][N],m,root[N],L[M],Lp[M],n;
int ls[N*23],rs[N*23],TOT,Q;
int head[N],to[N],nxt[N],CNT,ans1[M],ans2[M];
char s[M],t[N];
vector<int>V[N];
inline void add(int u,int v) {
	to[++CNT]=v; nxt[CNT]=head[u]; head[u]=CNT;
}
void insert(int x) {
	int p=lst,np=++cnt;
	len[np]=len[p]+1;
	for(;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if(!p) fa[np]=1;
	else {
		int q=ch[p][x];
		if(len[q]==len[p]+1) fa[np]=q;
		else {
			int nq=++cnt;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; len[nq]=len[p]+1;
			fa[np]=fa[q]=nq;
			for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}
	lst=np;
}
struct A {
	int x,v;
	A() {}
	A(int x_,int v_) {x=x_,v=v_;}
	A operator + (const A &u) const {
		A re;
		if(v>u.v||(v==u.v&&x<u.x)) re=*this;
		else re=u;
		return re;
	}
}tr[N*23];
struct B {
	int l,r,pl,pr;
}qw[M];
void update(int l,int r,int x,int &p) {
	if(!p) p=++TOT;
	if(l==r) {
		tr[p].v++; tr[p].x=l; return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(l,mid,x,ls[p]);
	else update(mid+1,r,x,rs[p]);
	tr[p]=tr[ls[p]]+tr[rs[p]];
}
int merge(int x,int y) {
	if(!x||!y) return x+y;
	if(leaf(x)) {
		tr[x].v+=tr[y].v; return x;
	}
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	tr[x]=tr[ls[x]]+tr[rs[x]];
	return x;
}
A query(int l,int r,int x,int y,int p) {
	if(x<=l&&y>=r) return tr[p];
	int mid=(l+r)>>1;
	if(y<=mid) return query(l,mid,x,y,ls[p]);
	else if(x>mid) return query(mid+1,r,x,y,rs[p]);
	else return query(l,mid,x,y,ls[p])+query(mid+1,r,x,y,rs[p]);
}
void dfs(int x) {
	int i;
	for(i=head[x];i;i=nxt[i]) {
		dfs(to[i]);
		root[x]=merge(root[x],root[to[i]]);
	}
	int lim=V[x].size();
	for(i=0;i<lim;i++) {
		int l=qw[V[x][i]].l,r=qw[V[x][i]].r;
		A ans=query(1,m,l,r,root[x]);
		ans1[V[x][i]]=ans.x;
		ans2[V[x][i]]=ans.v;
	}
}
int main() {
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	int i,j;
	for(i=1;i<=m;i++) {
		lst=1;
		scanf("%s",t+1);
		int k=strlen(t+1);
		for(j=1;j<=k;j++) {
			insert(t[j]-'a');
			update(1,m,i,root[lst]);
		}
	}
	// printf("%d\n",cnt);
	for(i=2;i<=cnt;i++) add(fa[i],i),f[0][i]=fa[i];
	for(i=1;(1<<i)<=cnt;i++) {
		for(j=1;j<=cnt;j++) f[i][j]=f[i-1][f[i-1][j]];
	}
	int p=1,lth=0;
	for(i=1;i<=n;i++) {
		int x=s[i]-'a';
		if(ch[p][x]) lth++,p=ch[p][x];
		else {
			for(;p&&!ch[p][x];p=fa[p]);
			if(p) lth=len[p]+1,p=ch[p][x];
			else lth=0,p=1;
		}
		L[i]=lth;
		Lp[i]=p;
	}
	scanf("%d",&Q);
	for(i=1;i<=Q;i++) {
		scanf("%d%d%d%d",&qw[i].l,&qw[i].r,&qw[i].pl,&qw[i].pr);
		int l=qw[i].pl, r=qw[i].pr;
		if(L[r]<r-l+1) continue;
		int x=Lp[r];
		for(j=18;j>=0;j--) {
			if(f[j][x]&&len[f[j][x]]>=r-l+1) x=f[j][x];
		}
		V[x].push_back(i);
	}
	dfs(1);
	for(i=1;i<=Q;i++) printf("%d %d\n",ans2[i]?ans1[i]:qw[i].l,ans2[i]);
}
/*
suffixtree
2
suffixtree
treetree
1
1 2 1 10
*/