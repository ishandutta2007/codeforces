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
#include<unordered_map>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define REP(i, m) for(long long i=0; i<m; ++i)
#define FOR(i, n, m) for(long long i=n; i<m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<ll> vl;
typedef vector<vector<ll> > vll;

ll gcd(ll a, ll b) {		// 
	if (b == 0) return a;
	return gcd(b, a % b);
}
vector<vector<ll> > adj;
vector<ll> res;
vector<ll> nz;
vector<ll> a;
void dfs(ll roc, ll par, set<ll> &s) {
	if(par==-1) {
		nz[roc]=a[roc];
		s.insert(0);
		res[roc]=a[roc];
		REP(i,adj[roc].size()) {
			dfs(adj[roc][i],roc,s);
		}
	} else {
		nz[roc]=gcd(nz[par],a[roc]);
		set<ll> ns;
		auto ite=s.begin();
		ll ret=0;
		while(ite!=s.end()) {
			ll buf=gcd(*ite,a[roc]);
			ret=max(ret,buf);
			ns.insert(buf);
			++ite;
		}
		ns.insert(nz[par]);
		ret=max(ret,nz[par]);
		res[roc]=max(nz[roc],ret);
		REP(i,adj[roc].size()) {
			if(adj[roc][i]==par) continue;
			dfs(adj[roc][i],roc,ns);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	adj.resize(n);
	res.resize(n);
	nz.resize(n);
	a.resize(n);
	REP(i,n) cin>>a[i];
	REP(i,n-1) {
		ll x,y;
		cin>>x>>y;
		--x;
		--y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	set<ll> s;
	dfs(0,-1,s);
	REP(i,n) {
		cout<<res[i];
		if(i!=n-1) cout<<" ";
		else cout<<endl;
	}
}