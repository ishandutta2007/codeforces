#include<bits/stdc++.h>
using namespace std;
#define N 400010
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,k,m,Q,dis[N],bel[N],f[N],ff[N][20],dep[N];
vector<int> G[N];
class Union_Set{
public:
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
	}
}S;
void dfs(int u){
	ff[u][0]=f[u];
	dep[u]=dep[f[u]]+1;
	for(int i=1;i<=19;++i){
		ff[u][i]=ff[ff[u][i-1]][i-1];
	}
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs(v);	
	}
}
inline int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;--i){
		if(dep[ff[u][i]]>=dep[v])u=ff[u][i];
	}
	if(u==v)return u;
	for(int i=19;i>=0;--i){
		if(ff[u][i]^ff[v][i])u=ff[u][i],v=ff[v][i];
	}
	return f[u];
}
inline int Jump(int u,int k){
	for(int i=0;i<=19;++i){
		if(k>>i&1)u=ff[u][i];
	}
	return u;
}
bool Query(int u,int v){
	int lca=LCA(u,v);
	int dis=dep[u]+dep[v]-2*dep[lca];
	if(dis<=2*k)return true;
	int _u=dep[u]-dep[lca]>=k?Jump(u,k):Jump(v,dis-k);
	int _v=dep[v]-dep[lca]>=k?Jump(v,k):Jump(u,dis-k);
	return S.getf(_u)==S.getf(_v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>m;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(n+i);
		G[n+i].push_back(u);
		G[v].push_back(n+i);
		G[n+i].push_back(v);
	}
	S.init(2*n-1);
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		q.push(x);
		dis[x]=0;
		bel[x]=x;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(dis[u]==k)continue;
		for(auto v:G[u]){
			if(bel[v]){
				S.Merge(u,v);
			}
			else{
				bel[v]=bel[u];
				dis[v]=dis[u]+1;
				q.push(v);
				S.Merge(u,v);
			}	
		}
	}
	dfs(1);
	cin>>Q;
	while(Q--){
		int u,v;
		cin>>u>>v;
		cout<<(Query(u,v)?"YES\n":"NO\n");
	}
	return 0;
}