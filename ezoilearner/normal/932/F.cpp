#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e5+5,W=2e5,BASE=1e5;
constexpr ll inf=0x7fffffffffffffffLL;
struct Line{int k;ll b;}rec[N];
struct Node{int ls,rs,s;}t[N<<2];
int n,tot,a[N],b[N],rt[N];ll dp[N];
vector<int>G[N];
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
inline ll calc(int id,int x){return(ll)rec[id].k*(x-BASE)+rec[id].b;}
inline void update(int &x,int l,int r,int y){
	if(!x)return void(t[x=y]=(Node){0,0,t[y].s});
	int mid=l+r>>1,&id=t[y].s;
	if(calc(id,mid)<calc(t[x].s,mid))swap(t[x].s,id);
	if(calc(id,l)<calc(t[x].s,l))update(t[x].ls,l,mid,y);
	else if(calc(id,r)<calc(t[x].s,r))update(t[x].rs,mid+1,r,y);
}
inline ll query(int x,int l,int r,int y){
	if(!x)return inf;
	int mid=l+r>>1;ll res=calc(t[x].s,y);if(l==r)return res;
	return min(res,y<=mid?query(t[x].ls,l,mid,y):query(t[x].rs,mid+1,r,y));
}
inline int merge(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	if(l==r)return calc(t[x].s,l)<calc(t[y].s,l)?x:y;
	int mid=l+r>>1;
	t[x].ls=merge(t[x].ls,t[y].ls,l,mid);
	t[x].rs=merge(t[x].rs,t[y].rs,mid+1,r);
	return update(x,l,r,y),x;
}
inline void dfs(int x,int fa){
	for(auto y:G[x])if(y^fa)
		dfs(y,x),rt[x]=merge(rt[x],rt[y],0,W);
	if(rt[x])dp[x]=query(rt[x],0,W,a[x]+BASE);
	rec[x]=(Line){b[x],dp[x]},t[++tot]=(Node){0,0,x};
	update(rt[x],0,W,tot);
}
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);
	rep(i,2,n){
		int u,v;rd(u),rd(v);
		G[u].eb(v),G[v].eb(u);
	}
	dfs(1,0);
	rep(i,1,n)printf("%I64d ",dp[i]);
	return 0;
}