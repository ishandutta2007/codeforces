#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
int n,m,z;
stack<int>s;
vector<pair<int,int> >sand[N];
vector<int>adj[N],rev[N];
bool vis[N];
int scc[N];
bool need[N];
void add(int u,int v){
	//cout << "add " << u << ' ' << v << endl;
	adj[u].push_back(v);
	rev[v].push_back(u);
}
void dfs(int u){
	vis[u]=true;
	for(auto c:adj[u]){
		if(!vis[c]) dfs(c);
	}
	s.push(u);
}
void dfs2(int u,int rt){
	scc[u]=rt;
	for(auto c:rev[u]){
		if(scc[c]==0) dfs2(c,rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=n; i>=1 ;i--){
		for(int j=1; j<=m ;j++){
			char c;cin >> c;
			if(c=='#'){
				sand[j].push_back({i,++z});
				//cout << i << ' ' << j << ' ' << z << endl;
			}
		}
	}
	for(int j=1; j<=m ;j++) reverse(sand[j].begin(),sand[j].end());
	for(int j=1; j<=m ;j++){
		for(int k=0; k<sand[j].size() ;k++){
			if(k+1!=sand[j].size()){
				add(sand[j][k+1].se,sand[j][k].se);
			}
			if(k!=0 && sand[j][k-1].fi+1==sand[j][k].fi){
				add(sand[j][k-1].se,sand[j][k].se);
			}
			auto it=lower_bound(sand[j-1].begin(),sand[j-1].end(),pair<int,int>{sand[j][k].fi,0});
			if(it!=sand[j-1].end()) add(it->se,sand[j][k].se);
			it=lower_bound(sand[j+1].begin(),sand[j+1].end(),pair<int,int>{sand[j][k].fi,0});
			if(it!=sand[j+1].end()) add(it->se,sand[j][k].se);
		}
	}
	for(int i=1; i<=z ;i++){
		if(!vis[i]) dfs(i);
	}
	int ans=0;
	while(!s.empty()){
		int x=s.top();s.pop();
		if(scc[x]) continue;
		dfs2(x,x);need[x]=true;ans++;
	}
	for(int i=1; i<=z ;i++){
		for(auto u:rev[i]){
			if(scc[u]==scc[i]) continue;
			if(need[scc[i]]){
				need[scc[i]]=false;
				ans--;
			}
		}
	}
	cout << ans << endl;
}