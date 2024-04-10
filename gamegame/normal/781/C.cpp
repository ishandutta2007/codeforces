#include<iostream>
#include<vector>
using namespace std;
int n,m,k,p;
bool vis[200001];
vector<int>adj[200001];
vector<int>ans[200001];
int cur=1,moves=1,pos=1;
inline void dfs(int id){
	vis[id]=true;
	for(int i=0; i<adj[id].size() ;i++){
		if(vis[adj[id][i]]) continue;
		if(moves==p){
			cur++;
			moves=0;
		}
		moves++;
		pos=adj[id][i];
		ans[cur].push_back(adj[id][i]);
		dfs(adj[id][i]);
		if(moves==p){
			cur++;
			moves=0;
		}
		moves++;
		pos=id;
		ans[cur].push_back(pos);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	p=(2*n+k-1)/k;
	int x,y;
	for(int i=1; i<=m ;i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ans[1].push_back(1);
	dfs(1);
	for(int i=1; i<=k ;i++){
		cout << ans[i].size()+(ans[i].empty());
		for(int j=0; j<ans[i].size() ;j++) cout << ' ' << ans[i][j];
		if(ans[i].empty()){
			cout << " 1" << endl;
		}
		cout << endl;
	}
}