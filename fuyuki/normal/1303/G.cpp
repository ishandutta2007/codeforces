#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int v:e[u])if(!vis[v])
const int N=15e4+1;
ll ans;
vector<int>e[N];
int n,tot,rt,sum;
int a[N],siz[N],val[N],vis[N];
struct node{ll k,b;ll val(int x){return k*x+b;}}t[N<<2];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V input(){
	scanf("%d",&n);int x,y;
	FOR(i,2,n)scanf("%d%d",&x,&y),add_edge(x,y);
	FOR(i,1,n)scanf("%d",a+i);ans=a[1];
}
V getrt(int u,int fa){
	siz[u]=1,val[u]=0;
	REP(u)if(v^fa)getrt(v,u),siz[u]+=siz[v],val[u]=max(val[u],siz[v]);
	if((val[u]=max(val[u],sum-siz[u]))<=val[rt])rt=u;
}
V getsiz(int u,int fa){siz[u]=1;REP(u)if(v^fa)getsiz(v,u),siz[u]+=siz[v];}
#define lc p<<1
#define rc lc|1
#define root 1,1,sum
#define lson lc,L,mid
#define rson rc,mid+1,R
ll ask(int p,int L,int R,int x){
	if(L==R)return t[p].val(x);
	int mid=L+R>>1;
	if(x>mid)return max(ask(rson,x),t[p].val(x));
	else return max(ask(lson,x),t[p].val(x));
}
V getans(int u,int fa,int l,ll w,ll s){
	ans=max(ans,ask(root,l)+(w+=(s+=a[u])));
	REP(u)if(v^fa)getans(v,u,l+1,w,s);
}
V ins(int p,int L,int R,node x){
	int mid=L+R>>1;
	if(t[p].val(mid)<x.val(mid))swap(x,t[p]);
	if(t[p].val(L)<x.val(L))ins(lson,x);
	if(t[p].val(R)<x.val(R))ins(rson,x);
}
V insert(int u,int fa,int l,ll w,ll s){
	ins(root,(node){s+=a[u],w+=1ll*l*a[u]}),ans=max(ans,w);
	REP(u)if(v^fa)insert(v,u,l+1,w,s);
}
V clean(int p,int L,int R){
	t[p].k=t[p].b=0;
	if(L==R)return;int mid=L+R>>1;
	clean(lson),clean(rson);
}
V once(int u){
	clean(root),ins(root,(node){a[u],a[u]});
	REP(u)getans(v,u,1,0,0),insert(v,u,2,a[u],a[u]);
}
V dfs(int u){
	vis[u]=1,once(u),reverse(e[u].begin(),e[u].end()),once(u);
	REP(u)getsiz(v,u),sum=siz[v],rt=0,getrt(v,u),dfs(rt);
}
V work(){val[0]=N,sum=n,getrt(1,0),dfs(rt),cout<<ans<<'\n';}
int main(){
	input();
	work();
	return 0;
}