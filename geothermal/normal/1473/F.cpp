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

    int N; cin >> N;
    vi A(N); F0R(i, N) cin >> A[i];
    ll B[N]; F0R(i, N) cin >> B[i];
    Dinic flow(N+2, N, N+1);
    vi lst(101, -1);
    ll sum = 0;
    F0R(i, N) {
        if (B[i] > 0) {
            flow.add_edge(N, i, B[i]);
            sum += B[i];
        } else if (B[i] < 0) {
            flow.add_edge(i, N+1, -B[i]);
        }
        FOR(j, 1, A[i]+1) {
            if (lst[j] != -1 && A[i]%j == 0) {
                flow.add_edge(i, lst[j], 1e10);
            }
        }
        lst[A[i]] = i;
    }

    cout << sum - flow.flow() << nl;

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