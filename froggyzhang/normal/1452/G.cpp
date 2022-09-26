#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,m,dis[N],p[N],ans[N],vis[N];
queue<int> q;
vector<int> G[N];
int g[N];
void dfs(int u,int z,int d){
	if(g[u]>=z-d)return;
	g[u]=z-d;
	ans[u]=max(ans[u],z);
	for(auto v:G[u]){
		dfs(v,z,d+1);
	}	
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(dis,0x3f,sizeof(dis));
	m=read();
	for(int i=1;i<=m;++i){
		int x=read();
		dis[x]=0;
		q.push(x);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			if(dis[v]==inf){
				q.push(v);
				dis[v]=dis[u]+1;
			}
		}
	}
	for(int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+n+1,[&](int i,int j){return dis[i]>dis[j];});
	for(int i=1;i<=n;++i){
		int u=p[i];
		dfs(u,dis[u],0);
	}
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}