#include<iostream>
#include<vector>
using namespace std;
int n,m,k;
vector<int>adj[200001];
bool vis[200001];
int color[200001];
int par[200001];
int ans=1;
void dfs(int id){
	ans=max(ans,(int)adj[id].size()+1);
	vis[id]=true;
	int cur=1;
	for(int i=0; i<adj[id].size() ;i++){
		if(!vis[adj[id][i]]){
			while(cur==color[id] || cur==color[par[id]]) cur++;
			color[adj[id][i]]=cur;
			par[adj[id][i]]=id;
			dfs(adj[id][i]);
			cur++;
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    int x,y;
    color[1]=1;
    for(int i=1; i<n ;i++){
    	cin >> x >> y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
	}
	dfs(1);
	cout << ans << endl;
	for(int i=1; i<=n ;i++){
		cout << color[i] << ' ';
	}
	cout << endl;
}