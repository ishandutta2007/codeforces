#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int B=5e7;
typedef long long ll;
#define N 6133
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
	}edge[N<<2];
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
int n,m,val[N];
inline int ID(int x,int y){
	return (x-1)*(n+1)+y+1;
}
int main(){
	n=read(),m=read();
	Maxflow::init(n*n*n+123,n*n*n+124);
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		val[u]+=w,val[v]-=w;
		for(int j=0;j<n;++j){
			Maxflow::adde(ID(v,j),ID(u,j+1),inf);	
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<n;++j){
			Maxflow::adde(ID(i,j),ID(i,j+1),val[i]*j+B);	
		}	
	}
	for(int i=1;i<=n;++i){
		Maxflow::adde(Maxflow::S,ID(i,0),inf);
		Maxflow::adde(ID(i,n),Maxflow::T,inf);
	}
	Maxflow::Dinic();
	Maxflow::bfs();
	for(int i=1;i<=n;++i){
		for(int j=n;j>=0;--j){
			if(Maxflow::dep[ID(i,j)]){
				printf("%d ",j);
				break;
			}
		}	
	}
	return 0;
}