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
const int MX = 200101; //check the limits, dummy


ll SZ = 262144; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return a + b; }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}

void comp(vi &A) {
    vi B = A; sort(all(B));
    map<int, int> cm;
    trav(a, B) {
        if (!cm.count(a)) cm.ins({a, sz(cm)});
    }
    trav(a, A) a = cm[a];
}

void solve() {

    int N; cin >> N;
    vi X(N), Y(N); F0R(i, N) cin >> X[i] >> Y[i];
    comp(X); comp(Y);

    map<int, vi> pts;
    F0R(i, N) {
        pts[-Y[i]].pb(X[i]+1);
    }
    ll ans = 0;
    trav(a, pts) {
        trav(b, a.s) {
            update(b, 1);
        }
        ll X = query(0, MX); ans += X * (X+1) / 2;
        a.s.pb(0); a.s.pb(MX);
        sort(all(a.s));
        F0R(i, sz(a.s) - 1) {
            if (a.s[i] + 1 < a.s[i+1]) {
                ll Y = query(a.s[i] + 1, a.s[i+1] - 1);
                ans -= Y * (Y+1) / 2;
            }
        }
    }
    cout << ans << nl;

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