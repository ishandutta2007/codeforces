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
	
    int T; cin >> T;
    string dp[501][2];
    while(T--) {
        int N, K; cin >> N >> K;
        F0R(i, N+1) {
            F0R(j, 2) {
                dp[i][j] = "~";
            }
        }
        string S; cin >> S;
        dp[0][0] = S;
        F0R(i, N) {
            F0R(j, 2) {
                if (dp[i][j][0] == '~') continue;
                int p = i; if (j) p--;
                string cur = dp[i][j];
                if (p > 0 && dp[i][j][p-1] > dp[i][j][p]) {
                    swap(cur[p-1], cur[p]);
                    ckmin(dp[i+1][0], cur);
                } else {
                    char nxt = cur[p];
                    if (cur[p] == 'a' + K - 1) {
                        nxt = 'a';
                    } else if (cur[p] != 'a') {
                        nxt--;
                    }
                    cur[p] = nxt;
                    ckmin(dp[i+1][0], cur);
                }
                if (j == 0 && p < N-1) {
                    cur = dp[i][j];
                    swap(cur[p], cur[p+1]);
                    ckmin(dp[i+1][1], cur);
                }

            }
        }
        cout << dp[N][0] << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343