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

void solve() {

    int N; cin >> N;
    ll A[N]; F0R(i, N) cin >> A[i];
    ll sum[2]; F0R(i, 2) sum[i] = 0;
    F0R(i, N) {
        sum[i%2] += A[i];
    }
    multiset<ll> hi[2];
    ll cur[2]; F0R(i, 2) cur[i] = 0;
    ll vals[N]; 
    bool ok = true;
    F0R(i, N) {
        cur[i%2] += A[i];
        if (i > 0) {
            hi[i%2].ins(cur[i%2]-cur[1-(i%2)]);
            vals[i] = cur[i%2]-cur[1-(i%2)];
        }
        if (cur[i%2] < cur[1-(i%2)]) ok = false;
    }
    if (ok && cur[0] == cur[1]) {
        cout << "YES" << nl; return;
    }
    hi[0].ins(1e18); hi[1].ins(1e18);
    cur[0] = 0; cur[1] = 0;
    F0R(i, N-1) {
        hi[1-(i%2)].erase(hi[1-(i%2)].find(vals[i+1]));
        if (sum[i%2] - sum[1-(i%2)] == A[i]*2-A[i+1]*2) {
            ll X[2]; F0R(i, 2) X[i] = cur[i];
            
            X[i%2] += A[i+1];
            if (X[i%2] >= X[1-(i%2)]) {
                X[1-(i%2)] += A[i];
                if (X[1-(i%2)] >= X[i%2]) {
                    ll K1 = *hi[i%2].begin();
                    if (K1 + 2 * A[i+1] - 2 * A[i] >= 0) {
                        ll K2 = *hi[1-(i%2)].begin();
                        if (K2 + 2 * A[i] - 2 * A[i+1] >= 0) {
                            cout << "YES" << nl; return;
                        }
                    }
                }
            }
        }
        cur[i%2] += A[i];
        if (cur[i%2] < cur[1-(i%2)]) break;
    }
    cout << "NO" << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343