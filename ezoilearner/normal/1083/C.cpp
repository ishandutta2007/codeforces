#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e5+5;
struct Node{int p[2];}t[N<<2];
int n,x,q,tim,lg[N+N],val[N],pos[N],dep[N],L[N],R[N],anc[N+N][21];
vector<int>G[N];
template<typename T>inline void rd(T& x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
template<typename T,typename... Args>inline void rd(T& t, Args&... args){
    rd(t);rd(args...);
}
inline int cmp(int x,int y){return dep[x]<dep[y]?x:y;}
inline int lca(int x,int y){
	x=L[x],y=L[y];if(x>y)swap(x,y);int k=lg[y-x+1];
	return cmp(anc[x][k],anc[y-(1<<k)+1][k]);
}
inline bool in(int x,int y,int w){
	int z=lca(x,y);return lca(z,w)==z&&(lca(x,w)==w||lca(y,w)==w);
}
Node operator+(const Node&a,const Node&b){
	if(a.p[0]==-1||b.p[0]==-1)return(Node){-1,-1};
	if(!a.p[0]||!b.p[0])return(Node){a.p[0]+b.p[0],a.p[1]+b.p[1]};
	rep(i,0,1)rep(j,0,1)
		if(in(a.p[i],b.p[j],a.p[i^1])&&in(a.p[i],b.p[j],b.p[j^1]))
			return(Node){a.p[i],b.p[j]};
	if(in(a.p[0],a.p[1],b.p[0])&&in(a.p[0],a.p[1],b.p[1]))return a;
	if(in(b.p[0],b.p[1],a.p[0])&&in(b.p[0],b.p[1],a.p[1]))return b;
	return(Node){-1,-1};
}
inline void dfs(int x,int fa){
	anc[L[x]=++tim][0]=x,dep[x]=dep[fa]+1;
	for(auto y:G[x])if(y^fa)dfs(y,x),anc[++tim][0]=x;
	R[x]=tim;
}
inline void build(int x,int l,int r){
	if(l==r)return void(t[x].p[0]=t[x].p[1]=pos[l]);
	int mid=l+r>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
}
inline void update(int x,int l,int r,int y){
	if(l==r)return void(t[x].p[0]=t[x].p[1]=pos[l]);
	int mid=l+r>>1;
	y<=mid?update(x<<1,l,mid,y):update(x<<1|1,mid+1,r,y);
	t[x]=t[x<<1]+t[x<<1|1];
}
inline int query(int x,int l,int r,Node q){
	if(l==r)return l;
	int mid=l+r>>1;Node nxt=t[x<<1]+q;
	if(~nxt.p[0])return query(x<<1|1,mid+1,r,nxt);
	return query(x<<1,l,mid,q);
}
int main(){
	rd(n);
	rep(i,1,n)rd(val[i]),pos[val[i]]=i;
	rep(i,2,n)rd(x),G[x].eb(i);
	dfs(1,0);
	rep(i,2,tim)lg[i]=lg[i>>1]+1;
	rep(j,1,20)rep(i,1,tim-(1<<j)+1)anc[i][j]=cmp(anc[i][j-1],anc[i+(1<<j-1)][j-1]);
	build(1,0,n-1);
	for(rd(q);q--;){
		int type,x,y;rd(type);
		if(type==1){
			rd(x,y),swap(val[x],val[y]),swap(pos[val[x]],pos[val[y]]);
			update(1,0,n-1,val[x]),update(1,0,n-1,val[y]);
		}
		else{
			if(~t[1].p[0])printf("%d\n",n);
			else printf("%d\n",query(1,0,n-1,(Node){0,0}));
		}
	}
	return 0;
}