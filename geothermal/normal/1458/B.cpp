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
 
int dp[101][101][10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int A[N], B[N]; F0R(i, N) cin >> A[i] >> B[i];
    F0R(i, N+1) F0R(k, N+1) F0R(j, 10001) dp[i][k][j] = -1000000000;
    dp[0][0][0] = 0;
    int sum = 0;
    F0R(i, N) {
        sum += B[i];
        F0R(j, N+1) {
            F0R(k, 10001) {
                if (j < N && k + A[i] <= 10000) {
                    ckmax(dp[i+1][j+1][k+A[i]], dp[i][j][k] + B[i]);
                }
                ckmax(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    FOR(i, 1, N+1) {
        ld ans = 0;
        F0R(j, 10001) {
            ckmax(ans, (min( ((ld) dp[N][i][j] + sum) / 2, (ld) j))); 
        }
        cout << setprecision(20) << ans << " ";
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343