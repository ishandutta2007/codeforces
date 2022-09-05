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
const int MX = 3001; //check the limits, dummy

int depth1[MX], depth2[MX], N;
vector<vi> graph1, graph2;
int p1[MX], p2[MX];
int lca1[MX][MX], lca2[MX][MX];

vi dfs1(int v, int p) {
    if (p == -1) {
        depth1[v] = 0;
    } else {
        depth1[v] = depth1[p]+1;
    }
    vi leaves;
    if (sz(graph1[v]) == 1 && p != -1) {
        F0R(i, N) if (p1[i] == v) leaves.pb(i);
    }
    F0R(i, sz(graph1[v])) {
        int nxt = graph1[v][i];
        if (nxt == p) continue;
        vi newLeaves = dfs1(nxt, v);
        F0R(a, sz(leaves)) {
            F0R(b, sz(newLeaves)) {
                int x = leaves[a];
                int y = newLeaves[b];
                lca1[x][y] = depth1[v];
                lca1[y][x] = depth1[v];
            }
        }
        F0R(a, sz(newLeaves)) {
            leaves.pb(newLeaves[a]);
        }
    }
    return leaves;
}
vi dfs2(int v, int p) {
    if (p == -1) {
        depth2[v] = 0;
    } else {
        depth2[v] = depth2[p]+1;
    }
    vi leaves;
    if (sz(graph2[v]) == 1 && p != -1) {
        F0R(i, N) if (p2[i] == v) leaves.pb(i);
    }
    F0R(i, sz(graph2[v])) {
        int nxt = graph2[v][i];
        if (nxt == p) continue;
        vi newLeaves = dfs2(nxt, v);
        F0R(a, sz(leaves)) {
            F0R(b, sz(newLeaves)) {
                int x = leaves[a];
                int y = newLeaves[b];
                lca2[x][y] = depth2[v];
                lca2[y][x] = depth2[v];
            }
        }
        F0R(a, sz(newLeaves)) {
            leaves.pb(newLeaves[a]);
        }
    }
    return leaves;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    int A; cin >> A;
    F0R(i, A) {
        vi blank; graph1.pb(blank);
    }
    F0R(i, A-1) {
        int P; cin >> P; P--;
        graph1[P].pb(i+1);
        graph1[i+1].pb(P);
    }
    F0R(i, N) {
        cin >> p1[i]; p1[i]--;
    }

    int B; cin >> B;
    F0R(i, B) {
        vi blank; graph2.pb(blank);

    }

    F0R(i, B-1) {
        int P; cin >> P; P--;
        graph2[P].pb(i+1);
        graph2[i+1].pb(P);
    }
    F0R(i, N) {
        cin >> p2[i]; p2[i]--;
    }
    dfs1(0, -1); 
    dfs2(0, -1);

    int dp[N+1][N+1];
    F0R(i, N+1) {
        F0R(j, N+1) {
            dp[i][j] = MX*10;
        }
    }

    dp[0][0] = 0;
    dp[0][1] = depth2[p2[0]];
    dp[1][0] = depth1[p1[0]];
    FOR(i, 2, N+1) {
        F0R(j, i) {
            //dp[i-1][j] to dp[i][j] or dp[i-1][i]
            dp[i][j] = min(dp[i][j], depth1[p1[i-1]] - lca1[i-2][i-1] + dp[i-1][j]);
            if (j != 0) dp[i-1][i] = min(dp[i-1][i], depth2[p2[i-1]] - lca2[i-1][j-1] + dp[i-1][j]);
            if (j == 0) dp[i-1][i] = min(dp[i-1][i], depth2[p2[i-1]] + dp[i-1][j]);
        }
        F0R(j, i) {
            dp[j][i] = min(dp[j][i], depth2[p2[i-1]] - lca2[i-1][i-2] + dp[j][i-1]);
            if (j != 0) dp[i][i-1] = min(dp[i][i-1], depth1[p1[i-1]] - lca1[j-1][i-1] + dp[j][i-1]);
            if (j == 0) dp[i][i-1] = min(dp[i][i-1], depth1[p1[i-1]] + dp[j][i-1]);
        }
    }
    F0R(i, N) {
        F0R(j, N) {
//            cout << dp[i][j] << " " << i << " " << j << endl;
        }
    }

    int ans = MX*10;
    F0R(i, N) {
        ans = min(ans, dp[i][N]);
        ans = min(dp[N][i], ans);
    }

    cout << A+B-2-ans << endl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343