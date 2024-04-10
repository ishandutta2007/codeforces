#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
   cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io() {
   cin.tie(0)->sync_with_stdio(0);
}
void file_io(string taskname) {
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

int main(){
    fast_io();

    int t;
    cin >> t;
    forn(ti, t){
    	int n, m;
    	cin >> n >> m;
    	vector<ll> v(n);
    	forn(i, n){
    		cin >> v[i];
    	}
    	forn(i, n){
    		ll x;
    		cin >> x;
    		v[i] -= x;
    	}
    	vector<vector<int>> adj(n);
    	forn(i, m){
    		int x, y;
    		cin >> x >> y;
    		x--;y--;
    		adj[x].pb(y);
    		adj[y].pb(x);
    	}
    	vector<int> depth(n, -1);

    	function<void(int, int, int)> dfs = [&](int u, int par, int d){
    		depth[u] = d;
    		for(int oth: adj[u]){
    			if(oth != par && depth[oth] == -1){
    				dfs(oth, u, d+1);
    			}
    		}
    	};

    	dfs(0,-1,0);
    	ll sum = 0;
    	forn(i, n){
    		if(depth[i] %2 == 0){
    			sum += v[i];
    		}else{
    			sum -= v[i];
    		}
    	}
      sum = abs(sum);

    	if(sum%2 != 0){
    		cout << "NO\n";
    		continue;
    	}
    	if(sum == 0){
    		cout << "YES\n";
    		continue;
    	}
    	bool conn = false;
    	forn(i, n){
    		for(int oth: adj[i]){
    			if(depth[i] %2 == depth[oth]%2) conn = true;
    		}
    	}
    	if(conn){
    		cout << "YES\n";
    	}else{
    		cout << "NO\n";
    	}
    }
}