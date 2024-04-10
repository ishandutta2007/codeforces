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
const int MX = 6000; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, K; cin >> N >> K;
    vl A(N); F0R(i, N) cin >> A[i];

    vl X(N), Y(N);

    F0R(i, N) {
        int x = 0;
        while (A[i] % 5 == 0) {
            x++;
            A[i] /= 5;
        }
        int y = 0;
        while (A[i] % 2 == 0) {
            y++; A[i] /= 2;
        }
        X[i] = x;
        Y[i] = y;
    }

    ll dp[K+1][MX];
    ll nxt[K+1][MX];
    F0R(i, K+1) F0R(j, MX) dp[i][j] = -1000000;
    dp[0][0] = 0;
    F0R(i, N) {
        F0R(j, K+1) {
            F0R(k, MX) {
                nxt[j][k] = -1000000;
            }
        }
        F0R(j, K+1) {
            F0R(k, MX) {
                if (dp[j][k] < 0) continue;
                ckmax(nxt[j][k], dp[j][k]);
                if (j < K) {
                    nxt[j+1][k+X[i]] = max(nxt[j+1][k+X[i]], dp[j][k] + Y[i]);
                }
            }
        }
        F0R(j, K+1) {
            F0R(k, MX) {
                dp[j][k] = nxt[j][k];
            }
        }
    }
    ll ans = 0;
    F0R(i, MX) {
        ckmax(ans, min(dp[K][i], (ll) i));
    }

    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343