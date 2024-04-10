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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int A[N+1]; F0R(i, N) cin >> A[i];
    A[N] = -1;
    if (N == 1) {
        cout << 0 << endl; return 0;
    }
    int K = (N+3)/2;
    int dp[N][K][3];
    F0R(i, N) F0R(j, K) F0R(k, 3) dp[i][j][k] = 1e9;
    dp[0][0][0] = 0; //do nothing
    dp[0][1][1] = max(0, A[1] - A[0] + 1);

    F0R(i, N-1) {
        F0R(j, K) {
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0]); //from 0, do not use
            if (j != K-1) dp[i+1][j+1][1] = min(dp[i+1][j+1][1], dp[i][j][0] + max(0, A[i] - A[i+1] + 1) + max(0, A[i+2] - A[i+1] + 1));
            dp[i+1][j][2] = min(dp[i+1][j][2], dp[i][j][1]);
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][2]);
            if (i != 0 && j != K-1) dp[i+1][j+1][1] = min(dp[i+1][j+1][1], dp[i][j][2] + max(0, min(A[i], A[i-1]-1) - A[i+1] + 1) + max(0, A[i+2] - A[i+1] + 1));
        }
    }

    FOR(i, 1, (N+3)/2) {
        int ans = 1000000000;
        F0R(j, 3) {
            ans = min(ans, dp[N-1][i][j]);
        }
        cout << ans << " ";
    }
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343