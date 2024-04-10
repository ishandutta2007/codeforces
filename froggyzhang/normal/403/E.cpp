#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,lg[N],dis[N*40],S;
bool vis[N*40];
vector<int> ans[N];
int head[N*40],ecnt;
struct Edge{
	int nxt,to,val;
}edge[N*84];
inline void adde(int a,int b,int c){
	edge[++ecnt]={head[a],b,c};
	head[a]=ecnt;
}
inline int ID(int x,int y){
	return x*n+y;	
}
class Tree{
	vector<int> G[N];
public:
	int f[N],ff[N][19],son[N],siz[N],dep[N],top[N];
	void dfs1(int u){
		siz[u]=1;
		ff[u][0]=f[u];
		for(int i=1;i<=18;++i){
			ff[u][i]=ff[ff[u][i-1]][i-1];
		}
		for(auto v:G[u]){
			if(v==f[u])continue;
			dep[v]=dep[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]){
				son[u]=v;
			}
		}	
	}
	void dfs2(int u,int topf){
		top[u]=topf;
		if(!son[u])return;
		dfs2(son[u],topf);
		for(auto v:G[u]){
			if(v==f[u]||v==son[u])continue;
			dfs2(v,v);
		}
	}
	inline int LCA(int u,int v){
		while(top[u]^top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			u=f[top[u]];
		}
		if(dep[u]>dep[v])swap(u,v);
		return u;
	}
	void init(int n){
		for(int i=2;i<=n;++i){
			cin>>f[i];
			G[f[i]].push_back(i);
		}
		dfs1(1);
		dfs2(1,1);	
	}
	int Jump(int u,int len){
		for(int i=0;i<=18;++i){
			if(len>>i&1)u=ff[u][i];
		}
		return u;	
	}
	void Add_edge(int u,int v,int op,int from){
		int lca=LCA(u,v);
		if(lca^u){
			int k=lg[dep[u]-dep[lca]];
			adde(ID(k+op,u),from,1);
			adde(ID(k+op,Jump(u,dep[u]-dep[lca]-(1<<k))),from,1);
		}
		if(lca^v){
			int k=lg[dep[v]-dep[lca]];
			adde(ID(k+op,v),from,1);
			adde(ID(k+op,Jump(v,dep[v]-dep[lca]-(1<<k))),from,1);	
		}
	}
}T1,T2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	T1.init(n);
	T2.init(n);
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=18;++j){
			if(T1.ff[i][j]){
				adde(ID(j-1,i),ID(j,i),0);
				adde(ID(j-1,T1.ff[i][j-1]),ID(j,i),0);
			}
			if(T2.ff[i][j]){
				adde(ID(j+19-1,i),ID(j+19,i),0);
				adde(ID(j+19-1,T2.ff[i][j-1]),ID(j+19,i),0);
			}
		}
		T2.Add_edge(i,T1.f[i],19,i);
		T1.Add_edge(i,T2.f[i],0,i+19*n);
	}
	cin>>S;
	++S;
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	queue<int> q;
	q.push(S);
	vis[S]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to,w=edge[i].val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v])q.push(v),vis[v]=1;
			}
		}
	}
	for(int i=2;i<=n;++i){
		if(dis[i]<inf)ans[dis[i]].push_back(i-1);
	}
	for(int i=2;i<=n;++i){
		if(dis[i+19*n]<inf)ans[dis[i+19*n]].push_back(i-1);
	}
	for(int i=0;;++i){
		if(ans[i].empty())break;
		cout<<(i&1?"Red\n":"Blue\n");
		for(auto x:ans[i]){
			cout<<x<<' ';
		}
		cout<<'\n';
	}
	return 0;
}