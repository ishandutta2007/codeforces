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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, K; cin >> N >> K;
    N += 2;
    int dp[N][N][K][2];

    F0R(i, N) F0R(j, N) F0R(k, K) {
        dp[i][j][k][0] = 100000;
        dp[i][j][k][1] = 100000;
    }
    FOR(i, 1, N-1) {
        dp[i][N-1][0][0] = 0;
        dp[0][i][0][1] = 0;
    }

    vector<vpi> graph(N);
    int M; cin >> M;
    F0R(i, M) {
        int A, B; cin >> A >> B; int C; cin >> C;
        graph[A].pb({B, C});
    }

    F0R(k, K-1) {
        F0R(i, N) {
            FOR(j, i+1, N) {
                F0R(p, 2) {
                    int v = i;
                    if (p == 1) v = j;
                    F0R(index, sz(graph[v])) {
                        int nxt = graph[v][index].f;
                        int cost = graph[v][index].s + dp[i][j][k][p];
                        if (nxt <= i || nxt >= j) continue;
                        dp[i][nxt][k+1][1] = min(dp[i][nxt][k+1][1], cost);
                        dp[nxt][j][k+1][0] = min(dp[nxt][j][k+1][0], cost);
                    }
                }
            }
        }
    }

    int ans = 100000;
    F0R(i, N) {
        F0R(j, N) {
            F0R(k, 2) {
                ans = min(ans, dp[i][j][K-1][k]);
            }
        }
    }
    if (ans >= 100000) {
        cout << -1 << endl; return 0;
    }
    cout << ans << endl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343