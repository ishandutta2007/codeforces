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
	
    int N, M; cin >> N >> M;
    int L[N][M], R[N][M];
    F0R(i, N) {
        int K; cin >> K;
        F0R(j, K) {
            int l, r; cin >> l >> r;
            l--; r--;
            FOR(k, l, r+1) {
                L[i][k] = l;
                R[i][k] = r;
            }
        }
    }

    int dp[M][M];
    F0R(i, M) {
        int cnt = 0;
        F0R(j, N) {
            if (L[j][i] == R[j][i]) cnt++;
        }
        dp[i][i] = cnt*cnt;
    }
    F0R(d, M) {
        F0R(i, M) {
            int j = i+d;
            if (j >= M) continue;
            dp[i][j] = 0;
            FOR(k, i, j+1) {
                int cur = 0;
                F0R(l, N) {
                    if (L[l][k] >= i && R[l][k] <= j) cur++;
                }
                cur *= cur;
                if (i != k) cur += dp[i][k-1];
                if (j != k) cur += dp[k+1][j];
                ckmax(dp[i][j], cur);
            }
        }
    }
    cout << dp[0][M-1] << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343