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
const int MX = 10000001; //check the limits, dummy

int sqf[MX];

void solve() {

    int N, K; cin >> N >> K;
    int A[N]; F0R(i, N) cin >> A[i];
    map<int, int> lst;
    set<int> bp;
    int nxt[N][K+1]; 
    F0Rd(i, N) {
        A[i] = sqf[A[i]];
        if (lst.count(A[i])) {
            bp.ins(lst[A[i]]);
        }
        lst[A[i]] = i;
        auto it = bp.begin();
        F0R(j, K+1) {
            if (it != bp.end()) {
                nxt[i][j] = *it;
                it++;
            } else {
                nxt[i][j] = N;
            }
        }
    }
    int dp[N+1][K+1];
    F0R(i, N+1) F0R(j, K+1) dp[i][j] = N+1;
    dp[0][0] = 0;
    F0R(i, N) {
        F0R(j, K+1) {
            F0R(k, K+1) {
                if (j+k > K) continue;
                ckmin(dp[nxt[i][k]][j+k], dp[i][j] + 1);
            }
        }
    }
    int ans = N+1; F0R(i, K+1) ckmin(ans, dp[N][i]);
    cout << ans << nl;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    F0R(i, MX) sqf[i] = i;
    for (int i = 2; i * i < MX; i++) {
        for (int j = i*i; j < MX; j += i*i) {
            while ((sqf[j] % (i*i)) == 0) sqf[j] /= i*i;
        }
    }

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343