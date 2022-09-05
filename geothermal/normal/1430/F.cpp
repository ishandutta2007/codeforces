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
	
    int N; ll K; cin >> N >> K;
    ll L[N], R[N]; ll A[N]; F0R(i, N) cin >> L[i] >> R[i] >> A[i];

    map<ll, ll> dp[N+1];
    dp[0][K] = 0;
    F0R(i, N) {
        trav(a, dp[i]) {
            ll rl = (A[i] - a.f + K - 1) / K;
            if (L[i] + rl <= R[i]) {
                ll rem = a.f + rl * K - A[i];
                if (!dp[i+1].count(rem)) {
                    dp[i+1][rem] = 1e18;
                }
                ckmin(dp[i+1][rem], a.s + A[i]);
            }
            if (L[i] + rl < R[i] || (L[i] + rl <= R[i] && i != N-1 && R[i] < L[i+1])) {
                if (!dp[i+1].count(K)) {
                    dp[i+1][K] = 1e18;
                }
                ckmin(dp[i+1][K], a.s + a.f + rl * K);
            }
        }
    }
    if (sz(dp[N]) == 0) {
        cout << -1 << nl; return 0;
    }
    ll ans = 1e18;
    trav(a, dp[N]) {
        ckmin(ans, a.s);
    }
    cout << ans << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343