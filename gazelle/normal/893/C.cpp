#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

vector<ll> c;
vector<vector<ll>> adj;

ll dfs(ll pos, vector<bool>& used) {
	used[pos]=true;
	ll ret=c[pos];
	REP(i,(ll)adj[pos].size()) {
		if(!used[adj[pos][i]]) ret=min(ret,dfs(adj[pos][i],used));
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	c.resize(n);
	adj.resize(n);
	REP(i,n) cin>>c[i];
	REP(i,m) {
		ll x,y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ll ret=0;
	vector<bool> used(n,false);
	REP(i,n) {
		if(!used[i]) {
			ret+=dfs(i,used);
		}
	}
	cout<<ret<<endl;
}