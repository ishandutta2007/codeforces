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
	
    int N, M; cin >> N >> M;
    vpi data; F0R(i, N) {
        int A, B; cin >> A >> B;
        data.pb({A, B});

    }
    sort(all(data));
    int X[N], S[N]; F0R(i, N) {
        X[i] = data[i].f;
        S[i] = data[i].s;
    }
    int oM = M;
    M = 300010;

    int dp[M+1][N+1]; F0R(i, M+1) F0R(j, N+1) dp[i][j] = 10000000;

    dp[0][0] = 0;

    FOR(i, 1, N+1) {
        F0R(j, M+1) {
           dp[j][i] = min(dp[j][i], dp[j][i-1]); 
        }
        FOR(j, X[i-1] + S[i-1], M+1) {
            int cst = j - X[i-1] - S[i-1];
            dp[j][i] = min(dp[j][i], dp[max(0, 2*X[i-1]-j-1)][i-1]+cst);
        }
        F0Rd(j, M) {
            dp[j][i] = min(dp[j][i], dp[j+1][i]);
        }
    }

    cout << dp[oM][N] << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343