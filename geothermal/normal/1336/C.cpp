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
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string S; cin >> S;
    string T; cin >> T;
    int N = sz(S), M = sz(T);
    ll get[M+1][M+1]; //number of ways to get [i, j)
    F0R(i, M+1) {
        F0R(j, M+1) get[i][j] = 0; 
    }
    F0R(i, M+1) get[i][i] = 1;
    F0R(dif, M) {
        F0R(i, M+1) {
            int j = i+dif;
            if (j > M) continue;
            if (i > j) continue;
            //go from i, j to 
            char C = S[dif];
            if (i > 0 && T[i-1] == C) {
                get[i-1][j] += get[i][j]; get[i-1][j] %= MOD;
            }
            if (j < M && T[j] == C) {
                get[i][j+1] += get[i][j]; get[i][j+1] %= MOD;
            }
        }
    }
    ll ans = 0;
    ll dp[N+1][M+1]; //taken M+1 from the first N
    F0R(i, N+1) {
        F0R(j, M+1) {
            dp[i][j] = 0;
        }
    }
    FOR(i, M+1, N+1) {
        dp[i][0] = 1;
    }
    ans = get[0][M];
    if (N == M) {
        cout << get[0][M] << nl; return 0;
    }
    //ONLY add to answer after transition involving not using 
    FORd(i, 1, N+1) {
        F0R(j, M+1) {
            if (M-j == i-1) {
                ans += get[j][M] * dp[i][j]; ans %= MOD; //no useless's left
            } else {
                dp[i-1][j] += dp[i][j]; dp[i-1][j] %= MOD;
            }
            if (j != M && S[i-1] == T[j]) { //useful front
                dp[i-1][j+1] += dp[i][j]; dp[i-1][j+1] %= MOD;
            } else if (j == M) { //useless front
                if (M-j == i-1) {
                    ans += get[j][M] * dp[i][j]; ans %= MOD;
                } else {
                    dp[i-1][j] += dp[i][j]; dp[i-1][j] %= MOD;
                }
            }
        }
    }

    cout << ans << nl;

/*    F0R(i, N+1) {
        F0R(j, M+1) {
            cout << dp[i][j] << " " << i << " " << j << nl;
        }
    }

    cout << nl;
    F0R(i, M+1) {
        F0R(j, M+1) {
            cout << "GET " << i << " " << j << ": " << get[i][j] << nl;
        }
    }*/


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343