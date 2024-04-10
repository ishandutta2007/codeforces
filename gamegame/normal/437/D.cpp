#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
ll n,m;
pair<ll,int>a[N];
vector<int>adj[N];
ll sz[N];
int p[N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
ll ans=0;
ll join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return 0;
	p[x]=y;
	ll tmp=sz[x]*sz[y];
	sz[y]+=sz[x];
	return tmp;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=n; i>=1 ;i--){
		int x=a[i].se;
		sz[x]=1;
		p[x]=x;
		for(auto y:adj[x]){
			if(sz[y]==0) continue;
			ll tmp=join(x,y);
			ans+=a[i].fi*tmp;
		}
		//cout << ans << ' ' << x << endl;
	}
	cout << fixed << setprecision(10) << 2.0*ans/n/(n-1) << endl;
}