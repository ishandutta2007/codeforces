#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=109,M=1005,inf=0x3f3f3f3f;
int dg[N],U[M],V[M],G[M];bool is[M];
struct edge{int v,nxt,w;}c[M*4];
int front[N],ec;
inline void addedge(int u,int v,int w){
	c[++ec]=(edge){v,front[u],w},front[u]=ec;
	c[++ec]=(edge){u,front[v],0},front[v]=ec;
}
int _q[N],_l,_r,S,T,dep[N],nc,cur[N];
bool bfs(){
	memset(dep,-1,(nc+3)<<2),memcpy(cur,front,(nc+3)<<2),_q[_l=_r=1]=S,dep[S]=0;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(int i=front[x];~i;i=c[i].nxt)if(c[i].w){
			int v=c[i].v;
			if(dep[v]==-1){
				dep[v]=dep[x]+1,_q[++_r]=v;
				if(v==T)return 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int flow){
	if(x==T||!flow)return flow;
	int f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt){
		int v=c[i].v;
		if(dep[v]==dep[x]+1&&(rf=dfs(v,std::min(flow,c[i].w)))){
			flow-=rf,f+=rf,c[i].w-=rf,c[i^1].w+=rf;
			if(!flow)return f;
		}
	}
	return f;
}
int dinic(){int ans=0;while(bfs())ans+=dfs(S,inf);return ans;}
int main(){
	memset(front,-1,sizeof(front)),ec=-1;
	int n,m,ss,tt;read(n,m,ss,tt),nc=n,S=ss,T=tt;
	for(int i=1;i<=m;++i)read(U[i],V[i],G[i]);
	for(int i=1;i<=m;++i){
		if(G[i])addedge(U[i],V[i],1),addedge(V[i],U[i],inf);
		else addedge(U[i],V[i],inf);
	}
	printf("%d\n",dinic());
	for(int i=1;i<=m;++i)is[i]=dep[U[i]]!=-1&&dep[V[i]]==-1;
	memset(front,-1,sizeof(front)),ec=-1,S=n+1,T=n+2;
	for(int i=1;i<=m;++i)if(G[i])addedge(U[i],V[i],inf),++dg[U[i]],--dg[V[i]];
	addedge(tt,ss,inf);for(int i=1;i<=n;++i)if(dg[i]>0)addedge(i,T,dg[i]);else addedge(S,i,-dg[i]);
	dinic();
	for(int i=1,cur=0;i<=m;++i){
		if(!G[i])printf("0 1\n");
		else{
			int w=c[cur^1].w+1;cur+=2;
			printf("%d %d\n",w,is[i]?w:w+1);
		}
	}
	return 0;
}