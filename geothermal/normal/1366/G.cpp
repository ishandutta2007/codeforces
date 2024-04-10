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
const int MX = 10011; //check the limits, dummy

int dp[MX][MX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string S, T; cin >> S >> T;
    int N = sz(S), M = sz(T);
    int burnPos[N];
    F0R(p, N) {
        burnPos[p] = N+1;
        if (S[p] == '.') continue;
        int cnt = 0;
        FOR(j, p, N) {
            cnt++; if (S[j] == '.') cnt -= 2;
            if (cnt == 0) {
                burnPos[p] = j; break;
            }
        }
    }

    F0R(i, N+1) F0R(j, M+1) dp[i][j] = N*2;

    dp[0][0] = 0;
    F0R(i, N) {
        F0R(j, M+1) {
            if (S[i] == '.') {
                if (j > 0) {
                    dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j]);
                }
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            } else {
                if (j < M && S[i] == T[j]) {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                }
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
                if (burnPos[i] < N) {
                    dp[burnPos[i]+1][j] = min(dp[burnPos[i]+1][j], dp[i][j]);
                }
            }
        }
    }
/*    F0R(i, N+1) {
        F0R(j, M+1) {
            cout << dp[i][j] << " " << i << " " << j << nl;
        }
    }*/
    cout << dp[N][M] << nl;


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343