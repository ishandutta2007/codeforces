#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Forn(i,x,y) for(int i=x;i>=y;i--)
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(t,V)   for(__typeof(*V.begin()) t:V)
using namespace std;
const int N=300005;
const int M=N*2;

struct edge{
	int u,v,w,pre;
}e[M];int dex,adj[N];
int n,m;
int dis[N],f[N],lab[N],dist[N];

void addedge(int x,int y,int z){
	e[++dex]=(edge){x,y,z,adj[x]};adj[x]=dex;
}

void dfs(int x){
	lab[x]=1;
	for(int i=adj[x];i;i=e[i].pre){
		int v=e[i].v,w=e[i].w;
		if(w==0 && !lab[v]) dfs(v);
	}
}

void bfs(){
	static int Q[N],l,r;
	static int vis[N];
	memset(Q,0,sizeof Q);
	memset(vis,0,sizeof vis);
	vis[Q[l=r=1]=1]=1;
	dis[1]=0;
	for(;l<=r;l++){
		int u=Q[l];
		for(int i=adj[u];i;i=e[i].pre){
			int v=e[i].v;
			if(vis[v])continue;
			vis[Q[++r]=v]=1;
			dis[v]=dis[u]+1;
		}
	}
}

set<int> s1,s2;
queue<int> Q;
int main(){
	
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);++x;++y;
		addedge(x,y,w);
		addedge(y,x,w);
	}
	dfs(n);
	bfs();
	
	
	Q.push(n);
	lab[n]=0;
	int len=1<<30;
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		len=min(len,dis[u]);
		s1.insert(u);
		for(int i=adj[u];i;i=e[i].pre){
			int v=e[i].v,w=e[i].w;
			if(lab[v] && w==0){
				Q.push(v);
				lab[v]=0;
				dist[v]=dist[u]+1;
				f[v]=u;
			}
		}
	}
	
	
	Forn(d,len-1,0){
		int Min=10;
		rep(u,s1){
			for(int i=adj[u];i;i=e[i].pre){
				int v=e[i].v,w=e[i].w;
				if(dis[v]==d) Min=min(Min,w);
			}
		}
		rep(u,s1){
			for(int i=adj[u];i;i=e[i].pre){
				int v=e[i].v,w=e[i].w;
				if(dis[v]==d&&w==Min){
					if(f[v]==0||dist[f[v]]>dist[u]){
						f[v]=u;
						dist[v]=dist[u]+1;
					}				
					s2.insert(v);
				}
			}
		}
		printf("%d",Min);
		s1=s2;
		s2.clear();
	}
	
	
	
	if(len==0) printf("0");
	vector<int> ans;
	int u=1;
	For(i,1,len){
		ans.push_back(u);
		u=f[u];
	}
	while(u^n){
		ans.push_back(u);
		u=f[u];
	}
	ans.push_back(n);
	puts("");
	printf("%d\n",(int)ans.size());
	rep(v,ans) printf("%d ",v-1);
	printf("\n");
	
	
	return 0;
}