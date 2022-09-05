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

vi solve(vector<pair<int, pair<bool, int> > > A) {
    vi res(sz(A) / 2);
    int cnt = 0;
    bool found[sz(A) / 2]; F0R(i, sz(A) / 2) found[i] = false;
//    cout << "TEST" << nl;
    F0R(i, sz(A)) {
        if (A[i].s.f) {
            cnt++;
            found[A[i].s.s] = true;
        } else {
            res[A[i].s.s] = cnt;
            if (found[A[i].s.s]) res[A[i].s.s]--; 
        }
    }
    return res;
        
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int who, cares; cin >> who >> cares;
    int X1[N], X2[N], Y1[N], Y2[N]; F0R(i, N) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    F0R(i, N) {
        if (X1[i] > X2[i]) swap(X1[i], X2[i]);
        if (Y1[i] > Y2[i]) swap(Y1[i], Y2[i]);
    }

    vector<pair<int, pair<bool, int> > > X, Y, Xr, Yr;
    F0R(i, N) {
        X.pb({X1[i], {true, i}});
        Y.pb({Y1[i], {true, i}});
        Y.pb({Y2[i], {false, i}});
        X.pb({X2[i], {false, i}});
        Xr.pb({X1[i]+1, {false, i}});
        Xr.pb({X2[i], {true, i}});
        Yr.pb({Y1[i]+1, {false, i}});
        Yr.pb({Y2[i], {true, i}});
    }
    sort(all(X));
    sort(all(Y));
    sort(all(Yr));
    sort(all(Xr));
    reverse(all(Xr));
    reverse(all(Yr));
    vi A = solve(X), B = solve(Y), C = solve(Xr), D = solve(Yr);
    int E, F, G, H; cin >> E >> F >> G >> H;
    F0R(i, N) {
        if (E == A[i] && F == C[i] && G == B[i] && H == D[i]) {
            cout << i+1 << nl; return 0;
        }
//        cout << A[i] << " " << B[i] << " " << C[i] << " " << D[i] << nl;
    }
    cout << -1 << nl; return 0;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343