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
	
    int N, M, K; cin >> N >> M >> K;
    int best[N+1][K]; F0R(i, N+1) F0R(j, K) best[i][j] = -1e8;
    best[0][0] = 0;
    int A[N][M];
    F0R(i, N) {
        F0R(j, M) {
            cin >> A[i][j];
        }
    }

    F0R(x, N) {
        int trans[M+1][K][M/2+1]; F0R(i, M+1) F0R(j, K) F0R(k, M/2 + 1) trans[i][j][k] = -1e8;
        trans[0][0][0] = 0;
        F0R(i, M) {
            F0R(j, K) {
                F0R(k, M/2+1) {
                    ckmax(trans[i+1][j][k], trans[i][j][k]);
                    if (k != M/2) {
                        ckmax(trans[i+1][(j+A[x][i])%K][k+1], trans[i][j][k] + A[x][i]);
                    }
                }
            }
        }
        int bst[K]; F0R(i, K) {
            bst[i] = -1e8;
            F0R(j, M/2 + 1) {
                ckmax(bst[i], trans[M][i][j]);
            }
        }
        F0R(i, K) {
            F0R(j, K) {
                ckmax(best[x+1][(i+j)%K], best[x][i] + bst[j]);
            }
        }
    }

    cout << best[N][0] << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343