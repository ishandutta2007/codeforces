#include<bits/stdc++.h>
using namespace std;
#define N 123
typedef long long ll;
const int inf=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to,val;
	}edge[N*N<<1];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void init(int _S,int _T){
		ecnt=1;
		memset(head,0,sizeof(head));
		S=_S,T=_T;
	}
	queue<int> q;
	bool bfs(){
		memset(dep,0,sizeof(dep));
		q.push(S);
		dep[S]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&!dep[v]){
					dep[v]=dep[u]+1;
					q.push(v);
				}
			}
		}
		return dep[T]>0;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
		}
		if(!flow)dep[u]=inf;
		return flow;
	}
	int Dinic(){
		int maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
		}
		return maxflow;
	}
}
int n,m,K,t[N],a[N],tot;
int b[N],c[N],pre[N][N];
ll dp[N][N];
vector<int> ans;
void dfs(int u,int h){
	if(!u)return;
	dfs(u-1,h-pre[u][h]);
	for(int i=1;i<=pre[u][h];++i){
		ans.push_back(a[tot--]);
	}
	ans.push_back(0);
}
int main(){
	n=read(),m=read(),K=read();
	Maxflow::init(2*n+1,2*n+2);
	for(int i=1;i<=n;++i){
		Maxflow::adde(Maxflow::S,i,1);
		t[i]=Maxflow::ecnt;	
	}
	for(int i=1;i<=n;++i){
		Maxflow::adde(i+n,Maxflow::T,1);
		t[i+n]=Maxflow::ecnt;
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		Maxflow::adde(u,v+n,1);
	}
	int flow=Maxflow::Dinic();
	Maxflow::bfs();
	for(int i=1;i<=n;++i){
		if(!Maxflow::dep[i])a[++tot]=i;
	}
	for(int i=1;i<=n;++i){
		if(Maxflow::dep[i+n])a[++tot]=-i;
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[0][n-flow]=0;
	for(int i=1;i<=K;++i){
		b[i]=read(),c[i]=read();
	}
	for(int i=1;i<=K;++i){
		for(int j=i+1;j<=n;++j){
			for(int p=0;p<=j;++p){
				ll w=dp[i-1][j-p]+max(0LL,b[i]-1LL*c[i]*p);
				if(w>dp[i][j]){
					dp[i][j]=w;
					pre[i][j]=p;
				}	
			}
		}
	}
	ll mx=*max_element(dp[K]+1,dp[K]+n+1);
	for(int i=K+1;i<=n;++i){
		if(dp[K][i]==mx){
			dfs(K,i);
			printf("%d\n",(int)ans.size());
			for(auto x:ans){
				printf("%d ",x);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}