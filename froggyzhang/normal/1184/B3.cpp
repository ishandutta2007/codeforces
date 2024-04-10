#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 105
int n,m;
typedef pair<int,int> pii;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int dis[M][M],p[N],a[N],c[N],g[N];
vector<pii> t[N];
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to;
		ll val;
	}edge[N<<3];
	void add(int a,int b,ll c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,ll c){
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
	ll dfs(int u,ll limit){
		if(u==T)return limit;
		ll flow=0;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				ll k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
		}
		if(!flow)dep[u]=-1;
		return flow;
	}
	ll Dinic(){
		ll maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
		}
		return maxflow;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i){
		dis[i][i]=1;
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int n1,n2,o;
	cin>>n1>>n2>>o;
	for(int i=1;i<=n1;++i){
		cin>>p[i]>>a[i]>>g[i]>>c[i];	
	}
	for(int i=1;i<=n2;++i){
		int p,x,y;
		cin>>p>>x>>y;
		t[p].emplace_back(x,y);
	}
	for(int i=1;i<=n;++i){
		sort(t[i].begin(),t[i].end());
		for(int j=1;j<(int)t[i].size();++j){
			t[i][j].second=max(t[i][j].second,t[i][j-1].second);
		}	
	}
	ll tot=0;
	Maxflow::init(n1+1,n1+2);
	for(int i=1;i<=n1;++i){
		ll dm=-inf;
		for(int j=1;j<=n;++j){
			if(dis[p[i]][j]<=g[i]){
				int h=upper_bound(t[j].begin(),t[j].end(),make_pair(a[i]+1,-1))-t[j].begin()-1;
				if(h>=0){
					dm=max(dm,(ll)t[j][h].second-c[i]);	
				}
			}
		}
		if(dm>=0){
			tot+=dm;
			Maxflow::adde(Maxflow::S,i,dm);
		}
		else{
			Maxflow::adde(i,Maxflow::T,-dm);
		}
	}
	while(o--){
		int x,y;
		cin>>x>>y;
		Maxflow::adde(x,y,inf);
	}
	cout<<tot-Maxflow::Dinic()<<'\n';
	return 0;
}
//qwq