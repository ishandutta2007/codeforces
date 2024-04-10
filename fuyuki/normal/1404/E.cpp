#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define REP(u) for(int&i=cur[u],v;v=e[i].t,i;i=e[i].n)
const int N=205,M=1e6+1,INF=0x3f3f3f3f;
queue<int>q;
char a[N][N];
int n,m,tot,ans,S,T;
int h[M],cur[M],dis[M];
struct edge{int t,n,w;}e[M];
V input(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%s",a[i]+1);
}
V add_edge(int x,int y,int w){
	e[++tot]=(edge){y,h[x],w},h[x]=tot;
	e[++tot]=(edge){x,h[y],0},h[y]=tot;
}
V init(){
	vector<int>h,w;
	tot=1,S=(m+m+1)*n+m+1,T=S+1;
	FOR(i,1,n)FOR(j,1,m)if(a[i][j]=='#'){
		h.clear(),w.clear(),ans+=2;
		if(a[i+1][j]=='#')h.push_back((m+m+1)*i+j);
		if(a[i-1][j]=='#')h.push_back((m+m+1)*(i-1)+j);
		if(a[i][j-1]=='#')w.push_back((m+m+1)*(i-1)+j+m);
		if(a[i][j+1]=='#')w.push_back((m+m+1)*(i-1)+j+m+1);
		for(int x:h)add_edge(S,x,1),ans--;
		for(int x:w)add_edge(x,T,1),ans--;
		for(int u:h)for(int v:w)add_edge(u,v,2);
	}
}
I bfs(){
	memset(dis,0,T+1<<2),memcpy(cur,h,T+1<<2),q.push(S),dis[S]=1;
	for(int u;!q.empty();q.pop())rep(u=q.front())
		if(e[i].w&&!dis[v])dis[v]=dis[u]+1,q.push(v);
	return dis[T];
}
I dfs(int u,int res){
	if(!res||u==T)return res;
	int out=0,f;
	REP(u)if(dis[v]==dis[u]+1){
		f=dfs(v,min(e[i].w,res)),res-=f,out+=f,e[i].w-=f,e[i^1].w+=f;
		if(!res)return out;
	}
	return out;
}
V work(){
	while(bfs())ans+=dfs(S,INF);
	cout<<ans/2;
}
int main(){
	input();
	init();
	work();
	return 0;
}