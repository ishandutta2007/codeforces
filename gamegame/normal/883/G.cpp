#include<iostream>
#include<vector>
using namespace std;
int n,m,s;
int mini,maxi;
int ans[300001],ans2[300001];
bool vis[300001],vis2[300001];
struct edge{
	int t,v,id,dir;
};
vector<edge>adj[300001];
void dfs(int id){
	vis[id]=true;
	maxi++;
	for(int i=0; i<adj[id].size() ;i++){
		edge cur=adj[id][i];
		if(cur.t==2){
			if(ans[cur.id]!=0) continue;
			ans[cur.id]=cur.dir;
			if(!vis[cur.v]) dfs(cur.v);
		}
		else{
			if(!vis[cur.v]) dfs(cur.v);
		}
	}
}
void dfs2(int id){
	vis2[id]=true;
	mini++;
	for(int i=0; i<adj[id].size() ;i++){
		edge cur=adj[id][i];
		if(cur.t==2){
			if(ans2[cur.id]!=0) continue;
			ans2[cur.id]=3-cur.dir;
		}
		else{
			if(!vis2[cur.v]) dfs2(cur.v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	int ptr=0;
	for(int i=1; i<=m ;i++){
		int t,u,v;
		cin >> t >> u >> v;
		if(t==2){
			ptr++;
			edge shit={t,v,ptr,1},fuck={t,u,ptr,2};
			adj[u].push_back(shit);
			adj[v].push_back(fuck);
		}
		else{
			edge shit={t,v,0,0};
			adj[u].push_back(shit);
		}
	}
	dfs(s);
	dfs2(s);
	cout << maxi << endl;
	for(int i=1; i<=ptr ;i++){
		if(ans[i]==1) cout << '+';
		else cout << '-';
	}
	cout << endl;
	cout << mini << endl;
	for(int i=1; i<=ptr ;i++){
		if(ans2[i]==1) cout << '+';
		else cout << '-';
	}
	cout << endl;
}