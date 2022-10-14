#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//O(n log n) time, O(n) memory solution
//using centroid tree

template<typename T, typename Comparator>
struct rmq {
    static const Comparator comparator;
	vector<T> v; int n;
	static constexpr int b = 30; // block size
	vector<int> mask, t; // mask and sparse table

	__attribute__((always_inline)) int lsb(int x) const {
		return x & -x;
	}

	__attribute__((always_inline)) int msb_index(int x) const {
		return __builtin_clz(1)-__builtin_clz(x);
	}

	__attribute__((always_inline)) int op(int i, int j) const {
        return comparator(v[i], v[j]) ? i : j;
	}

	int small(int r, int sz = b) const {
		int dist_from_r = msb_index(mask[r] & ((1<<sz)-1));
		return r - dist_from_r;
	}

	rmq() {}

	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		int curr_mask = 0;
		for (int i = 0; i < n; i++) {
			curr_mask = (curr_mask<<1) & ((1<<b)-1);
			while (curr_mask > 0 && op(i, i - msb_index(lsb(curr_mask))) == i) {
				curr_mask ^= lsb(curr_mask);
			}
			curr_mask |= 1;
			mask[i] = curr_mask;
		}
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}

	int query(int l, int r) const {
	    assert(l <= r);
		// query too small
		if (r-l+1 <= b) return small(r, r-l+1);
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb_index(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return ans;
	}
};

template<typename T>
using min_rmq = rmq<T, less<T>>;

template<typename T>
using max_rmq = rmq<T, greater<T>>;

constexpr int INF = 1e9;
struct Solver {
private:
    int n, q;
    vvi adj;

    vi tin, tout;
    vi dep;
    vi tour, tour_dep;
    min_rmq<int> rmq;

    vvi cadj;
    vi cpar;
    vb cvis;
    vi csz;
    vi mdist;

    void input() {
        cin >> n >> q;
        adj.resize(n);
        rep(i, n - 1) {
            int u, v; cin >> u >> v; --u, --v;
            adj[u].eb(v);
            adj[v].eb(u);
        }
    }

    void dfs(int u, int p = -1) {
        tin[u] = tour.size();
        tour.pb(u);
        tour_dep.pb(dep[u]);
        for(int v: adj[u]) if(v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
            tout[u] = tour.size();
            tour.pb(u);
            tour_dep.pb(dep[u]);
        }
        if(tout[u] < tin[u]) tout[u] = tin[u];
    }

    void init_distance_oracle() {
        tin.resize(n);
        tout.resize(n);
        dep.resize(n);
        dfs(0);
        rmq = min_rmq<int>(tour_dep);
    }

    int lca(int u, int v) {
        if(u == v) return u;
        if(tin[u] > tin[v]) swap(u, v);
        if(tout[u] > tout[v]) return u;
        else {
            assert(tout[u] < tin[v]);
            return tour[rmq.query(tout[u], tin[v])];
        }
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    void cdfs(int u, int p = -1) {
        csz[u] = 1;
        for(int v: adj[u]) if(!cvis[v] && v != p) {
            cdfs(v, u);
            csz[u] += csz[v];
        }
    }

    int decomp(int u) {
        cdfs(u);
        int s = csz[u];
        int ans = u, par = -1;
        while (1) {
            int lg = 0, lg_sz = 0;
            for(int v: adj[ans]) if(!cvis[v] && v != par && csz[v] > lg_sz) lg_sz = csz[v], lg = v;
            if (lg_sz > s / 2) par = ans, ans = lg;
            else {
                cvis[ans] = 1;
                for(int v: adj[ans]) if(!cvis[v]) {
                    int x = decomp(v);
                    cadj[ans].pb(x);
                    cpar[x] = ans;
                }
                return ans;
            }
        }
    }

    void init_centroid_tree() {
        cadj.resize(n);
        cpar.assign(n, -1);
        cvis.assign(n, 0);
        csz.resize(n);
        mdist.assign(n, INF);
        decomp(0);
    }

    void init() {
        input();
        init_distance_oracle();
        init_centroid_tree();
    }

    void add(int u) {
        for(int v = u; ~v; v = cpar[v]) mdist[v] = min(mdist[v], dist(u, v));
    }

    int query(int u) {
        int ans = INF;
        for(int v = u; ~v; v = cpar[v]) ans = min(ans, mdist[v] + dist(u, v));
        return ans;
    }

public:
    void solve() {
        init();
        add(0);
        while(q--) {
            int t, v; cin >> t >> v; --v;
            if(t == 1) add(v);
            else cout << query(v) << endl;
        }
    }

} solver;

int32_t main() {
    fastio;
    Solver solver;
    solver.solve();
}