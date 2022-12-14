#include<bits/stdc++.h>
using namespace std;const int N=2e5+7;
struct data{int to,next;}e[N<<1];int dis[2][N],head[N],cnt,n,m,K,t,w,q[N],i,j,a[N],len,mx=-N,ans;
void ins(int u,int v){e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;}
void insert(int u,int v){ins(u,v);ins(v,u);}
void bfs(int S,int d[N]){
	for(i=0;i<N;++i)d[i]=-1;d[S]=0;t=0;w=1;q[0]=S;
	while(t!=w){
		int x=q[t++];
		for(i=head[x];i;i=e[i].next)if(d[e[i].to]==-1)d[e[i].to]=d[x]+1,q[w++]=e[i].to;
	}
}
bool cmp(int x,int y){return dis[0][x]-dis[1][x]<dis[0][y]-dis[1][y];}
int main(){
	for(scanf("%d%d%d",&n,&m,&K),i=1;i<=K;++i)scanf("%d",a+i);
	for(i=1;i<=m;++i)scanf("%d%d",&t,&w),insert(t,w);bfs(1,dis[0]);bfs(n,dis[1]);len=dis[0][n];
	sort(a+1,a+K+1,cmp);for(i=K;i>=1;--i)ans=max(ans,dis[0][a[i]]+mx+1),mx=max(mx,dis[1][a[i]]);
	printf("%d\n",min(ans,len));
}