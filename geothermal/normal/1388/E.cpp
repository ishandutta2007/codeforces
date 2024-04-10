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
ld opt(ld lo, ld hi, ld X1, ld Y1, ld X2, ld Y2) {
    if (Y1 <= Y2) {
        return X1 - X2 + hi * (Y1 - Y2);
    } else {
        return X1 - X2 + lo * (Y1 - Y2);
    }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    ll A[N], B[N], C[N];
    F0R(i, N) cin >> A[i] >> B[i] >> C[i];
 
    vector<pair<ld, pi> > ev;
    vector<pair<ld, pi> > pe, pe2;
    F0R(i, N) {
        F0R(j, N) {
            if (C[i] <= C[j]) continue;
            ev.pb({((ld) B[j] - A[i]) / ((ld) C[i] - C[j]) - 1e-15, {i, j}});
            ev.pb({((ld) A[j] - B[i]) / ((ld) C[i] - C[j]) + 1e-15, {i, j}});
            pe.pb({((ld) A[j] - A[i]) / ((ld) C[i] - C[j]), {i, j}});
            pe2.pb({((ld) B[j] - B[i]) / ((ld) C[i] - C[j]), {i, j}});
 
        }
    }
    if (sz(ev) == 0) {
        ld lo = 1e20, hi = -1e20;
        F0R(i, N) {
            ckmin(lo, (ld) A[i]);
            ckmax(hi, (ld) B[i]);
        }
        cout << hi-lo << nl; return 0;
    }
    ld ans = 1e20;
    sort(all(ev));
    vector<pair<ld, int> > is;
    F0R(i, N) {
        is.pb({(ev[0].f-1)*C[i] + A[i], i});
    }
    sort(all(is));
    int lpos[N], rpos[N]; F0R(i, N) lpos[is[i].s] = i;
 
 
    vi lord, rord; F0R(i, N) lord.pb(is[i].s);
 
    is.clear();
    F0R(i, N) is.pb({(ev[0].f - 1) * C[i] + B[i], i});
    sort(all(is));
    F0R(i, N) rpos[is[i].s] = i;
    F0R(i, N) rord.pb(is[i].s);
    ans = opt(-1e20, ev[0].f, B[rord[N-1]], C[rord[N-1]], A[lord[0]], C[lord[0]]);
    bool in[N][N]; F0R(i, N) F0R(j, N) in[i][j] = false;
    int cnt = 0;
    int pind = 0, pind2 = 0;
    sort(all(pe));
    sort(all(pe2));
    F0R(i, sz(ev)) {
        auto a = ev[i];
        int L = min(a.s.f, a.s.s);
        int R = max(a.s.f, a.s.s);
        if (in[L][R]) {
            cnt--;
        } else {
            cnt++;
            in[L][R] = true;
        }
        while (pind != sz(pe) && pe[pind].f <= ev[i].f) {
            a = pe[pind]; pind++;
            if (lpos[a.s.f] > lpos[a.s.s]) continue;
            swap(lord[lpos[a.s.f]], lord[lpos[a.s.s]]);
            swap(lpos[a.s.f], lpos[a.s.s]);
        }
        while (pind2 != sz(pe2) && pe2[pind2].f <= ev[i].f) {
            a = pe2[pind2]; pind2++;
            if (rpos[a.s.f] > rpos[a.s.s]) continue;
            swap(rord[rpos[a.s.f]], rord[rpos[a.s.s]]);
            swap(rpos[a.s.f], rpos[a.s.s]);
        }
 
        if (cnt == 0 && i != sz(ev) - 1) {
            ckmin(ans, opt(ev[i].f, ev[i+1].f, B[rord[N-1]], C[rord[N-1]], A[lord[0]], C[lord[0]]));
        }
    }
    ckmin(ans, opt(ev[sz(ev) - 1].f, 1e20, B[rord[N-1]], C[rord[N-1]], A[lord[0]], C[lord[0]]));
 
    cout << setprecision(20) << ans << nl;
 
/*    if (hi <= -1e14) {
        hi = 0; lo = 0;
    }
    cout << lo << " " << hi << nl;
    ld loa = 1e20, hia = -1e20;
    F0R(i, N) {
        ckmin(loa, A[i] + lo * C[i]);
        ckmax(hia, B[i] + lo * C[i]);
    }
    ld best = hia - loa;
    loa = 1e20; hia = -1e20;
    F0R(i, N) {
        ckmin(loa, A[i] + hi * C[i]);
        ckmax(hia, B[i] + hi * C[i]);
    }
    ckmax(best, hia - loa);
 
    cout << setprecision(20) << best << nl;*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343