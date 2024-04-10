#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> G[N];
vector<tuple<int,int,int> > E;
int n,m,c[N];
bool dfs(int u){
	for(auto [v,w]:G[u]){
		if(~c[v]){
			if((c[u]^c[v])!=w)return false;
		}
		else{
			c[v]=c[u]^w;
			if(!dfs(v))return false;
		}
	}
	return true;
}
void Solve(){
	cin>>n>>m;
	E.clear();
	for(int i=1;i<=n;++i){
		G[i].clear();c[i]=-1;
	}
	for(int i=1;i<n;++i){
		int x,y,p;
		cin>>x>>y>>p;
		if(~p){
			int c=__builtin_popcount(p)&1;
			G[x].emplace_back(y,c);
			G[y].emplace_back(x,c);
		}
		E.emplace_back(x,y,p);
	}
	for(int i=1;i<=m;++i){
		int x,y,p;
		cin>>x>>y>>p;
		G[x].emplace_back(y,p);
		G[y].emplace_back(x,p);
	}
	for(int i=1;i<=n;++i){
		if(!~c[i]){
			c[i]=0;
			if(!dfs(i)){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	for(auto [x,y,e]:E){
		cout<<x<<' '<<y<<' '<<(e==-1?(c[x]^c[y]):e)<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}