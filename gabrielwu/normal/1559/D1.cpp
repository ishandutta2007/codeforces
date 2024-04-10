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

	int n, m1, m2;
	cin >> n >> m1 >> m2;

	DSU d1(n), d2(n);
	forn(i, m1){
		int a, b;
		cin >> a >> b;
		d1.join(a-1, b-1);
	}
	forn(i, m2){
		int a, b;
		cin >> a >> b;
		d2.join(a-1, b-1);
	}

	if(m1 < m2){
		swap(d1, d2);
		swap(m1, m2);
	}

	set<int> ids;
	vector<vector<int>> comps(n);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	forn(i, n){
		if(d2.root(i) == i){
			ids.insert(i);
		}
		comps[d1.root(i)].pb(i);
	}

	forn(i, n){
		if(d1.root(i) == i) pq.push(mp(comps[i].size(), i));
	}

	cout << n - 1 - m1 << "\n";
	int sofar = 0;
	while(sofar < n-1-m1){
		pii p = pq.top(); pq.pop();
		if(d1.root(p.s) != p.s || p.f != comps[p.s].size()) continue;

		vector<int> c = comps[p.s];

		bool allsame = true;
		int oth = -1;
		for(int i = 1; i<c.size(); i++){
			if(d2.root(c[0]) != d2.root(c[i])){
				allsame = false;
				oth = i;
			}
		}

		int a, b;
		if(allsame){
			a = c[0];
			auto it = ids.begin();
			if(d2.root(a) == *it) it++;
			b = *it;
			assert(d1.root(a) != d1.root(b));
		} else {
			int x = rand(0,n-1);
			while(d1.root(x) == p.s) x = rand(0, n-1);
			b = x;
			if(d2.root(x) == d2.root(c[0])) a = c[oth];
			else a = c[0];
		}

		// assert(d2.root(a) != d2.root(b));

		cout << a+1 << " " << b+1 << "\n";
		sofar++;
		ids.erase(d2.root(a));
		ids.erase(d2.root(b));
		d2.join(a, b);
		ids.insert(d2.root(a));

		for(int x: comps[d1.root(b)]) c.pb(x);
		d1.join(a, b);
		int nr = d1.root(a);
		comps[a].clear();
		comps[b].clear();
		comps[nr] = c;
		pq.push(mp(comps[nr].size(), nr));
	}
}