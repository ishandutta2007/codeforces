#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)	
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,inf=0x3f3f3f3f;
struct edge{int v,nxt,w;}c[N*120];
int front[N],ec;
inline void addedge(int u,int v,int w){
	c[++ec]=(edge){v,front[u],w},front[u]=ec;
	c[++ec]=(edge){u,front[v],0},front[v]=ec;
}
int cur[N],_q[N],_l,_r,S,T,nc,dep[N];
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
int dinic(){
	int ans=0;while(bfs())ans+=dfs(S,inf);
	return ans;
}
int id[N],a[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]),id[a[i]]=i;
	S=4*n+1,T=S+1,nc=T,ec=-1,memset(front,-1,(nc+3)<<2);
	for(int i=1;i<=2*n;++i)addedge(S,i+2*n,1),addedge(i,T,1);
	for(int i=1;i<=n;++i)addedge(i+2*n,i+n,1);
	for(int i=1;i<=n;++i)for(int j=a[i]*2;j<=5e4;j+=a[i])if(id[j])addedge(id[j]+2*n,i,1),addedge(id[j]+3*n,i+n,1),addedge(id[j]+2*n,i+n,1);
	printf("%d\n",dinic()-n);
	for(int i=1;i<=n;++i)id[a[i]]=0;
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}