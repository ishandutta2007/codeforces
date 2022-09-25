#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,dis[N],ans[N];
bool ST[N],pl[N];
vector<int> G[N],c[N];
void Solve(int z){
	static int g[N];
	memset(g,0x3f,sizeof(g));
	queue<int> q;
	for(auto x:c[z])g[x]=0,q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			int w=max(0,dis[u]==dis[v]?g[u]+1:(dis[v]>dis[u]?g[u]-1:inf));
			if(w<g[v])g[v]=w,q.push(v);
		}
	}
	for(int i=1;i<=n;++i){
		if(!g[i])ans[i]=min(ans[i],z);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i){
		cin>>ST[i];
		if(ST[i])q.push(i),dis[i]=0;
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;q.push(v);
			}
		}
	}
	for(int u=1;u<=n;++u){
		for(auto v:G[u]){
			if(dis[u]==dis[v]){pl[u]=1;break;}
		}
		if(pl[u])c[dis[u]].push_back(u);
	}
	for(int i=1;i<=n;++i)ans[i]=dis[i];
	for(int i=0;i<=n;++i){
		if(!c[i].empty())Solve(i);
	}
	for(int i=1;i<=n;++i){
		cout<<2*dis[i]-ans[i]<<' ';
	}
	return 0;
}