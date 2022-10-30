#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef std::pair<int,int> pi;
typedef long long ll;
const int N=2005;
const ll INF=1e18;
struct edge{int v,nxt;ll w;}c[N<<4];
int front[N],ec=-1;
inline void addedge(int u,int v,ll w){
	if(u==-1||v==-1)return;
	c[++ec]=(edge){v,front[u],w},front[u]=ec;
	c[++ec]=(edge){u,front[v],0},front[v]=ec;
}
int _q[N],_l,_r,cur[N],dep[N],S,T,nc;
bool bfs(){
	memset(dep,-1,(nc+3)<<2),memcpy(cur,front,(nc+3)<<2),_q[_l=_r=1]=S,dep[S]=0;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(int i=cur[x];~i;i=c[i].nxt)if(c[i].w){
			int v=c[i].v;
			if(dep[v]==-1)dep[v]=dep[x]+1,_q[++_r]=v;
		}
	}
	return ~dep[T];
}
ll dfs(int x,ll flow){
	if(x==T||!flow)return flow;
	ll f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt)if(c[i].w){
		int v=c[i].v;
		if(dep[v]==dep[x]+1&&(rf=dfs(v,std::min(flow,c[i].w)))){
			flow-=rf,f+=rf;
			c[i].w-=rf,c[i^1].w+=rf;
			if(!flow)return f;
		}
	}
	return f;
}
ll dinic(){
	ll ans=0;
	while(bfs())ans+=dfs(S,INF);
	return ans;
}
int X[N],Y[N],W[N],n;
struct node{
	int x,y,id;
	inline bool operator < (const node &o)const{return x==o.x?y<o.y:x<o.x;}
}t[N];
inline int getid(int x,int y){
	int id=std::lower_bound(t+1,t+n+1,(node){x,y,0})-t;
	return id==n+1||t[id].x!=x||t[id].y!=y?-1:t[id].id;
}
int main(){
	memset(front,-1,sizeof(front));
	read(n);
	ll all=0;
	for(int i=1;i<=n;++i)read(X[i],Y[i],W[i]),t[i]={X[i],Y[i],i},all+=W[i];
	std::sort(t+1,t+n+1);
	S=n+n+1,T=S+1,nc=T;
	for(int i=1;i<=n;++i){
		int x=X[i],y=Y[i];
		addedge(i,i+n,W[i]);
		if(x%2&&y%2==0)addedge(i+n,getid(x-1,y),INF),addedge(i+n,getid(x+1,y),INF),addedge(S,i,INF);
		else if(x%2==0&&y%2==0)addedge(i+n,getid(x,y-1),INF),addedge(i+n,getid(x,y+1),INF);
		else if(x%2==0&&y%2)addedge(i+n,getid(x+1,y),INF),addedge(i+n,getid(x-1,y),INF);
		else if(x%2&&y%2)addedge(i+n,T,INF);
	}
	printf("%lld\n",all-dinic());
	return 0;
}