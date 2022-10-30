#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=1009;typedef long long ll;const ll inf=1e18;
struct edge{int v,nxt;ll w;}c[N<<3];
int front[N],ec,a[N],b[N],id[N];
inline void addedge(int u,int v,ll w){
	c[++ec]=(edge){v,front[u],w},front[u]=ec;
	c[++ec]=(edge){u,front[v],0},front[v]=ec;
}
int cur[N],dep[N],_q[N],_l,_r,S,T,nc;
bool bfs(){
	memcpy(cur,front,(nc+3)<<2),memset(dep,-1,(nc+3)<<2),dep[S]=0,_q[_l=_r=1]=S;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(int i=cur[x];~i;i=c[i].nxt)if(c[i].w){
			int v=c[i].v;
			if(dep[v]==-1){
				dep[v]=dep[x]+1,_q[++_r]=v;
				if(v==T)return 1;
			}
		}
	}
	return 0;
}
ll dfs(int x,ll flow){
	if(x==T||!flow)return flow;
	ll f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt){
		int v=c[i].v;
		if(dep[v]==dep[x]+1&&(rf=dfs(v,std::min(flow,c[i].w)))){
			flow-=rf,f+=rf,c[i].w-=rf,c[i^1].w+=rf;
			if(!flow)return f;
		}
	}
	return f;
}
ll dinic(){
	ll ans=0;while(bfs())ans+=dfs(S,inf);
	return ans;
}
int ask(int x,int y){return abs(y-a[x]);}
std::vector<int> e[N];
void solve(const std::vector<int> &V,int L,int R){
	if(V.empty())return;
	if(L==R){
		for(auto x:V)b[x]=L;
		return;
	}
	int mid=(L+R)>>1,cnt=0;
	ec=-1,S=SZ(V)+1,T=S+1,nc=T;for(int i=1;i<=nc;++i)front[i]=-1;
	for(auto x:V){
		id[x]=++cnt;int w0=ask(x,mid),w1=ask(x,mid+1),tmp=w1-w0;tmp*=-1;
		if(tmp>0)addedge(S,id[x],tmp);else addedge(id[x],T,-tmp);
	}
	for(auto x:V)for(auto v:e[x])if(id[v])addedge(id[x],id[v],inf);
	dinic();std::vector<int> v1,v2;T=-1,bfs();
	for(auto x:V)(dep[id[x]]==-1?v1:v2).pb(x);
	for(auto x:V)id[x]=-1;
	solve(v1,L,mid),solve(v2,mid+1,R);
}
int main(){
	int n,m;read(n,m);for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<=m;++i)read(x,y),e[x].pb(y);
	std::vector<int> v(n);std::iota(v.begin(),v.end(),1);solve(v,1,1e9);
	for(int i=1;i<=n;++i)printf("%d%c",b[i]," \n"[i==n]);
	return 0;
}