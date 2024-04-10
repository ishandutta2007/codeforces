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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}
void solve() {

    int N, M, K; cin >> N >> M >> K;
    ll cost[N][M][4];
    F0R(i, N) F0R(j, M) F0R(k, 4) cost[i][j][k] = 1e16;
    F0R(i, N) {
        F0R(j, M-1) {
            ll X; cin >> X;
            cost[i][j][1] = X; cost[i][j+1][3] = X;
        }
    }
    F0R(i, N-1) {
        F0R(j, M) {
            ll X; cin >> X;
            cost[i][j][0] = X; cost[i+1][j][2] = X;
        }
    }
    if (K % 2) {
        F0R(i, N) {
            F0R(j, M) {
                cout << -1 << " ";
            }
            cout << nl;
        }
        return;
    }
    K /= 2;
    /*ll dist[N][M][11]; F0R(i, N) F0R(j, M) F0R(k, 11) dist[i][j][k] = 1e16;
    vpi offs[11];
    FOR(i, -K, K+1) {
        FOR(j, -K, K+1) {
            int X = abs(i) + abs(j);
            if (X > K) continue;
            FOR(k, X, K+1) {
                if (k % 2 == X % 2) {
                    offs[k].pb({i, j});
                }
            }
            
        }
    }
    F0R(ri, N) {
        F0R(rj, M) {
            ll ans = 1e16;
            dist[ri][rj][0] = 0;
            F0R(k, K+1) {
                trav(a, offs[k]) {
                    int i = ri + a.f, j = rj + a.s;
                    if (i < 0 || j < 0 || i >= N || j >= M) continue;
                    F0R(d, 4) {
                        int x = i + dx[d], y = j + dy[d];
                        if (k < K && valid(x, y, N, M)) {
                            ckmin(dist[x][y][k+1], dist[i][j][k] + cost[i][j][d]);
                        }
                        ckmin(ans, dist[i][j][k] + cost[i][j][d] * (K - k));
                    }
                    dist[i][j][k] = 1e16;
                }
            }
            cout << ans*2 << " ";
        }
        cout << nl;
    }*/

    ll dp[N][M][K+1];
    F0R(i, N) F0R(j, M) dp[i][j][0] = 0;
    FOR(k, 1, K+1) {
        F0R(i, N) {
            F0R(j, M) {
                dp[i][j][k] = 1e18;
                F0R(z, 4) {
                    int x = i + dx[z], y = j + dy[z];
                    if (valid(x, y, N, M)) {
                        ckmin(dp[i][j][k], dp[x][y][k-1] + cost[i][j][z]);
                    }
                }
            }
        }
    }

    F0R(i, N) {
        F0R(j, M) {
            cout << dp[i][j][K]*2 << " ";
        }
        cout << nl;
    }
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343