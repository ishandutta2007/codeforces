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
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy


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

vector<vpl> graph;
int depth[MX], parent[MX];
int K;
int anc[MX][18]; ll maxVal[MX][18];
ll weightDown[MX];

void dfs(int v, int p) {
    if (p == -1) {
        depth[v] = 0;
    } else {
        depth[v] = depth[p]+1;
    }
    parent[v] = p;
    weightDown[v] = 0;

    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i].f;
        if (nxt == p) {
            weightDown[v] = graph[v][i].s;
            //cout << v << " " << weightDown[v] << endl;

            continue;
        }
        dfs(nxt, v);
    }
}

void precomp() {
    F0R(i, K) {
        F0R(j, 18) {
            anc[i][j] = -1;
        }
        anc[i][0] = parent[i];
        maxVal[i][0] = weightDown[i];
    }
    FOR(j, 1, 18) {
        F0R(i, K) {
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                maxVal[i][j] = max(maxVal[i][j-1], maxVal[anc[i][j-1]][j-1]);
            }
        }
    }
}

ll distVal(int A, int B) {
    if (depth[A] < depth[B]) {
        int C = B;
        B = A;
        A = C;
    }

    int dist = depth[A] - depth[B];
    ll ans = 0;
    while (dist > 0) {
        F0R(i, 18) {
            if (dist & (1 << i)) {
                ans = max(ans, maxVal[A][i]);
                //cout << ans << " " << maxVal[A][i] << endl;
                A = anc[A][i];
                dist -= 1 << i;
            }
        }
    }
    if (A == B) return ans;
    F0Rd(j, 18) {
        if (anc[A][j] != -1 && anc[A][j] != anc[B][j]) {
            ans = max(ans, max(maxVal[A][j], maxVal[B][j]));
            A = anc[A][j]; B = anc[B][j];
        }
    }
    ans = max(ans, max(weightDown[A], weightDown[B]));
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M, Q; cin >> N >> M >> K >> Q;

    F0R(i, N) {
        vpl blank; graph.pb(blank);
    }

    F0R(i, M) {
        int A, B, C; cin >> A >> B >> C;
        A--; B--;
        graph[A].pb({B, C});
        graph[B].pb({A, C});
    }

    vector<pair<ll, pi> > edges;
    int owner[N]; F0R(i, N) owner[i] = -1;
    ll dist[N]; F0R(i, N) dist[i] = 1000000000000000;
    bool visited[N]; F0R(i, N) visited[i] = false;
    F0R(i, K) visited[i] = true;
    F0R(i, K) {
        owner[i] = i; dist[i] = 0;
    }

    priority_queue<pair<ll, pi>> q; //dist, next, owner
    F0R(i, K) {
        F0R(j, sz(graph[i])) {
            q.push({graph[i][j].s*-1, {graph[i][j].f, i}});
        }
    }

    while (!q.empty()) {
        pair<ll, pi> curData = q.top(); q.pop();
        ll curDist = curData.f * -1;
        int curOwn = curData.s.s;
        int cur = curData.s.f;
        if (visited[cur]) {
            if (owner[cur] != curOwn) {
                edges.pb({curDist + dist[cur], {curOwn, owner[cur]}});
            }
            continue;
        }
        visited[cur] = true;
        dist[cur] = curDist;
        owner[cur] = curOwn;

        F0R(i, sz(graph[cur])) {
            
            int nxt = graph[cur][i].f;
            ll nxtDist = curDist + graph[cur][i].s;
            //cout << cur << " " << dist[cur] << " " << owner[cur] << " " << nxt << " " << nxtDist << endl;
            q.push({nxtDist*-1, {nxt, curOwn}});
        }
    }

    //build MST
    vector<vpl> mst;
    F0R(i, K) {
        vpl blank; mst.pb(blank);
    }
    DSU<MX> dsu;
    sort(all(edges));
    F0R(i, sz(edges)) {

        int A = edges[i].s.f, B = edges[i].s.s;
        ll dist = edges[i].f;
        //cout << A << " " << B << " " << dist << " edge" << endl;
        if (dsu.get(A) != dsu.get(B)) {
            dsu.unify(A, B);
            mst[A].pb({B, dist});
            mst[B].pb({A, dist});
        }

    }
    graph = mst;

    dfs(0, -1);
    precomp();

    F0R(i, Q) {
        int A, B; cin >> A >> B; A--; B--;
        cout << distVal(A, B) << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343