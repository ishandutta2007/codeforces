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
const int MX = 100001; //check the limits, dummy

struct Edge
{
    ll from, to, capacity, cost;
};

vector<vector<ll >> adj, cost, capacity;

const ll INF = 1e15;

void shortest_paths(int n, int v0, vector<ll>& d, vector<ll>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<ll> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        inq[u] = false;
        for (ll v : adj[u]) {
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

ll min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<ll>());
    cost.assign(N, vector<ll>(N, 0));
    capacity.assign(N, vector<ll>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    ll flow = 0;
    ll cost = 0;
    vector<ll> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        ll f = K - flow;
        ll cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        vl A(N), B(N); F0R(i, N) cin >> A[i] >> B[i];

        vector<Edge> edges; //0..N-1 monsters, N...N+K-1 values, N+K source, N+K+1 sink
        F0R(i, N) {
            F0R(j, K) {
                edges.pb({i, N+j, 1, 1000000000-A[i]+j*B[i]});
            }
        }
        F0R(i, N) {
            edges.pb({N+K, i, 1, 0});
        }
        F0R(i, K) {
            edges.pb({N+i, N+K+1, 1, 0});
        }

        int val[N]; F0R(i, N) val[i] = -1;
        ll ans = min_cost_flow(N+K+2, edges, K, N+K, N+K+1);
        F0R(i, N) {
            FOR(j, N, N+K) {
                if (capacity[i][j] == 0) {
                    val[i] = j-N;
                }
            }
        }
        cout << N*2-K << nl;
        FORd(iter, 1, K) {
            F0R(i, N) {
                if (val[i] == iter) {
                    cout << i+1 << " ";
                }
            }
        }

        F0R(i, N) {
            if (val[i] == -1) {
                cout << i+1 << " " << -i-1 << " ";
            }
        }

        F0R(i, N) {
            if (val[i] == 0) {
                cout << i+1 << nl;
            }
        }

/*        ll ans = min_cost_flow(N+K+2, edges, K, N+K, N+K+1);
        ll res = 0; F0R(i, N) res += B[i] * (K-1);
        res += (1000000000ll) * K;
        res -= ans;
        cout << res << nl;*/
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343