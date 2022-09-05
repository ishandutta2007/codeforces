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
const int MX = 510; //check the limits, dummy
 
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int pref[MX][MX][300];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M, Q; cin >> N >> M >> Q;

    F0R(i, MX) F0R(j, MX) F0R(k, 300) pref[i][j][k] = 0;

    char A[N][M]; F0R(i, N) F0R(j, M) cin >> A[i][j];
    

    F0R(i, N) {
        F0R(j, M) {
            FOR(K, 1, 300) {
                FOR(x, i-K+1, i+1) {
                    if (!valid(x, j-K+1, N, M) || A[x][j-K+1] != 'R') goto done;
                }
                FOR(y, j-K+1, j+1) {
                    if (!valid(i-K+1, y, N, M) || A[i-K+1][y] != 'R') goto done;
                }
                FOR(x, i-K+1, i+1) {
                    if (!valid(x, j+K, N, M) || A[x][j+K] != 'G') goto done;
                }
                FOR(y, j+1, j+K+1) {
                    if (!valid(i-K+1, y, N, M) || A[i-K+1][y] != 'G') goto done;
                }
                FOR(x, i+1, i+K+1) {
                    if (!valid(x, j+K, N, M) || A[x][j+K] != 'B') goto done;
                }
                FOR(y, j+1, j+K+1) {
                    if (!valid(i+K, y, N, M) || A[i+K][y] != 'B') goto done;
                }
                FOR(x, i+1, i+K+1) {
                    if (!valid(x, j-K+1, N, M) || A[x][j-K+1] != 'Y') goto done;
                }
                FOR(y, j-K+1, j+1) {
                    if (!valid(i+K, y, N, M) || A[i+K][y] != 'Y') goto done;
                }

                pref[i-K+1][j-K+1][K]++;
            }

            done:
            ;
        }
    }

    F0R(i, N+5) {
        F0R(j, M+5) {
            F0R(k, 300) {
                if (i > 0) pref[i][j][k] += pref[i-1][j][k];
                if (j > 0) pref[i][j][k] += pref[i][j-1][k];
                if (i > 0 && j > 0) pref[i][j][k] -= pref[i-1][j-1][k];
            }
        }
    }

/*    F0R(i, N) {
        F0R(j, M) {
            cout << pref[i][j][1] << " ";
        }
        cout << nl;
    }*/

    F0R(q, Q) {
        int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
        X1--; Y1--; X2--; Y2--;
        F0Rd(k, 300) {
            int x2 = X2 - 2*k + 1, y2 = Y2 - 2*k + 1;
            if (x2 < X1 || y2 < Y1) continue;
            int sum = pref[x2][y2][k];
            if (X1 > 0) sum -= pref[X1-1][y2][k];
            if (Y1 > 0) sum -= pref[x2][Y1-1][k];
            if (X1 > 0 && Y1 > 0) sum += pref[X1-1][Y1-1][k];
            if (sum > 0) {
                cout << 4*k*k << nl; goto done2;
            }
        }
        cout << 0 << nl;
        done2:
        ;
    }



	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343