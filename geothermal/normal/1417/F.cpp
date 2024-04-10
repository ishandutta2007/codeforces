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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
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
const int MX = 1000001; //check the limits, dummy
 
ll SZ = 262144; //set this to power of two
pl* seg = new pl[2*SZ]; //segtree implementation by bqi343's Github

pl combine(pl a, pl b) { 
    if (a > b) return a;
    return b;
}


void update(int p, ll value) {  
    for (seg[p += SZ] = {value, p}; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    pl resL = {0, -1}, resR = {0, -1}; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    pl res = combine(resL,resR);
    if (res.s != -1) {
        update(res.s, 0);
    }
    return res.f;
}

vector<vi> graph, queries;
int ans[MX];
int ct = 0;
int tin[MX], tout[MX];
int P[MX];

void dfs1(int v, int p) {
    tin[v] = ct;
    bool found = false;
    trav(a, graph[v]) {
        if (a == p) continue;
        found = true;
        dfs1(a, v);
    }
    if (!found) {
        update(ct, P[v]);
        ct++;
    }
    tout[v] = ct-1; 
}

void dfs2(int v, int p) {
    F0Rd(i, sz(queries[v])) {
        ans[queries[v][i]] = query(tin[v], tout[v]);
    }

    trav(a, graph[v]) {
        if (a != p) dfs2(a, v);
    }
}

int parent[MX], siz[MX], rep[MX];

int nr = 0;

void init() {
    F0R(i, MX) parent[i] = i, siz[i] = 0, rep[i] = i;
}

int get(int x) {
    if (parent[x] != x) parent[x] = get(parent[x]);
    return parent[x];
}

int getRep(int x) {
    return rep[get(x)];
}

void unify(int x, int y) {
    x = get(x); y = get(y);
    if (x == y) return;
    if (siz[x] < siz[y]) swap(x, y);
    if (siz[x] == siz[y]) siz[x]++;
    parent[y] = x;
    graph.pb(vi());
    queries.pb(vi());
    graph[nr].pb(rep[x]); graph[nr].pb(rep[y]);
    rep[x] = nr;
    nr++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    F0R(i, MX) ans[i] = -1;
    init();
    F0R(i, SZ*2) {
        seg[i] = {0, -1};
    }
    int N, M, Q; cin >> N >> M >> Q;
    F0R(i, N) cin >> P[i];
    nr = N;
    vpi edges(M); F0R(i, M) cin >> edges[i].f >> edges[i].s;
    F0R(i, M) edges[i].f--, edges[i].s--;

    vpi quer(Q);
    F0R(i, Q) cin >> quer[i].f >> quer[i].s;
    set<int> inEd; F0R(i, M) inEd.ins(i);
    F0R(i, Q) {
        if (quer[i].f == 2) {
            inEd.erase(quer[i].s-1);
        }
    }
    F0R(i, N) {
        graph.pb(vi()); queries.pb(vi());
    }
    trav(a, inEd) {
        unify(edges[a].f, edges[a].s);
    }
    F0Rd(i, Q) {
        if (quer[i].f == 1) {
            int R = getRep(quer[i].s-1);
            queries[R].pb(i);
        } else {
            int E = quer[i].s-1;
            unify(edges[E].f, edges[E].s);
        }
    }

    bool isRoot[nr]; F0R(i, nr) isRoot[i] = true;
    trav(a, graph) {
        trav(b, a) {
            isRoot[b] = false;
        }
    }
    F0R(i, nr) {
        if (isRoot[i]) {
            dfs1(i, i);
            dfs2(i, i);
        }
    }
    F0R(i, Q) {
        if (ans[i] != -1) {
            cout << ans[i] << nl;
        }
    }
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343