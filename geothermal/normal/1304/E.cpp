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
 
const int L = 18; 
int anc[MX][L];
int depth[MX];
int parent[MX];

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int c = b;
        b = a;
        a = c;
    }

    int dist = depth[a] - depth[b];
    while (dist > 0) {
        F0R(i, L) {
            if (dist & 1 << i) {
                a = anc[a][i];
                dist -= 1 << i;
            }
        }
    }

    if (a == b) return a;

    F0Rd(j, L) {
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]) {
            a = anc[a][j]; b = anc[b][j];
        }
    }
    return parent[a];
}

void preprocess(int N) {
    //make sure to compute parents and depths
    F0R(i, N) F0R(j, L) anc[i][j] = -1;
    F0R(i, N) anc[i][0] = parent[i];
    FOR(j, 1, L) {
        F0R(i, N) {
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
            }
        }
    }
}
vector<vi> graph;
void dfs(int v, int p, int d) {

    depth[v] = d;
    parent[v] = p;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (p == nxt) continue;
        dfs(nxt, v, d+1);
    }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    graph = vector<vi>(N);
    F0R(i, N-1) {
        int A, B; cin >> A >> B;
        A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }

    dfs(0, -1, 0);

    preprocess(N);
    int Q; cin >> Q;

    F0R(i, Q) {
        int X, Y, A, B, K; cin >> X >> Y >> A >> B >> K;
        X--; Y--; A--; B--;
        int dist1 = depth[A] + depth[B] - 2*depth[LCA(A, B)];
        int pre1 = depth[A] + depth[X] - 2*depth[LCA(A, X)];
        int pre2 = depth[B] + depth[Y] - 2*depth[LCA(B, Y)];
        int dist2 = pre1 + pre2 + 1;
        int pre3 = depth[A] + depth[Y] - 2*depth[LCA(A, Y)];
        int pre4 = depth[B] + depth[X] - 2*depth[LCA(B, X)];
        int dist3 = pre3 + pre4 + 1;

        int V1 = K - dist1;
        int V2 = K - dist2;
        int V3 = K - dist3;
        if ((V1 >= 0 && V1 % 2 == 0) || (V2 >= 0 && V2 % 2 == 0) || (V3 >= 0 && V3 % 2 == 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343