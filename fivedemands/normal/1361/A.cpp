#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
int n,m;
vector<int>adj[500001];
pair<int,int>t[500001];
int c[500001];
int d[500001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n ;i++){
		cin >> t[i].fi;t[i].se=i;
	}
	sort(t+1,t+n+1);
	for(int i=1; i<=n ;i++){
		int x=t[i].se;
		for(auto y:adj[x]){
			//cout << x << ' ' << y << ' ' << c[y] << endl;
			d[c[y]]=true;
		}
		for(int j=1; j<t[i].fi ;j++){
			if(!d[j]) return cout << "-1\n",0;
		}
		if(d[t[i].fi]) return cout << "-1\n",0;
		for(auto y:adj[x]){
			d[c[y]]=false;
		}
		c[x]=t[i].fi;
	}
	for(int i=1; i<=n ;i++) cout << t[i].se << ' ';
}