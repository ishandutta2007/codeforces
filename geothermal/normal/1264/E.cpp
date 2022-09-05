#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const int MX = 100001; //check the limits, dummy
 struct Edge
{
    int from, to, capacity, cost;
    Edge(int A, int B, int C, int D) {
        from = A; 
        to = B;
        capacity = C;
        cost = D;
    }
};
 
vector<vector<int>> adj, cost, capacity;
 
const int INF = 1e9;
 
void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
 
int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }
 
    int flow = 0;
    int curcost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;
 
        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
 
        // apply flow
        flow += f;
        curcost += f * d[t];
        cur = t;
        cost[p[cur]][cur]++;
        cost[cur][p[cur]] = max(0, cost[p[cur]][cur]);
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
 
    if (flow < K) {
        cout << K << " " << flow << endl;
        assert(false);
        return -1; 
    
     } else
        return curcost;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    vpi edges;
    vpi used;
    int cnt[N]; F0R(i, N) cnt[i] = 0;
    bool isUsed[N][N]; F0R(i, N) F0R(j, N) isUsed[i][j] = false;
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--; 
        used.pb({A, B});
        cnt[B]++;
        isUsed[A][B] = true;
        isUsed[B][A] = true;
    }

    vector<Edge> graph;
    //source = 0;
    F0R(i, N) {
        FOR(j, i+1, N) {
            if (!isUsed[i][j]) {
                edges.pb({i, j});
            }
        }
    }

    F0R(i, sz(edges)) {
        Edge e(0, i+1, 1, 0); 
        Edge e2(i+1, sz(edges)+1+edges[i].f, 1, 0);
        Edge e3(i+1, sz(edges)+1+edges[i].s, 1, 0);
        graph.pb(e); graph.pb(e2); graph.pb(e3);
    }

    F0R(i, N) {
                Edge e(sz(edges)+1+i, sz(edges)+1+N, N+1, cnt[i]);
                graph.pb(e);
    }
    F0R(i, sz(graph)) {
//        cout << graph[i].from << " " << graph[i].to << endl;
    }

    ll cost = min_cost_flow(sz(edges)+2+N, graph, N*(N-1)/2-M, 0, sz(edges)+1+N);
//    cout << cost << endl;

    bool ans[N][N]; F0R(i, N) F0R(j, N) ans[i][j] = false;
    F0R(i, sz(used)) {
        ans[used[i].f][used[i].s] = true;
    }

    F0R(i, sz(edges)) {
        if (capacity[i+1][sz(edges)+1+edges[i].f] == 0) {
            ans[edges[i].s][edges[i].f] = true;
        } else if (capacity[i+1][sz(edges)+1+edges[i].s] == 0) {
            ans[edges[i].f][edges[i].s] = true;
        }
    }

    F0R(i, N) {
        F0R(j, N) {
            cout << (ans[i][j]?1:0);
        }
        cout << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343