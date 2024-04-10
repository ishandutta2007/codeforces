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
const int MX = 200001; //check the limits, dummy
ll N, K, S, T;
vl A;

bool ok(ll C) {
    ll tot = 0;
    ll cur = 0;
    F0R(i, K+1) {
        ll X = A[i] - cur;
        cur = A[i];
        if (X > C) return false;
        tot += max(X, 3*X-C);
    }
    return tot <= T;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> K >> S >> T;
    vpl data(N); F0R(i, N) cin >> data[i].f >> data[i].s;
    A = vl(K+1);
    F0R(i, K) cin >> A[i];
    A[K] = S;
    sort(all(A));
    sort(all(data));
    
    ll lo = 0;
    ll hi = 1e9 + 1;

    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (ok(mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    ll ans = 2e9;
    F0R(i, N) {
        if (data[i].s >= lo) {
            ckmin(ans, data[i].f);
        }
    }
    if (ans > 1e9 + 10) {
        cout << -1 << nl;
    } else {
        cout << ans << nl;
    }

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343