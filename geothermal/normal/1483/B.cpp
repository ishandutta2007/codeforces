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

set<int> cur;
set<int> err;

int getLst(int p) {
    if (sz(cur) == 0) return -1;
    auto it = cur.lb(p);
    if (it == cur.begin()) return *cur.rbegin();
    it--;
    return *it;
}

int getNxt(int p) {
    if (sz(err) == 0) return -1;
    auto it = err.ub(p);
    if (it == err.end()) it = err.begin();
    return *it;
}

int getNxt2(int p) {
    if (sz(cur) == 0) return -1;
    auto it = cur.ub(p);
    if (it == cur.end()) it = cur.begin();
    return *it;
}

void solve() {
    cur.clear(); err.clear();
    int N; cin >> N;
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) {
        cur.ins(i);
        if (__gcd(A[i], A[(i+N-1)%N]) == 1) err.ins(i);
    }
    int p = 0;
    vi ans;
    while (sz(err)) {
        p = getNxt(p);
        if (p == -1) break;
        err.erase(p); cur.erase(p); ans.pb(p+1);
        //cout << "Delete " << p << nl;
        p = getNxt2(p);
        if (p == -1) continue;
        //cout << "Update " << p << nl;
        err.erase(p);
        int pr = getLst(p);
        if (pr == -1) continue;
        //cout << "With " << pr << nl;
        if (__gcd(A[p], A[pr]) == 1) err.ins(p);
    }
    cout << sz(ans) << " ";
    F0R(i, sz(ans)) cout << ans[i] << " ";
    cout << nl;
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