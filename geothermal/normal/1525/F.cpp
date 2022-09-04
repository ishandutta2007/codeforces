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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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
const int MX = 100001; 

struct Edge {
   int v, u;
   long long cap, flow = 0;
   Edge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
   const long long flow_inf = 1e18;
   vector<Edge> edges;
   vector<vector<int>> adj;
   int n, m = 0;
   int s, t;
   vector<int> level, ptr;
   queue<int> q;

   Dinic(int n, int s, int t) : n(n), s(s), t(t) {
       adj.resize(n);
       level.resize(n);
       ptr.resize(n);
   }

   void add_edge(int v, int u, long long cap) {
       edges.emplace_back(v, u, cap);
       edges.emplace_back(u, v, 0);
       adj[v].push_back(m);
       adj[u].push_back(m + 1);
       m += 2;
   }

   bool bfs() {
       while (!q.empty()) {
           int v = q.front();
           q.pop();
           for (int id : adj[v]) {
               if (edges[id].cap - edges[id].flow < 1)
                   continue;
               if (level[edges[id].u] != -1)
                   continue;
               level[edges[id].u] = level[v] + 1;
               q.push(edges[id].u);
           }
       }
       return level[t] != -1;
   }

   long long dfs(int v, long long pushed) {
       if (pushed == 0)
           return 0;
       if (v == t)
           return pushed;
       for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
           int id = adj[v][cid];
           int u = edges[id].u;
           if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
               continue;
           long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
           if (tr == 0)
               continue;
           edges[id].flow += tr;
           edges[id ^ 1].flow -= tr;
           return tr;
       }
       return 0;
   }

   long long flow() {
       long long f = 0;
       while (true) {
           fill(level.begin(), level.end(), -1);
           level[s] = 0;
           q.push(s);
           if (!bfs())
               break;
           fill(ptr.begin(), ptr.end(), 0);
           while (long long pushed = dfs(s, flow_inf)) {
               f += pushed;
           }
       }
       return f;
   }
};
void solve() {
    int N, M, K; cin >> N >> M >> K;
    Dinic din(2*N+2, 2*N, 2*N+1);
    F0R(i, N) {
        din.add_edge(2*N, i, 1);
        din.add_edge(i+N, 2*N+1, 1);
    }

    F0R(i, M) {
        int X, Y; cin >> X >> Y;
        X--; Y--;
        din.add_edge(X, N+Y, 1);
    }

    ll X[K], Y[K];
    F0R(i, K) cin >> X[i] >> Y[i];

    ll G = N - 1 - din.flow(); // 0 ... N-1, number of waves that can be survived

    vector<vi> graph(2*N);
    bool found[2*N]; F0R(i, N) found[i] = true;
    FOR(i, N, 2*N) found[i] = false;
    queue<int> q;
    trav(a, din.edges) {
        if (a.v >= 2*N || a.u >= 2*N || a.cap == 0) continue;
        if (a.flow == 1) { //matched 
            found[a.v] = false;
            graph[a.u].pb(a.v);
        } else graph[a.v].pb(a.u);
    }

    F0R(i, N) if (found[i]) q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        trav(a, graph[v]) {
            if (!found[a]) {
                found[a] = true; q.push(a);
            }
        }
    }

    vi cov;
    F0R(i, N) {
        if (!found[i]) {
            cov.pb(i);
        }
    }
    FOR(i, N, 2*N) {
        if (found[i]) cov.pb(i);
    }


    ll dp[K+1][N]; F0R(i, K+1) F0R(j, N) dp[i][j] = -1e18;
    ll lst[K+1][N]; 
    dp[0][G] = 0;
    F0R(i, K) {
        F0R(j, N) {
            FOR(k, max(j, i+1), N) {
                if (ckmax(dp[i+1][k], dp[i][j] + max(0ll, X[i]-(k-j)*Y[i]))) {
                    lst[i+1][k] = k-j;
                }
            }
        }
    }

    int v = 0;
    FOR(i, 1, N) {
        if (dp[K][i] > dp[K][v]) v = i;
    }

    vi res;
    int p = 0;
    FORd(i, 1, K+1) {
        res.pb(0);
        F0R(j, lst[i][v]) {
            if (cov[p] < N) {
                res.pb(cov[p]+1);
            } else {
                res.pb(-1*(cov[p]-N+1));
            }
            p++;
        }
        v -= lst[i][v];
    }
    reverse(all(res));
    cout << sz(res) << nl;
    trav(a, res) {
        cout << a << " ";
    }
    cout << nl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}