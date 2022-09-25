#include<bits/stdc++.h>
using namespace std;
#define N 4010
const int inf=0x3f3f3f3f;
typedef long long ll;
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
	}edge[N<<3];
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
int n1,n2,m,d[N];
int main(){
	n1=read(),n2=read(),m=read();
	Maxflow::init(n1+n2+1,n1+n2+2);
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		Maxflow::adde(u,v+n1,1);
		++d[u],++d[n1+v];	
	}
	int mn=*min_element(d+1,d+n1+n2+1);
	printf("0\n");
	for(int t=1,ans=0;t<=mn;++t){
		for(int i=1;i<=n1;++i){
			Maxflow::adde(Maxflow::S,i,1);
		}
		for(int i=1;i<=n2;++i){
			Maxflow::adde(n1+i,Maxflow::T,1);
		}
		ans+=Maxflow::Dinic();
		printf("%d ",(n1+n2)*t-ans);
		static int cnt[N];
		for(int i=1;i<=n1+n2;++i)cnt[i]=0;
		for(int u=1;u<=n1;++u){
			for(int i=Maxflow::head[u];i;i=Maxflow::edge[i].nxt){
				int v=Maxflow::edge[i].to;
				if(v>n1&&v<=n1+n2&&!Maxflow::edge[i].val){
					++cnt[u],++cnt[v];
					printf("%d ",i>>1);	
				}
			}
		}
		for(int u=1;u<=n1;++u){
			for(int i=Maxflow::head[u];i;i=Maxflow::edge[i].nxt){
				int v=Maxflow::edge[i].to;
				if(v>n1&&v<=n1+n2&&cnt[u]<t&&Maxflow::edge[i].val){
					++cnt[u],++cnt[v];
					printf("%d ",i>>1);	
				}
			}
		}
		for(int u=n1+1;u<=n1+n2;++u){
			for(int i=Maxflow::head[u];i;i=Maxflow::edge[i].nxt){
				int v=Maxflow::edge[i].to;
				if(v>=1&&v<=n1&&cnt[u]<t&&!Maxflow::edge[i].val){
					++cnt[u],++cnt[v];
					printf("%d ",i>>1);	
				}
			}
		}
		printf("\n");
	}
	return 0;
}