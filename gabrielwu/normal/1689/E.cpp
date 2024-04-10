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

int n;

pair<int, vector<int>> f(vector<int> a) {
	const int LG = 30;
	DSU d(n);
	vector<int> have(LG, -1);
	forn(i, n) {
		forn(j, LG) {
			if(a[i] & (1<<j)) {
				if(have[j] == -1) have[j] = i;
				else d.join(have[j], i);
			}
		}
	}

	vector<int> comps;
	forn(i, n) {
		if(d.par[i] == i) {
			comps.pb(i);
		}
	}

	if(comps.size() == 1) {
		return mp(0, a);
	}

	if(have[0] == -1) {
		for(int x: comps) a[x]++;
		return mp(comps.size(), a);
	} else {
		for(int x: comps) {
			if(d.root(x) != d.root(have[0])) a[x]++;
		}
		return mp(comps.size() - 1, a);
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t) {
		cin >> n;
		vector<int> a(n);
		forn(i, n) cin >> a[i];

		int best = n+1;
		vector<int> ans;

		auto x = f(a);
		if(x.f < best) {
			best = x.f;
			ans = x.s;
		}

		forn(i, n) {
			if(a[i] == 0) continue;
			a[i]--;
			auto x = f(a); x.f++;
			if(x.f < best) {
				best = x.f;
				ans = x.s;
			}
			a[i]++;
		}

		cout << best << "\n";
		forn(i, n) {
			cout << ans[i] << " ";
		}cout << "\n";
	}
}