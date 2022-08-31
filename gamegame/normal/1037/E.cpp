#include<iostream>
#include<set>
#include<queue>
using namespace std;
#define fi first
#define se second
int n,m,k;
set<pair<int,int> >s;
vector<pair<int,int> >adj[200001];
int deg[200001];
bool die[200001];
int ans[200001];
int u[200001],v[200001];
void yolo(int id){
	s.erase({deg[id],id});
	deg[id]--;
	s.insert({deg[id],id});
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=m ;i++){
		cin >> u[i] >> v[i];
		adj[u[i]].push_back({i,v[i]});
		adj[v[i]].push_back({i,u[i]});
		deg[u[i]]++;
		deg[v[i]]++;
	}
	for(int i=1; i<=n ;i++) s.insert({deg[i],i});
	for(int i=m; i>=1 ;i--){
		while(!s.empty() && s.begin()->fi<k){
			auto cur=*s.begin();
			s.erase(s.begin());
			die[cur.se]=true;
			for(auto newi:adj[cur.se]) if(!die[newi.se] && newi.fi<=i) yolo(newi.se);
		}
		ans[i]=s.size();
		if(!die[u[i]] && !die[v[i]]){
			yolo(u[i]);
			yolo(v[i]);
		}
	}
	for(int i=1; i<=m ;i++) cout << ans[i] << '\n';
}