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

vpi ans;

void solveTwo(vi &A, vi &B) {
    F0R(i, sz(B)) {
        ans.pb({A[0], B[i]});
    }
    FOR(i, 1, sz(A)) {
        ans.pb({A[i], B[0]});
    }
    ans.pb({A[0], B[0]});
}

void solveOne(vi &A) {
    if (sz(A) > 2) {
        FOR(i, 1, sz(A)-1) {
            ans.pb({A[i], A[0]});
        }
        ans.pb({A[1], A[sz(A)-1]});
        ans.pb({A[0], A[sz(A)-1]});
        ans.pb({A[0], A[1]});
        return;
    }
    int oth = 0;
    while (A[0] == oth || A[1] == oth) oth++;
    ans.pb({A[1], oth});
    ans.pb({A[0], oth});
    ans.pb({A[1], oth});
}

void solve() {

    int N; cin >> N;
    bool found[N]; F0R(i, N) found[i] = false;
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) A[i]--;
    vector<vi> cycs;
    F0R(i, N) {
        if (found[i] || A[i] == i) continue;
        found[i] = true;
        int nxt = A[i];
        vi cur; cur.pb(i);
        while (!found[nxt]) {
            found[nxt] = true;
            cur.pb(nxt);
            nxt = A[nxt];
        }
        cycs.pb(cur);
    }
    if (sz(cycs) % 2) {
        solveOne(cycs[0]);
    }
    for (int i = sz(cycs)%2; i < sz(cycs); i += 2) {
        solveTwo(cycs[i], cycs[i+1]);
    }

    cout << sz(ans) << nl;
    trav(a, ans) {
        cout << a.f+1 << " " << a.s+1 << nl;
    }

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