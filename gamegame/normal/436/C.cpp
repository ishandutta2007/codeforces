#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
int n,m;
int k,w;
char c[1001][11][11];
vector<pair<ll,pair<int,int> > >v;
int par[1001];
int find(int x){
	if(par[x]!=x) par[x]=find(par[x]);
	return par[x];
}
bool join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return false;
	par[x]=y;
	return true;
}
bool vis[1001];
vector<int>adj[1001];
void dfs(int id){
	vis[id]=true;
	for(auto cur:adj[id]){
		if(vis[cur]) continue;
		cout << cur << ' ' << id << '\n';
		dfs(cur);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> w;
	for(int i=1; i<=k ;i++){
		for(int j=1; j<=n ;j++){
			for(int k=1; k<=m ;k++){
				cin >> c[i][j][k];
			}
		}
	}
	for(int i=1; i<=k ;i++){
		v.push_back({n*m,{0,i}});
		for(int j=1; j<i ;j++){
			int e=0;
			for(int x=1; x<=n ;x++){
				for(int y=1; y<=m ;y++){
					if(c[i][x][y]!=c[j][x][y]) e++;
				}
			}
			v.push_back({1LL*e*w,{j,i}});
		}
	}
	for(int i=0; i<=k ;i++){
		par[i]=i;
	}
	sort(v.begin(),v.end());
	ll ans=0;
	vector<pair<int,int> >ff;
	for(auto cur:v){
		int x=cur.se.fi;
		int y=cur.se.se;
		if(join(x,y)){
			ans+=cur.fi;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	cout << ans << '\n';
	dfs(0);
}