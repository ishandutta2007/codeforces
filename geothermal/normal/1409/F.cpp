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
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, K; cin >> N >> K;
    string S; cin >> S;
    string T; cin >> T;

    if (T[0] == T[1]) {
        int cnt = 0;
        trav(a, S) cnt += T[0] == a;
        cnt += K; ckmin(cnt, sz(S));
        cout << (cnt*(cnt-1))/2 << nl; return 0;
    }

    int dp[N+1][N+1][K+1];
    F0R(i, N+1) F0R(j, N+1) F0R(k, K+1) dp[i][j][k] = -1e9;
    dp[0][0][0] = 0;
    F0R(i, N) {
        F0R(j, N) {
            F0R(k, K+1) {
                if (k < K || S[i] == T[0]) {
                    int cost = 0; if (S[i] != T[0]) cost = 1;
                    ckmax(dp[i+1][j+1][k+cost], dp[i][j][k]);
                }
                if (k < K || S[i] == T[1]) {
                    int cost = 0; if (S[i] != T[1]) cost = 1;
                    ckmax(dp[i+1][j][k+cost], dp[i][j][k] + j);
                }
                ckmax(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }
    int ans = 0;
    F0R(i, N+1) F0R(j, K+1) ckmax(ans, dp[N][i][j]);
    cout << ans << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343