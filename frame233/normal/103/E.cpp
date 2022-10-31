#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=605;typedef long long ll;
const ll A=0x3f3f3f3f,B=1e18;
struct edge{int v,nxt;ll w;}c[N*N];
int front[N],ec=-1;
inline void addedge(int u,int v,ll w){
	c[++ec]=(edge){v,front[u],w},front[u]=ec;
	c[++ec]=(edge){u,front[v],0},front[v]=ec;
}
int _q[N],_l,_r,S,T,nc,cur[N],dep[N];
bool bfs(){
	memcpy(cur,front,(nc+3)<<2),memset(dep,-1,(nc+3)<<2),_q[_l=_r=1]=S,dep[S]=0;
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
		if(dep[v]==dep[x]+1&&(rf=dfs(v,std::min(c[i].w,flow)))){
			flow-=rf,f+=rf,c[i].w-=rf,c[i^1].w+=rf;
			if(!flow)return f;
		}
	}
	return f;
}
ll dinic(){ll ans=0;while(bfs())ans+=dfs(S,B);return ans;}
int main(){
	memset(front,-1,sizeof(front));int n;read(n);
	S=n*2+1,T=n*2+2,nc=T;
	for(int i=1;i<=n;++i){
		int k;read(k);
		for(int j=1,x;j<=k;++j)read(x),addedge(i,x+n,B);
	}
	ll ans=0;for(int i=1;i<=n;++i)addedge(i+n,T,A);
	for(int i=1,x;i<=n;++i)read(x),x*=-1,addedge(S,i,A+x),ans+=A+x;
	printf("%lld\n",dinic()-ans);
	return 0;
}