/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 2e5+10;
int n,m,opt,u,v,cnt,dfs_time,head[MAXN],fa[MAXN],col[MAXN],rev[MAXN];
int top[MAXN],size[MAXN],dep[MAXN],son[MAXN],id[MAXN];
struct Edge{int to,next;}e[MAXN];
struct Node{int u,v;bool mjy;}tree[MAXN<<2];
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
inl void add(int u,int v){
	e[++cnt]=(Edge){v,head[u]},head[u]=cnt;
}
inl void dfs1(int u,int deep){
	dep[u]=deep,size[u]=1;
	travel(i,u){
		dfs1(e[i].to,deep+1);
		if(size[e[i].to]>size[son[u]]) son[u]=e[i].to;
		size[u]+=size[e[i].to];
	}
}
inl void dfs2(int u,int topfa){
	top[u]=topfa,id[u]=++dfs_time;
	if(son[u]) dfs2(son[u],topfa);
	travel(i,u) if(e[i].to!=son[u]) dfs2(e[i].to,e[i].to);
}
inl int lca(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}return dep[u]<dep[v]?u:v;
}
inl bool in(int u,int v){
	return id[v]>=id[u] && id[v]<=id[u]+size[u]-1;
}
inl bool check(int u,int v,int x,int y){
	int z=lca(u,v);
	return in(z,x) && in(z,y) && (in(x,u) || in(x,v)) && (in(y,u) || in(y,v));
}
inl Node Merge(Node x,Node y){
	if(x.u==-1 && x.v==-1 && x.mjy==false) return y;
	if(x.mjy==false || y.mjy==false) return (Node){2000,0724,false};
	if(check(x.u,x.v,y.u,y.v)) return (Node){x.u,x.v,true};
	else if(check(x.u,y.v,y.u,x.v)) return (Node){x.u,y.v,true};
	else if(check(y.u,y.v,x.u,x.v)) return (Node){y.u,y.v,true};
	else if(check(x.u,y.u,x.v,y.v)) return (Node){x.u,y.u,true};
	else if(check(x.v,y.v,x.u,y.u)) return (Node){x.v,y.v,true};
	else if(check(x.v,y.u,x.u,y.v)) return (Node){x.v,y.u,true};
	else return (Node){2000,0724,false};
}
inl void PushUp(int root){
	tree[root]=Merge(tree[lson],tree[rson]);
}
inl void build(int root,int l,int r){
	if(l==r) return tree[root]=(Node){rev[l],rev[l],true},void();
	build(lson,l,Mid),build(rson,Mid+1,r),PushUp(root);
}
inl void update(int root,int l,int r,int Pos){
	if(l==r) return tree[root]=(Node){rev[l],rev[l],true},void();
	Pos<=Mid?update(lson,l,Mid,Pos):update(rson,Mid+1,r,Pos);PushUp(root); 
}
inl int Query(Node all,int root,int l,int r){
	if(l==r) return l;
	Node tmp=Merge(all,tree[lson]);
	if(tmp.mjy) return Query(tmp,rson,Mid+1,r);
	else return Query(all,lson,l,Mid);
}
inl void init(){
	dfs1(1,1),dfs2(1,1),build(1,1,n);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(col[i]),col[i]++,rev[col[i]]=i;
	rep(i,2,n) read(fa[i]),add(fa[i],i); 
	init();
	for(read(m);m;m--){
		read(opt);
		if(opt==1) read(u),read(v),swap(rev[col[u]],rev[col[v]]),swap(col[u],col[v]),update(1,1,n,col[u]),update(1,1,n,col[v]);
		else printf("%d\n",tree[1].mjy?n:Query((Node){-1,-1,false},1,1,n)-1);
	}
	return 0;
}