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
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; ll K; cin >> N >> K;
    ll A[N], B[N]; F0R(i, N) cin >> A[i] >> B[i];

    ll dp[N+1][K];
    F0R(i, N+1) {
        F0R(j, K) {
            dp[i][j] = -1000000000000000;
        }
    }
    dp[0][0] = 0;
    ll sum = 0;
    F0R(i, N) {
        for (ll nr = 0; nr < K; nr++) {
            if (dp[i][nr] < 0) continue;
            ll nb = (sum - nr) % K;
            for (ll nxtr = 0; nxtr < min(K, A[i]+1); nxtr++) {
                ll rem = A[i] + B[i] - nxtr;
                ll inp = rem / K;
                ll nxtb = rem % K; if (B[i] < nxtb) continue;
                ll res = dp[i][nr] + inp;
                ll xr = nr + nxtr, xb = nb + nxtb;
                if (xr >= K) {
                    xr-=K; res++;
                }
                if (xb >= K) {
                    xb-=K; res++;
                }
                dp[i+1][xr] = max(dp[i+1][xr], res);
            }
        }
        sum += A[i] + B[i];
    }
    ll ans = 0;
    F0R(i, K) {
        ans = max(dp[N][i], ans);
    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343