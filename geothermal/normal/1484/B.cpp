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

    int N; cin >> N; vi A(N); F0R(i, N) cin >> A[i];
    bool ok = true;
    F0R(i, N) if (A[i] != A[0]) ok = false;
    if (ok) {
        cout << 0 << nl; return;
    }
    int dif1 = -1;
    F0R(i, N-1) if (A[i+1] > A[i]) {
        if (dif1 != -1 && dif1 != A[i+1] - A[i]) {
            cout << -1 << nl; return;
        }
        dif1 = A[i+1] - A[i];
    }
    int dif2 = -1;
    F0R(i, N-1) {
        if (A[i+1] <= A[i]) {
            if (dif2 != -1 && dif2 != A[i] - A[i+1]) {
                cout << -1 << nl; return;
            }
            dif2 = A[i] - A[i+1];
        }
    }
    if (dif2 == -1 || dif1 == -1) {
        cout << 0 << nl; return;
    }
    if (A[0] >= dif1+dif2) {
        cout << -1 << nl; return;
    }
    F0R(i, N-1) {
        if (A[i+1] != (A[i]+dif1)%(dif1+dif2)) {
            cout << -1 << nl; return;
        }
    }
    cout << dif1+dif2 << " " << dif1 << nl; return;

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