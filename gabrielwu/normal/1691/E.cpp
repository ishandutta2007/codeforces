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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

	int t;
	cin >> t;
	forn(ti, t) {
		int n;
		cin >> n;
		vector<int> c(n);
		vector<pair<pii, int>> ints(n);
		forn(i, n) {
			cin >> c[i] >> ints[i].f.f >> ints[i].f.s;
			ints[i].s = i;
		}

		sort(ints.begin(), ints.end());

		DSU dsu(n);
		set<pii> reds, blues;
		forn(i, n) {

			//remove expired
			while(reds.size() > 0 && (reds.begin()->f < ints[i].f.f)) reds.erase(reds.begin());
			while(blues.size() > 0 && (blues.begin()->f < ints[i].f.f)) blues.erase(blues.begin());

			if(c[ints[i].s] == 0) {
				while(blues.size() > 1) {
					dsu.join(blues.begin()->s, ints[i].s);
					blues.erase(blues.begin());
				}
				if(blues.size()) dsu.join(blues.begin()->s, ints[i].s);

				reds.insert({ints[i].f.s, ints[i].s});
			} else if(c[ints[i].s] == 1) {
				while(reds.size() > 1) {
					dsu.join(reds.begin()->s, ints[i].s);
					reds.erase(reds.begin());
				}
				if(reds.size()) dsu.join(reds.begin()->s, ints[i].s);

				blues.insert({ints[i].f.s, ints[i].s});
			}
		}

		int cnt = 0;
		forn(i, n) {
			if(dsu.par[i] == i) cnt++;
		}

		cout << cnt << "\n";
	}
}