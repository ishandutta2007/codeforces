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
	
    int N; cin >> N;
    ll T[N+1], X[N+1]; F0R(i, N) cin >> T[i+1] >> X[i+1];
    T[0] = 0; X[0] = 0;
    bool ok[N+1][N+1];
    ll time[N+1][N+1];
    F0R(i, N+1) {
        F0R(j, N+1) {
            ok[i][j] = false;
            time[i][j] = 1e12;
        }
    }
    ok[0][N] = true;
    F0R(i, N) {
        time[0][i] = abs(X[i+1]);
    }
    F0R(i, N) {
        if (ok[i][N]) {
            F0R(k, N) {
                ckmin(time[i][k], T[i] + abs(X[i] - X[k+1]));
            }
        }
        F0R(j, N) {
            if (ok[i][j]) {
                if (abs(X[i+1] - X[i]) <= T[i+1] - T[i]) {
                    ok[i+1][j] = true;
                }
                if (i == j) {
                    F0R(k, N) {
                        ckmin(time[i+1][k], max(T[i+1], T[i] + abs(X[i] - X[k+1])));
                    }
                }
            }
            if (time[i][j] + abs(X[j+1] - X[i+1]) <= T[i+1]) {
                ok[i+1][j] = true;
            }
            if (i == j && time[i][j] <= T[i+1]) {
                F0R(k, N) {
                    ckmin(time[i+1][k], max(T[i+1], time[i][j] + abs(X[j+1] - X[k+1])));

                }
            }
        }
    }

/*    F0R(i, N+1) {
        F0R(j, N+1) {
            cout << ok[i][j] << " ";
        }
        cout << nl;
    }
    F0R(i, N+1) {
        F0R(j, N+1) {
            cout << time[i][j] << " ";
        }
        cout << nl;
    }*/
    bool ans = false;
    F0R(i, N+1) {
        if (ok[N][i] || time[N][i] <= T[N]) ans = true;
    }
    cout << (ans?"YES":"NO") << nl;
    
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343