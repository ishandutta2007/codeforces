#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

struct DSU{
	vector<int> par;
	vector<vector<pii>> adj;
	int n;
	DSU(int _n, vector<vector<pii>> _adj): n(_n), par(_n), adj(_adj) {
		for(int i=0; i<n; i++) par[i] = i;
	}
	void join(int x, int y) {
		int xr = root(x), yr = root(y);
		if(xr == yr) return;

		if(adj[xr].size() < adj[yr].size()) swap(xr, yr);
		par[yr] = xr;
		for(pii item: adj[yr]){
			adj[xr].pb(item);
		}
	}    
	int root(int x){ //Uses path splitting.
		while(par[x] != x) {
			int prev = x;
			x = par[x];
			par[prev] = par[x];
		}
		return x;
	}
	bool together(int x, int y) {return root(x) == root(y);}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m; ll x;
	cin >> n >> m >> x;
	vector<ll> a(n);
	ll sum = 0;
	forn(i, n){
		cin >> a[i];
		sum += a[i];
	}

	if(sum < x*(n-1)){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	vector<vector<pii>> adj(n);
	forn(i, m){
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].pb(mp(i, y));
		adj[y].pb(mp(i, x));
	}

	priority_queue<pll> pq;
	forn(i, n){
		pq.push(mp(a[i], i));
	}

	DSU d(n, adj);

	int joined = 0;
	while(joined < n-1){
		pll top = pq.top(); pq.pop();
		if(top.s != d.root(top.s) || a[top.s] != top.f) continue;
		bool found = false;
		while(!found){
			assert(!d.adj[top.s].empty());
			pii back = d.adj[top.s].back();
			d.adj[top.s].pop_back();
			int oth = d.root(back.s);
			if(oth != top.s){
				found = true;
				cout << back.f+1 << "\n";
				ll newa = a[top.s] + a[oth] - x;
				a[top.s] = newa;
				a[oth] = newa;
				d.join(top.s, oth);
				pq.push(mp(newa, d.root(top.s)));
			}
		}
		joined++;
	}



}