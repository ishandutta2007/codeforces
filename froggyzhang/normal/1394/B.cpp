#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
inline int read(){
	int x=0,f=1;
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
int n,m,k,ans,a[N],vis[10][10];
vector<pair<int,int> > G[N],p[N];
int ban[10][10][10][10];
void dfs(int u){
	if(u==k+1){
		++ans;
		return;
	}
	for(int i=1;i<=u;++i){
		a[u]=i;
		bool ok=true;
		for(int v=1;v<=u;++v){
			if(ban[v][a[v]][u][a[u]]){
				ok=false;
				break;
			}
		}
		if(ok)dfs(u+1);
	}
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[u].push_back(make_pair(w,v));
		//cerr<<" !! "<<u<<" "<<v
	}
	for(int i=1;i<=n;++i){
		//cerr<<" .. "<<G[i].size()<<endl;
		sort(G[i].begin(),G[i].end());
	}
	for(int u=1;u<=n;++u){
		int d=G[u].size();
		if(!d){
			return !printf("0\n");
		}
		//cerr<<" du: "<<u<<" "<<d<<endl;
		for(int i=0;i<d;++i){
			int v=G[u][i].second;
			p[v].emplace_back(d,i+1);
			//cerr<<" ! "<<u<<" "<<v<<" "<<d<<" "<<i+1<<endl;
		}
	}
	for(int u=1;u<=n;++u){
		sort(p[u].begin(),p[u].end());
		for(int i=1;i<=k;++i){
			for(int j=1;j<=k;++j){
				vis[i][j]=0;
			}
		}
		for(auto x:p[u]){
			if(vis[x.first][x.second]){
				ban[x.first][x.second][x.first][x.second]=1;
			}
			vis[x.first][x.second]=1;
		}
		p[u].erase(unique(p[u].begin(),p[u].end()),p[u].end());
		if(p[u].empty())return !printf("0\n");
		for(int i=0;i<(int)p[u].size();++i){
			for(int j=i+1;j<(int)p[u].size();++j){	
				//cerr<<" "<<i<<" "<<j<<" "<<u<<" "<<p[u][i].first<<" "<<p[u][i].second<<" "<<p[u][j].first<<" "<<p[u][j].second<<endl;
				ban[p[u][i].first][p[u][i].second][p[u][j].first][p[u][j].second]=1;
			}
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}