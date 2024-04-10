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
const int MX = 200001; //check the limits, dummy
const int loMX = 1001;

template<int SZ> struct DSU {
    int parent[SZ], size[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;

    }
};

void solve() {

    ll N, M; cin >> N >> M;
    vector<vpi> graph(N);
    int xo = 0;
    F0R(i, M) {
        int X, Y, Z; cin >> X >> Y >> Z; X--; Y--;
        graph[X].pb({Y, Z});
        graph[Y].pb({X, Z});
        xo ^= Z;
    }

    bool isCyc = false;
    if ((N*(N-1))/2 - M >= N) {
        isCyc = true;
    }
    vector<pi> freeEdge;
    if (!isCyc) {
        DSU<loMX> dsu;
        F0R(i, N) {
            bool ok[N]; F0R(j, N) ok[j] = true;
            trav(a, graph[i]) ok[a.f] = false;
            FOR(j, i+1, N) {
                if (ok[j] && dsu.get(j) == dsu.get(i)) {
                    isCyc = false;
                } else if (ok[j]) {
                    freeEdge.pb({i, j});
                    dsu.unify(i, j);
                }
            }
        }
    }
    vector<pair<int, pi>> ed;
    F0R(i, N) {
        trav(a, graph[i]) {
            if (a.f > i) {
                ed.pb({a.s, {i, a.f}});
            }
        }
    }
    if (!isCyc) {
        ll ans = 1e18;
        ed.pb({xo, {-1, -1}});
        sort(all(ed));
        F0R(x, sz(freeEdge)) {
            DSU<loMX> dsu;
            F0R(i, sz(freeEdge)) {
                if (i != x) dsu.unify(freeEdge[i].f, freeEdge[i].s);
            }
            ll cur = 0;
            trav(a, ed) {
                if (a.s.s == -1) {
                    if (dsu.get(freeEdge[x].f) != dsu.get(freeEdge[x].s)) {
                        dsu.unify(freeEdge[x].f, freeEdge[x].s); cur += xo;
                    }
                }
                else if (dsu.get(a.s.f) != dsu.get(a.s.s)) {
                    dsu.unify(a.s.f, a.s.s);
                    cur += a.f;
                }
            }
            ckmin(ans, cur);
        }
        cout << ans << nl;
    } else {
        //standard MST
        priority_queue<pl, vpl, greater<pl>> q;
        bool vis[N]; F0R(i, N) vis[i] = false;
        set<int> need; F0R(i, N) need.ins(i);
        need.erase(0);
        q.push({0, 0});
        ll ans = 0;
        while (!q.empty()) {
            int x = q.top().s; ll d = q.top().f; q.pop();
            if (vis[x]) continue;
            ans += d;
            vis[x] = true;
            set<int> nxt;
            trav(a, graph[x]) {
                if (need.count(a.f)) {
                    nxt.ins(a.f);
                }
                q.push({a.s, a.f});
            }
            trav(a, need) {
                if (!nxt.count(a)) {
                    q.push({0, a});
                }
            }
            need = nxt;
        }
        cout << ans << nl;
    }



}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343