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
inline int get(int m, int p) {
    return (m >> p) % 2;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N, M; cin >> N >> M;
    if (min(N, M) >= 4) {
        cout << -1 << nl; return 0;
    }
    vector<vi> A;
    F0R(i, N) {
        vi cur;
        F0R(j, M) {
            char C; cin >> C; cur.pb(C - '0');
        }
        A.pb(cur);
    }

    if (N < M) {
        vector<vi> B;
        F0R(i, M) {
            vi cur;
            F0R(j, N) {
                cur.pb(A[j][i]);
            }
            B.pb(cur);
        }
        A = B;
        swap(N, M);
    }

    bool valid[(1 << M)][(1 << M)];
    F0R(i, 1 << M) {
        F0R(j, 1 << M) {
            valid[i][j] = true;

            F0R(k, M-1) {
                int C = 0;
                F0R(l, 2) {
                    C += get(i, k+l) + get(j, k+l);
                }
                if (C % 2 == 0) valid[i][j] = false;
            }
        }
    }

    int dp[N][(1 << M)];
    F0R(i, N) {
        F0R(j, (1 << M)) {
            dp[i][j] = 10000000;
        }
    }

    F0R(m, (1 << M)) {
        int cur = 0;
        F0R(i, M) {
            if (A[0][i] != get(m, i)) {
                cur++;
            }
        }
        dp[0][m] = cur;
    }

    FOR(i, 1, N) {
        F0R(a, (1 << M)) {
            int C = 0;
            F0R(j, M) {
                if (A[i][j] != get(a, j)) {
                    C++;
                }
            }
            F0R(b, (1 << M)) {
                if (valid[a][b]) {
                    ckmin(dp[i][a], dp[i-1][b] + C);
                }
            }
        }
    }

    int ans = 100000000;
    F0R(i, (1 << M)) ckmin(ans, dp[N-1][i]);
    if (ans > N*M) {
        cout << -1 << nl;
    } else {
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343