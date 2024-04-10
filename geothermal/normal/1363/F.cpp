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
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N; string S, T; cin >> S >> T;
        int cntS[N+1][26], cntT[N+1][26];
        F0R(i, 26) cntS[0][i] = 0;
        F0R(i, 26) cntT[0][i] = 0;
        F0R(i, N) {
            F0R(j, 26) {
                cntS[i+1][j] = cntS[i][j];
                cntT[i+1][j] = cntT[i][j];
            }
            cntS[i+1][S[i] - 'a']++;
            cntT[i+1][T[i] - 'a']++;
        }
        int dp[N+1][N+1];
        F0R(i, 26) {
            if (cntS[N][i] != cntT[N][i]) {
                cout << -1 << nl; goto done;
            }
        }
        F0R(i, N+1) F0R(j, N+1) dp[i][j] = N*N;
        dp[0][0] = 0;
        F0R(i, N+1) {
            F0R(j, N+1) {
                if (i < N && j < N && S[i] == T[j]) {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                } 
                if (i < N && cntS[i][S[i] - 'a'] < cntT[j][S[i] - 'a']) { //if letter stolen
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                }
                if (j < N) {
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
                }
            }
        }
/*        F0R(i, N+1) {
            F0R(j, N+1) {
                cout << dp[i][j] << " ";
            }
            cout << nl;
        }*/
        cout << dp[N][N] << nl;
        done:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343