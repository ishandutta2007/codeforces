#include<bits/stdc++.h>
using namespace std;
#define N 100100
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,m,a[N],ans[N],jb[N];
char dir[N],jbd[N];
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const char zyk[4]={'R','D','L','U'};
inline int ID(int x,int y){
	return (x-1)*m+y;	
}
inline int In(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;	
}
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N],pre[N];
	struct Edge{
		int nxt,to,val;
	}edge[N<<4];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void init(int _S,int _T){
		ecnt=1;
		S=_S,T=_T;
		fill(head+1,head+T+1,0);
	}
	queue<int> q;
	bool bfs(){
		fill(dep+1,dep+T+1,0);
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
		for(int &i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
			if(!limit)break;
		}
		if(!flow)dep[u]=inf;
		return flow;
	}
	int Dinic(){
		int maxflow=0;
		for(int i=1;i<=T;++i)pre[i]=head[i];
		while(bfs()){
			maxflow+=dfs(S,inf);
			for(int i=1;i<=T;++i)head[i]=pre[i];
		}
		return maxflow;
	}
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];ans[i]=jb[i]=0;
	}
	int S=n*m+1,T=n*m+2;
	int _S=T+1,_T=_S+1;
	Maxflow::init(_S,_T);
	int need=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int u=ID(i,j);
			for(int k=0;k<4;++k){
				int ni=i+d[k][0],nj=j+d[k][1];
				if(In(ni,nj)){
					int v=ID(ni,nj);
					if(a[u]==a[v]){
						if((i+j)&1)Maxflow::adde(u,v,1);
					}	
					else if(a[v]<a[u]){
						jb[u]=v,jbd[u]=zyk[k];
					}	
				}
			}
			if(jb[u]){
				(i+j)&1?Maxflow::adde(S,u,1):Maxflow::adde(u,T,1);
			}
			else{
				++need;
				(i+j)&1?(Maxflow::adde(S,_T,1),Maxflow::adde(_S,u,1)):(Maxflow::adde(u,_T,1),Maxflow::adde(_S,T,1));
			}
		}
	}
	Maxflow::adde(T,S,inf);
	if(Maxflow::Dinic()^need){
		cout<<"NO\n";
		return;
	}
	Maxflow::S=S,Maxflow::T=T;
	Maxflow::Dinic();
	cout<<"YES\n";
	for(int x=1;x<=n;++x){
		for(int y=1;y<=m;++y){
			int u=ID(x,y);
			for(int i=Maxflow::head[u];i;i=Maxflow::edge[i].nxt){
				int v=Maxflow::edge[i].to;
				if(v<=n*m&&((x+y)&1)^Maxflow::edge[i].val){
					for(int k=0;k<4;++k){
						int nx=x+d[k][0],ny=y+d[k][1];
						if(In(nx,ny)&&ID(nx,ny)==v){
							dir[u]=zyk[k],ans[u]=(a[u]+((x+y)&1))/2;
						}	
					}
				}	
			}
			if(!ans[u]){
				ans[u]=a[u]-a[jb[u]];
				dir[u]=jbd[u];
			}
		}
	}
	for(int i=1;i<=n*m;++i){
		cout<<ans[i]<<(i%m?' ':'\n');
	}
	for(int i=1;i<=n*m;++i){
		cout<<dir[i]<<(i%m?' ':'\n');
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}