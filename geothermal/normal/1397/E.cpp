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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; ll X, Y, Z, D; cin >> N >> X >> Y >> Z >> D;
    ll A[N]; F0R(i, N) cin >> A[i];
    ll dp[N+1][3]; F0R(i, N+1) F0R(j, 3) dp[i][j] = 1e18;
    dp[0][0] = 0;
    ll cs = 0;
    F0R(i, N) {
        F0R(j, 3) {
            ll costZed = X * A[i] + Z;
            ll costOne = min(X * (A[i] + 1), Y);
            costOne += X; ckmin(costOne, costZed);
            if (j == 0 && i >= N-2) cs += costOne;
//            cout << "Costs at " << i << " " << costZed << " " << costOne << nl;
            ll T = D; ll ind = 0; if (i == N-1) ind = 2*D;
            if (j == 0) {
                ckmin(dp[i+1][0], dp[i][j] + costZed);
                ckmin(dp[i+1][1], dp[i][j] + costOne+ind);
                ckmin(dp[i+1][2], dp[i][j] + costOne+ind); //go back at the end
            } else if (j == 1) {
                ckmin(dp[i+1][0], dp[i][j] + costZed + T*2);
                ckmin(dp[i+1][0], dp[i][j] + costOne + T*2+ind/2);
                ckmin(dp[i+1][1], dp[i][j] + costOne + T*2+ind/2);
                ckmin(dp[i+1][2], dp[i][j] + costOne + T*2+ind/2);
            } else {
                if (i != N-1) {
                    ckmin(dp[i+1][2], dp[i][j] + costOne + T);
                } else {
                    ckmin(dp[i+1][2], dp[i][j] + costZed + T);
                    ckmin(dp[i+1][2], dp[i][j] + costOne + T*3);
                }
            }
        }
    }
    ll ans = min(dp[N][0], min(dp[N][1], dp[N][2]));
/*    cout << ans << nl;
    F0R(i, N+1) {
        F0R(j, 3) {
            cout << dp[i][j] << " ";
        }
        cout << nl;
    }*/
    ckmin(ans, dp[N-2][0] + cs + D*2);
//    cout << ans << nl;
/*    dp[N-2][1] = 1e18; dp[N-2][2] = 1e18;

    FOR(i, N-2, N) {
        F0R(j, 3) {
            ll costZed = X * A[i] + Z;
            ll costOne = min(X * (A[i] + 1), Y);
            costOne += X; ckmin(costOne, costZed);
            ll T = D;
            if (j == 0) {
                ckmin(dp[i+1][0], dp[i][j] + costZed);
                ckmin(dp[i+1][1], dp[i][j] + costOne);
                ckmin(dp[i+1][2], dp[i][j] + costOne); //go back at the end
            } else if (j == 1) {
                ckmin(dp[i+1][0], dp[i][j] + costOne + T*2);
                ckmin(dp[i+1][1], dp[i][j] + costOne + T*2);
                ckmin(dp[i+1][2], dp[i][j] + costOne + T*2);
            } else {
                ckmin(dp[i+1][2], dp[i][j] + costOne + T);
            }
        }
    }
    ckmin(ans, dp[N][2]);
    cout << dp[N][2] << nl;*/
    cout << ans + D * (N-1) << nl;


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343