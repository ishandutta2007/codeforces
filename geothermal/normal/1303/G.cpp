#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 150001; //check the limits, dummy



struct CentroidDecomposition {
	vector<set<int>> tree; // it's not vector<vector<int>>!
	vector<int> dad;
	vector<int> sub;
    vector<int> dep;
 
	CentroidDecomposition(vector<set<int>> &tree) : tree(tree) {
		int n = tree.size();
		dad.resize(n);
		sub.resize(n);
        dep.resize(n);
		build(0, -1);
	}
 
	void build(int u, int p) {
		int n = dfs(u, p); // find the size of each subtree
		int centroid = dfs(u, p, n); // find the centroid
        if (p == -1) {
            dep[centroid] = 0;
        } else {
            dep[centroid] = dep[p] + 1;
        }
		if (p == -1) p = centroid; // dad of root is the root itself
		dad[centroid] = p;
		// for each tree resulting from the removal of the centroid
        while (!tree[centroid].empty()) {
            int v = *(tree[centroid].begin());
			tree[centroid].erase(v); // remove the edge to disconnect
			tree[v].erase(centroid); // the component from the tree
			build(v, centroid);
        }
 
	}
 
	int dfs(int u, int p) {
		sub[u] = 1;
 
		for (auto v : tree[u])
			if (v != p) sub[u] += dfs(v, u);
 
		return sub[u];
	}
 
	int dfs(int u, int p, int n) {
		for (auto v : tree[u])
			if (v != p and sub[v] > n/2) return dfs(v, u, n);
 
		return u;
	}
 
	int operator[](int i) {
		return dad[i];
	}
};

struct dp_hull {

    static const long long LL_INF = (long long) 2e18 + 5;
     
    struct point {
        long long x, y;
     
        point() : x(0), y(0) {}
     
        point(long long _x, long long _y) : x(_x), y(_y) {}
    };

    struct segment {
        point p;
        mutable point next_p;
 
        segment(point _p = {0, 0}, point _next_p = {0, 0}) : p(_p), next_p(_next_p) {}
 
        bool operator<(const segment &other) const {
            // Sentinel value indicating we should binary search the set for a single x-value.
            if (p.y == LL_INF)
                return p.x * (other.next_p.x - other.p.x) <= other.p.y - other.next_p.y;
 
            return make_pair(p.x, p.y) < make_pair(other.p.x, other.p.y);
        }
    };
 
    set<segment> segments;
 
    int size() const {
        return segments.size();
    }
 
    set<segment>::iterator prev(set<segment>::iterator it) const {
        return it == segments.begin() ? it : --it;
    }
 
    set<segment>::iterator next(set<segment>::iterator it) const {
        return it == segments.end() ? it : ++it;
    }
 
    static long long floor_div(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }
 
    static bool bad_middle(const point &a, const point &b, const point &c) {
        // This checks whether the x-value where b beats a comes after the x-value where c beats b. It's fine to round
        // down here if we will only query integer x-values. (Note: plain C++ division rounds toward zero)
        return floor_div(a.y - b.y, b.x - a.x) >= floor_div(b.y - c.y, c.x - b.x);
    }
 
    bool bad(set<segment>::iterator it) const {
        return it != segments.begin() && next(it) != segments.end() && bad_middle(prev(it)->p, it->p, next(it)->p);
    }
 
    void insert(const point &p) {
        set<segment>::iterator next_it = segments.lower_bound(segment(p));
 
        if (next_it != segments.end() && p.x == next_it->p.x)
            return;
 
        if (next_it != segments.begin()) {
            set<segment>::iterator prev_it = prev(next_it);
 
            if (p.x == prev_it->p.x)
                segments.erase(prev_it);
            else if (next_it != segments.end() && bad_middle(prev_it->p, p, next_it->p))
                return;
        }
 
        // Note we need the segment(p, p) here for the single x-value binary search.
        set<segment>::iterator it = segments.insert(next_it, segment(p, p));
 
        while (bad(prev(it)))
            segments.erase(prev(it));
 
        while (bad(next(it)))
            segments.erase(next(it));
 
        if (it != segments.begin())
            prev(it)->next_p = it->p;
 
        if (next(it) != segments.end())
            it->next_p = next(it)->p;
    }
 
    void insert(long long a, long long b) {
        insert(point(a, b));
    }
 
    // Queries the maximum value of ax + b.
    long long query(long long x) const {
        assert(size() > 0);
        set<segment>::iterator it = segments.upper_bound(segment(point(x, LL_INF)));
        return it->p.x * x + it->p.y;
    }
};

dp_hull hull;

ll A[MX];
vector<set<int> > graph(MX), cg(MX);
vi dep;

ll dfs1(int v, int p, int d, ll tot, ll sum, int C) {
    d++;
    sum += A[v];
    tot += A[v] * d;
    ll ans = hull.query(sum) + tot;
    trav(nxt, graph[v]) {
        if (nxt == p || dep[nxt] <= dep[C]) continue;
        ckmax(ans, dfs1(nxt, v, d, tot, sum, C));
    }
    return ans;
}

void dfs2(int v, int p, int d, ll tot, ll sum, int C) {
    sum += A[v];
    tot += sum;
    d++;
    hull.ins(d, tot);
    trav(nxt, graph[v]) {
        if (nxt == p || dep[nxt] <= dep[C]) continue;
        dfs2(nxt, v, d, tot, sum, C);
    }
}

ll go(ll C) {
    hull = dp_hull();
    ll ans = A[C];
    hull.ins(1, A[C]);
    for (auto it = graph[C].begin(); it != graph[C].end(); it++) {
        int nxt = *it;
        if (dep[nxt] > dep[C]) {
            ckmax(ans, dfs1(nxt, C, 0, 0, 0, C));
            dfs2(nxt, C, 1, A[C], A[C], C);
        }
    }
    ckmax(ans, hull.query(0));
    hull = dp_hull();
    hull.ins(1, A[C]);
    for (auto it = graph[C].rbegin(); it != graph[C].rend(); it++) {
        int nxt = *it;
        if (dep[nxt] > dep[C]) {
            ckmax(ans, dfs1(nxt, C, 0, 0, 0, C));
            dfs2(nxt, C, 1, A[C], A[C], C);
        }
    }
    trav(a, cg[C]) {
        ckmax(ans, go(a));
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N; cin >> N;

    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].ins(Y);
        graph[Y].ins(X);
    }

    F0R(i, N) cin >> A[i];

    CentroidDecomposition cd(graph);
    int C;
    F0R(i, N) {
        if (cd.dad[i] != i) {
            cg[cd.dad[i]].ins(i);
        } else {
            C = i;
        }
    }
    dep = cd.dep;
    cout << go(C) << nl;


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343