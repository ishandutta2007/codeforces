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

void solve() {

    ll X, Y; cin >> X >> Y;
    vl A, B;
    F0R(i, 32) {
        A.pb(X%2);
        B.pb(Y%2); 
        X /= 2;
        Y /= 2;
    }
    /*int K = 0;
    F0R(i, 32) K += A[i] - B[i];
    if (K > 0) {
        K++;
        int num = K;
        int p;
        F0R(i, 32) {
            if (A[i]) {
                num--;
                if (num  == 0) {
                    p = i; break;
                }
            }
        }
        while (A[p+1]) p++;
        A[p+1] = 1;
        while (K > 0) {
            if (A[p]) {
                A[p] = 0; K--;
            }
            p--;
        }
    }
    int sum = 0;
    F0R(i, 32) {
        sum += A[i] - B[i];
        if (sum < 0) {
            cout << "NO" << nl; return;
        }
    }
    cout << "YES" << nl;*/

    bool dp[32][32];
    F0R(i, 32) F0R(j, 32) dp[i][j] = 0;
    dp[0][0] = true;
    F0R(i, 31) {
        FOR(j, 1, 32) {
            if (A[i] == 0 && dp[i][j]) dp[i][1] = true;
        }
        F0R(j, 32) {
            if (!dp[i][j]) continue;
            int k = j + A[i] - B[i];
            if (k >= 0 && k < 32) {
                dp[i+1][k] = true;
            }

        }
    }
    
    cout << (dp[31][0]?"YES":"NO") << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343