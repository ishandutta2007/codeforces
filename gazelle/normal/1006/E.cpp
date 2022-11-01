#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<ll> pos;
vector<ll> subt;
vector<ll> preord;
vector<vector<ll>> adj;

ll dfs(ll p, ll par) {
	pos[p]=(ll)preord.size();
	preord.pb(p);
	ll ret=1;
	REP(i,adj[p].size()) if(adj[p][i]!=par) {
		ret+=dfs(adj[p][i],p);
	}
	subt[p]=ret;
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,q;
	cin>>n>>q;
	pos.resize(n);
	subt.assign(n,0);
	adj.resize(n);
	REP(i,n-1) {
		ll p;
		cin>>p;
		p--;
		adj[i+1].pb(p);
		adj[p].pb(i+1);
	}
	REP(i,n) sort(ALL(adj[i]));
	dfs(0,-1);
	REP(i,q) {
		ll u,k;
		cin>>u>>k;
		u--;
		if(k>subt[u]) cout<<-1<<endl;
		else {
			cout<<preord[pos[u]+(k-1)]+1<<endl;
		}
	}
	return 0;
}