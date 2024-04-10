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
    while(T--) {
        int N; cin >> N;
        vector<string> A(N); F0R(i, N) cin >> A[i];
        bool good[N][N];
        F0R(i, N) F0R(j, N) good[i][j] = false;
        F0R(x, 10) {
            F0R(i, N) {
                F0R(j, N) {
                    if (A[i][j] - '0' == x) {
                        good[i][j] = true; break;
                    }
                }
                F0Rd(j, N) {
                    if (A[i][j] - '0' == x) {
                        good[i][j] = true; break;
                    }
                }
            }
            F0R(j, N) {
                F0R(i, N) {
                    if (A[i][j] - '0' == x) {
                        good[i][j] = true; break;
                    }
                }
                F0Rd(i, N) {
                    if (A[i][j] - '0' == x) {
                        good[i][j] = true; break;
                    }
                }
            }
        }

        vpi pos[10];
        F0R(i, N) {
            F0R(j, N) {
                if (good[i][j]) {
                    int cur = A[i][j] - '0';
                    pos[cur].pb({i, j});
                }
            }
        }

        F0R(x, 10) {
            int ans = 0;
            F0R(i, sz(pos[x])) {
                FOR(j, i+1, sz(pos[x])) {
                    pi X = pos[x][i], Y = pos[x][j];
                    if (X.f == Y.f) {
                        ckmax(ans, abs(X.s - Y.s) * max(X.f, N-1-X.f));
                    } else if (X.s == Y.s) {
                        ckmax(ans, abs(X.f - Y.f) * max(X.s, N-1-X.s));
                    } else {
                        ckmax(ans, max(abs(X.s-Y.s)*max(max(X.f, Y.f), N-1-min(X.f, Y.f)), abs(X.f-Y.f)*max(max(X.s, Y.s), N-1-min(X.s, Y.s))));
                    }
                }
            }
            cout << ans << " ";
        }
        cout << nl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343