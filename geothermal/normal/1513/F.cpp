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



int N;
ll A[MX], B[MX];

set<int> use1, use2;
map<int, int> comp1, comp2;
ll revComp1[MX*2], revComp2[MX*2];

ll go() {



    vector<pair<int, pair<bool, int>>> P;
    F0R(i, N) {
        if (A[i]>= B[i]) {
            P.pb({comp1[A[i]], {true, comp1[B[i]]}});
        } else {
            P.pb({comp1[B[i]], {false, comp1[A[i]]}});
        }
    }
    sort(all(P)); reverse(all(P));
    int hi = sz(comp1);
    ll ans = 0;
    F0R(i, N) {
        if (P[i].s.f) {
            ckmin(hi, P[i].s.s);
        } else if (P[i].s.s >= hi) {
            ckmax(ans, (ll) revComp1[P[i].f] - revComp1[P[i].s.s]);
        }
    }
    return ans * 2;

}

ll go3() {



    vector<pair<int, pair<bool, int>>> P;
    F0R(i, N) {
        if (A[i]>= B[i]) {
            P.pb({comp2[A[i]], {true, comp2[B[i]]}});
        } else {
            P.pb({comp2[B[i]], {false, comp2[A[i]]}});
        }
    }
    sort(all(P)); reverse(all(P));
    int hi = sz(comp1);
    ll ans = 0;
    F0R(i, N) {
        if (P[i].s.f) {
            ckmin(hi, P[i].s.s);
        } else if (P[i].s.s >= hi) {
            ckmax(ans, (ll) revComp2[P[i].f] - revComp2[P[i].s.s]);
        }
    }
    return ans * 2;

}

ll go2() {

    vector<pair<int, pair<bool, int>>> P;
    F0R(i, N) {
        if (A[i]>= B[i]) {
            P.pb({comp1[A[i]], {true, comp1[B[i]]}});
        } else {
            P.pb({comp1[B[i]], {false, comp1[A[i]]}});
        }
    }
    sort(all(P)); reverse(all(P));
    ll ans = 0;
    set<int> found;
    F0R(i, sz(P)) {
        if (P[i].s.f) {
            found.ins(P[i].s.s);
        } else {
            auto it = found.lb(P[i].s.s);
            if (it != found.end() && *it <= P[i].f) {
                ckmax(ans, revComp1[P[i].f] - revComp1[*it]);
            }
        }
    }
    return ans*2;

}

void solve() {

    cin >> N;
    F0R(i, N) cin >> A[i];
    F0R(i, N) cin >> B[i];
    F0R(i, N) {
        use1.ins(A[i]); use1.ins(B[i]);
        use2.ins(-A[i]); use2.ins(-B[i]);
    }
    trav(a, use1) {
        revComp1[sz(comp1)] = a;
        comp1[a] = sz(comp1);
    }
    trav(a, use2) {
        revComp2[sz(comp2)] = a;
        comp2[a] = sz(comp2);
    }
    ll ans = 0, best = 0;
    F0R(i, N) {
        ans += abs(A[i] - B[i]);
    }
    best = go();
    F0R(i, N) {
        A[i] *= -1; B[i] *= -1;
    }
    best = max(best, go3());
    F0R(i, N) {
        A[i] *= -1; B[i] *= -1;
    }
    best = max(best, go2());
    F0R(i, N) swap(A[i], B[i]);
    best = max(best, go2());
    cout << ans-best << nl;
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