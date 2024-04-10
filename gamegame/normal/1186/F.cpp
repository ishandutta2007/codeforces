#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,m;
vector<pair<int,int> >adj[4000001];
bool e[4000001];
vector<int>v;
vector<int>ax,ay;
bool vis[4000001];
void dfs(int id){
	vis[id]=true;
	
	while(!adj[id].empty()){
		auto cur=adj[id].back();
		if(!e[cur.fi]){
			e[cur.fi]=true;
			adj[id].pop_back();
			dfs(cur.se);
		}
		else adj[id].pop_back();
	}
	v.push_back(id);
}
void in(int& x){
	x=0;
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
int sz;
int w[4000001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	in(n);in(m);
	v.reserve(5000000);
	if(n==1){
		cout << "0\n";
		return 0;
	}
	for(int i=1; i<=m ;i++){
		int u,v;in(u);in(v);
		adj[u].push_back({i,v});
		adj[v].push_back({i,u});
	}
	for(int i=1; i<=n ;i++){
		if(adj[i].size()%2==1){
			adj[0].push_back({m+i,i});
			adj[i].push_back({m+i,0});
		}
	}
	/*if(adj[0].empty()){
		dfs(1);
		cout << (v.size()+1)/2 << '\n';
		for(int i=0; i<(int)v.size()-2; i+=2){
			cout << v[i] << ' ' << v[i+1] << '\n';
		}
		cout << v[v.size()-2] << ' ' << v.back() << '\n';
	}*/
	if(true){
		dfs(0);
		for(int i=1; i<=n ;i++){
			if(!vis[i]){
				v.push_back(0);
				dfs(i);
				v.push_back(0);
			}
		}
		//for(auto cur:v) cout << cur << ' ';
		//cout << endl;
		for(auto cur:v){
			if(cur==0){
				for(int i=0; i<(int)sz-2; i+=2){
					ax.push_back(w[i]);
					ay.push_back(w[i+1]);
				}
				if(sz>=2){
					ax.push_back(w[sz-2]);
					ay.push_back(w[sz-1]);
				}
				sz=0;
			}
			else{
				w[sz++]=cur;
			}
		}
		cout << ax.size() << '\n';
		for(int i=0; i<ax.size() ;i++){
			cout << ax[i] << ' ' << ay[i] << '\n';
		}
	}
	
}