#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
int n,m;
vector<int>s[100001];
int deg[100001];
vector<int>adj[100001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		if(u>v) swap(u,v);
		s[u].push_back(v);
		deg[u]++;deg[v]++;
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ans+=1LL*s[i].size()*(deg[i]-s[i].size());
	}
	cout << ans << '\n';
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		int x;cin >> x;
		ans-=1LL*s[x].size()*(deg[x]-s[x].size());
		for(auto y:s[x]){
			ans-=1LL*s[y].size()*(deg[y]-s[y].size());
			s[y].push_back(x);
			ans+=1LL*s[y].size()*(deg[y]-s[y].size());
		}
		s[x].clear();
		cout << ans << '\n';
	}
}