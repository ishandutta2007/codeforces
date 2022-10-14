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
		vector<vector<bool>> v(2, vector<bool>(n));
		int N = 0;
		int left = MOD, right = 0;
		forn(i, 2) {
			forn(j, n) {
				char c; cin >> c;
				v[i][j] = c == '*';
				N += v[i][j];
				if(v[i][j]) {
					ckmin(left, j);
					ckmax(right, j);
				}
			}
		}

		// vector<pair<ll, pii>> edges;
		// int hi = -1, lo = -1;
		// int hipos = -1, lopos = -1;
		// int ind = 0;
		// forn(j, n) {
		// 	if(v[0][j] && v[1][j]) {
		// 		if(hi != -1) {
		// 			edges.pb({j - hipos, {hi, ind}});
		// 			edges.pb({j - hipos+1, {hi, ind+1}});
		// 		}
		// 		if(lo != -1) {
		// 			edges.pb({j - lopos+1, {lo, ind}});
		// 			edges.pb({j - lopos, {lo, ind+1}});
		// 		}

		// 		hi = ind++;
		// 		lo = ind++;
		// 		hipos = j;
		// 		lopos = j;
		// 		edges.pb({1, {hi, lo}});
		// 	} else if(v[0][j]) {
		// 		if(hi != -1) {
		// 			edges.pb({j - hipos, {hi, ind}});
		// 		}
		// 		if(lo != -1) {
		// 			edges.pb({j - lopos+1, {lo, ind}});
		// 		}

		// 		hi = ind++;
		// 		hipos = j;
		// 	} else if(v[1][j]) {
		// 		if(hi != -1) {
		// 			edges.pb({j - hipos+1, {hi, ind}});
		// 		}
		// 		if(lo != -1) {
		// 			edges.pb({j - lopos, {lo, ind}});
		// 		}

		// 		lo = ind++;
		// 		lopos = j;
		// 	}
		// }

		// DSU d(N);
		// sort(edges.begin(), edges.end());
		// ll ans = 0;
		// for(auto e: edges) {
		// 	if(!d.together(e.s.f, e.s.s)) {
		// 		ans += e.f;
		// 		d.join(e.s.f, e.s.s);
		// 	}
		// }

		int hicost = MOD, locost = MOD;
		for(int j = left; j<=right; j++) {
			if(hicost == MOD) {
				assert(j == left);
				hicost = 0;
				locost = 0;
				if(v[0][j]) {
					locost++;
				}
				if(v[1][j]) {
					hicost++;
				}
			} else {
				hicost++;
				locost++;
				int nhc = hicost;
				int nlc = locost;
				if(v[0][j]) {
					nlc++;
				}
				if(v[1][j]) {
					nhc++;
				}

				ckmin(nhc, locost+1);
				ckmin(nlc, hicost+1);

				hicost = nhc;
				locost = nlc;
			}
			// ckmin(hicost, locost+1);
			// ckmin(locost, hicost+1);
		}

		cout << min(hicost, locost) << "\n";


	}
}