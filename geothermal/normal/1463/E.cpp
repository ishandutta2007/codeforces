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
const int MX = 300001; //check the limits, dummy
 
template<int SZ> struct DSU {
    int parent[SZ], size[SZ], rep[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0, rep[i] = i;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) { 
            rep[y] = rep[x];
            swap(x, y);
        }
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;

    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    DSU<MX> dsu;
    int N, K; cin >> N >> K;
    int P[N]; F0R(i, N) cin >> P[i];
    vpi req;
    int aft[N]; F0R(i, N) aft[i] = -1;
    vector<vi> graph(N);
    int deg[N]; F0R(i, N) deg[i] = 0;
    F0R(i, K) {
        int X, Y; cin >> X >> Y; X--; Y--;
        dsu.unify(X, Y);
        req.pb({X, Y});
        aft[X] = Y;
        graph[X].pb(Y);
        deg[Y]++;
    }

    int pos[N]; 
    F0R(i, N) {
        if (P[i] != 0) {
            P[i]--;
            if (dsu.rep[dsu.get(P[i])] == dsu.rep[dsu.get(i)]) continue;
            graph[P[i]].pb(dsu.rep[dsu.get(i)]);
            deg[dsu.rep[dsu.get(i)]]++;
        } else {
            P[i] = -1;
        }
    }
    F0R(i, N) pos[i] = -1;
    deque<int> q;
    F0R(i, N) {
        if (deg[i] == 0) q.push_back(i);
    }
    int nxt = 0;
    vi ans;
    while (!q.empty()) {
        int cur = q.front(); q.pop_front();
        if (pos[cur] != -1) continue;

        pos[cur] = nxt; ans.pb(cur+1); nxt++;
        trav(a, graph[cur]) {
            deg[a]--;
            if (deg[a] == 0) {
                q.push_back(a);
            }
        }
        if (aft[cur] != -1) {
            if (deg[aft[cur]] == 0) q.push_front(aft[cur]);
        }
    }

    if (sz(ans) < N) {
        cout << 0 << nl;
    } else {
        F0R(i, N) {
            if (aft[i] != -1 && pos[aft[i]] != pos[i]+1) {
                cout << 0 << nl; return 0;
            }
            if (P[i] != -1 && pos[P[i]] > pos[i]) {
                cout << 0 << nl; return 0;
            }
        }
        F0R(i, N) {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343