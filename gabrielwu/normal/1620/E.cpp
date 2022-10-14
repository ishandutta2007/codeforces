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
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


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

	int q;
	cin >> q;

	int m = 5e5+5;
	DSU d(m);
	vector<int> comp(m, -1);
	vector<int> val(m);

	int ind = 0;
	forn(qi, q){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			cin >> x;
			val[ind] = x;
			if(comp[x] == -1){
				comp[x] = ind;
			} else {
				d.join(comp[x], ind);
				if(d.root(ind) == ind){
					comp[x] = ind;
				}
				assert(d.root(ind) == comp[x]);
			}
			ind++;
		} else {
			int x, y;
			cin >> x >> y;
			if(comp[x] == -1 || x == y) continue;
			val[d.root(comp[x])] = y;
			if(comp[y] == -1){
				comp[y] = comp[x];
			} else {
				d.join(comp[x], comp[y]);
				if(d.root(comp[x]) == comp[x]){
					comp[y] = comp[x];
				}
				assert(d.root(comp[x]) == comp[y]);
			}
			comp[x] = -1;
		}
	}

	forn(i, ind){
		cout << val[d.root(i)] << " ";
	} cout << "\n";
}