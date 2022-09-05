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
        int N, M; cin >> N >> M;
        ll A[N][M]; F0R(i, N) F0R(j, M) cin >> A[i][j];

        ll INF = 1e18;
        ll ans = INF;
        ll D[N][M]; ll C[N][M];
        F0R(rx, N) {
            F0R(ry, M) {
                F0R(i, N) F0R(j, M) D[i][j] = INF;
                F0R(i, N) {
                    F0R(j, M) {
                        C[i][j] = INF;
                        ll goal = A[rx][ry] - rx - ry + i + j;
                        if (A[i][j] >= goal) C[i][j] = A[i][j] - goal;
                    }
                }
                D[0][0] = C[0][0];
                F0R(i, N) {
                    F0R(j, M) {
                        if (i < N-1) {
                            D[i+1][j] = min(D[i+1][j], D[i][j] + C[i+1][j]);
                        }
                        if (j < M-1) {
                            D[i][j+1] = min(D[i][j+1], D[i][j] + C[i][j+1]);
                        }
                    }
                }
                ans = min(ans, D[N-1][M-1]);
            }
        }

        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343