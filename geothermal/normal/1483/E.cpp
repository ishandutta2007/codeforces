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

ll X;
ll rem;

bool query(ll K) {
    if (K > 100000000000000) K = 100000000000000;
    rem--;
    cout << "? " << K << endl;
    string ans; cin >> ans;
    if (ans[1] == 'i') exit(0);
    if (ans[1] == 'r') { X -= K; return true; }
    if (ans[1] == 'u') { X += K; return false; }
    return false;
}

void solve() {
    
    X = 1;
    rem = 105;
    ll lo = 0, hi = 100000000000000ll;
    while (X <= 100000000000000ll) {
        ll old = X;
        if (query(X)) {
            hi = old-1; break;
        }
        lo = old;
    }
    ckmin(hi, 100000000000000ll);
    ckmin(lo, 100000000000000ll);
    while (lo < hi) {
        ll numAllowed = rem + min(rem, X/lo); numAllowed /= 2; if (X < lo) numAllowed--;
        ld frac = pow(hi-lo+1, 1/((ld) numAllowed));
        frac = 1/frac;
        ll mid = lo + (hi - lo) * frac;
        mid+=2;
        ckmin(mid, (lo+hi+1)/2);
        while (X < mid) {
            query(lo);
        }
        if (query(mid)) {
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    cout << "! " << lo << endl;

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