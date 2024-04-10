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
    std::vector<int> par, sz;
    int n;

    DSU() {}
    DSU(int _n) { init(_n); }
    void init(int _n) {
        n = _n;
        sz.assign(n, 1);
        par.assign(n, 0);
        std::iota(par.begin(), par.end(), 0);
    }

    void join(int x, int y) {
        int xr = root(x), yr = root(y);
        if(xr == yr) return;

        if(sz[xr] < sz[yr]) swap(xr, yr);
        par[yr] = xr;
        sz[xr] += sz[yr];
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

	// -- Sieve start --
	const int MAX_PRIME = 1000005;
	vector<int> sieve(MAX_PRIME);	// sieve[i] := smallest factor of i greater than 1.
	vector<int> primes;				// list of primes up to MAX_PRIME
	
	for(int i=2; i<MAX_PRIME; i++) {
			if(!sieve[i]) {
					primes.push_back(i);
					for(int x=i; x<MAX_PRIME; x+=i) {
							if(sieve[x] == 0) {
									sieve[x] = i;
							}
					}
			}
	}
	// -- Sieve end --
	
	DSU d(MAX_PRIME);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	forn(i, n){
		cin >> v[i];
		vector<int> p;
		int x = v[i];
		while(x != 1){
			p.pb(sieve[x]);
			x /= sieve[x];
		}
		forn(j, p.size()-1){
			d.join(p[j], p[j+1]);
		}
	}

	vector<set<int>> adj(MAX_PRIME);
	forn(i, n){
		vector<int> p;
		p.pb(sieve[v[i]]);
		int x = v[i]+1;
		while(x != 1){
			p.pb(sieve[x]);
			x /= sieve[x];
		}
		forn(j, p.size()){
			for(int k=j+1; k<p.size(); k++){
				adj[d.root(p[j])].insert(d.root(p[k]));
				adj[d.root(p[k])].insert(d.root(p[j]));
			}
		}
	}

	forn(qi, q){
		int i, j;
		cin >> i >> j;
		i--; j--;
		int a=d.root(sieve[v[i]]), b=d.root(sieve[v[j]]);
		if(a==b){
			cout << "0\n";
		}else if(adj[a].find(b) != adj[a].end()){
			cout << "1\n";
		}else{
			cout << "2\n";
		}
	}
}