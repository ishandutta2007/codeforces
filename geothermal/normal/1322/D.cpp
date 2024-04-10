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
const int MX = 2001; //check the limits, dummy

vi dp[MX][MX*2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) A[i]--;

    int C[N]; F0R(i, N) cin >> C[i];

    int P[N+M]; F0R(i, N+M) cin >> P[i];
    int ans = 0;
    F0R(lev, N+M) {
        vi cur = {0};
        F0Rd(i, N) {
            if (A[i] == lev) {
                vi nxt((sz(cur) + 2) / 2);
                trav(a, nxt) a = -1e9;
                F0R(j, sz(cur)) {
                    ckmax(nxt[(j+1)/2], cur[j] + P[lev] * (j+1) - C[i]);
                }
                dp[i][lev+1] = nxt;
                cur.pb(cur[sz(cur) - 1] - C[i]);
                F0Rd(j, sz(cur) - 1) {
                    ckmax(cur[j+1], cur[j] - C[i]);
                }
            } else if (sz(dp[i][lev]) > 0) {
                vi nxt((sz(dp[i][lev]) + 1) / 2); 
                trav(a, nxt) a = -1e9;
                F0R(j, sz(dp[i][lev])) {
                    ckmax(nxt[j/2], dp[i][lev][j] + j * P[lev]);
                }
                dp[i][lev+1] = nxt;
                while (sz(cur) < sz(dp[i][lev])) cur.pb(-1e9);
                F0R(j, sz(dp[i][lev])) ckmax(cur[j], dp[i][lev][j]);
            } 
        }
    }

    F0R(i, N) {
        F0R(j, N+M) {
/*            cout << "Last recruited " << i << " moving to level " << j << nl;
            trav(a, dp[i][j]) {
                cout << a << " ";
            }
            cout << nl;*/
            if (sz(dp[i][j]) > 0) ckmax(ans, dp[i][j][0]);
        }
    }

    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343