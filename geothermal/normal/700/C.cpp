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
const int MX = 100001; //check the limits, dummy

int N;
vector<vector<pair<int, pl> > > graph;
int S, T;
vector<bool> vis;
vi tin, low, vb;
int timer;
vector<pair<pi, int> > edges;
ll ans;
int bestEdge = -1;
bool ok[30001], me[30001];
int cnt[1001][1001];

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    trav(x, graph[v]) {
        int a = x.f;
        if (a == p) continue;
        if (vis[a]) {
            ckmin(low[v], tin[a]);
        } else {
            dfs(a, v);
            ckmin(low[v], low[a]);
            if (low[a] > tin[v]) {
                //cout << "Edge " << x.s.s << " between " << a << " " << v << " is a possible bridge" << nl;
                if (ok[x.s.s] && !me[x.s.s]) {
                    if (ckmin(ans, x.s.f)) {
                        bestEdge = x.s.s;
                        //cout << x.s.s+1 << " is a bridge" << nl;
                    }
                }
            }
        }
    }
}

pl solve(int e) {
   //cout << "Trying " << e+1 << nl;
    timer = 0;
    vis.assign(N, false);
    tin.assign(N, -1);
    low.assign(N, -1);
    graph.assign(N, vector<pair<int, pl>>());
    ans = 1e11;
    cnt[edges[e].f.f][edges[e].f.s]--;
    F0R(i, sz(edges)) {
        if (i != e) {
            graph[edges[i].f.f].pb({edges[i].f.s, {edges[i].s, i}});
            graph[edges[i].f.s].pb({edges[i].f.f, {edges[i].s, i}});
            ok[i] = false;
            me[i] = cnt[edges[i].f.f][edges[i].f.s] > 1;
        }
    }
    cnt[edges[e].f.f][edges[e].f.s]++;
    int lst[N]; F0R(i, N) lst[i] = -1;
    int bef[N];
    lst[T] = sz(edges)+1;
    queue<int> q;
    q.push(T);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        trav(a, graph[cur]) {
            if (lst[a.f] == -1) {
                lst[a.f] = a.s.s; q.push(a.f);
                bef[a.f] = cur;
            }
        }
    }
    if (lst[S] == -1) {
        return {0, -1};
    }
    int val = S;
    while (val != T) {
        ok[lst[val]] = true;
        val = bef[val];
    }
    dfs(S);
    if (vis[T]) {
        return {ans, bestEdge};
    } 
    return {0, -1};
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    int M; cin >> M;
    graph.assign(N, vector<pair<int, pl> > ());
    cin >> S >> T; S--; T--;
    F0R(i, N) F0R(j, N) cnt[i][j] = 0;
    F0R(i, M) {
        int X, Y, W; cin >> X >> Y >> W; X--; Y--;
        if (X > Y) swap(X, Y);
        graph[X].pb({Y, {i, W}});
        graph[Y].pb({X, {i, W}});
        edges.pb({{X, Y}, W});
        cnt[X][Y]++;
    }

    int lst[N]; F0R(i, N) lst[i] = -1;
    int bef[N]; F0R(i, N) bef[i] = -1;
    lst[S] = M+1;
    queue<int> q; q.push(S);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        trav(a, graph[cur]) {
            if (lst[a.f] == -1) {
                lst[a.f] = a.s.f; q.push(a.f);
                bef[a.f] = cur;
            }
        }
    }
    if (lst[T] == -1) {
        cout << "0\n0\n" << nl; return 0;
//        cout << 0 << nl; return 0;
    }
    ll res = 1e12; pl best = {-1, -1};
    int cur = T;
    while (cur != S) {
        pl val = solve(lst[cur]);
        if (res > val.f + edges[lst[cur]].s) {
            res = val.f + edges[lst[cur]].s;
            best = {lst[cur], val.s};
        }
        cur = bef[cur];
    }

    if (res >= 1e10) {
        cout << -1 << nl; return 0;
    }
    cout << res << nl;
    if (best.s == -1) {
        cout << "1\n" << best.f+1 << nl;
    } else {
        cout << "2\n" << best.f+1 << " " << best.s+1 << nl;
    }


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343