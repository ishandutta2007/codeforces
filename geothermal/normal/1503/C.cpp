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

ll go(vpl &A) {
    ll ans = 0;
    ll cur = A[0].f;
    F0R(i, sz(A)) {
        ans += max(0ll, A[i].f-cur);
        cur = max(cur, A[i].f+A[i].s);
    }
    return ans;
}

void solve() {

    int N; cin >> N;
    vpl hi(1), lo;
    cin >> hi[0].f >> hi[0].s;
    ll K = hi[0].f, L = hi[0].s;
    lo.pb(hi[0]);
    ll ans = hi[0].s;
    vpl A;
    F0R(i, N-1) {
        ll X, Y; cin >> X >> Y;
        A.pb({X, Y});
        ans += Y;
        if (X >= hi[0].f) {
            hi.pb({X, Y});
        } else {
            lo.pb({X, Y});
        }
    }
    sort(all(hi)); sort(all(lo));
    sort(all(A));

    cout << ans + min(go(hi) + go(lo), go(A) + max(0ll, K - A[N-2].f - A[N-2].s) + max(0ll, A[0].f - K - L)) << nl;

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