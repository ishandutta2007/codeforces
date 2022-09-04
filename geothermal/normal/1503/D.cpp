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

    int N; cin >> N;
    vpi A(N); F0R(i, N) cin >> A[i].f >> A[i].s;
    F0R(i, N) {
        if (min(A[i].f, A[i].s) > N || max(A[i].f, A[i].s) <= N) {
            cout << -1 << nl; return;
        }
        A[i].f--; A[i].s--;
    }

    int V[N]; F0R(i, N) V[min(A[i].f, A[i].s)] = max(A[i].f, A[i].s);
    bool fl[N]; F0R(i, N) fl[min(A[i].f, A[i].s)] =  A[i].s > A[i].f;
    int p[N]; F0R(i, N) p[i] = 0;
    int cur = 2*N+1;
    F0R(i, N) {
        if (V[i] >= cur) {
            p[i] = 2;
        }
        ckmin(cur, V[i]);
    }
    cur = 2*N+1;
    F0R(i, N) {
        if (V[i] >= cur) {
            cout << "-1" << nl; return;
        }
        if (p[i] == 2) ckmin(cur, V[i]);
    }
    cur = 0;
    F0Rd(i, N) {
        if (V[i] <= cur) {
            p[i] = 1;
        }
        ckmax(cur, V[i]);
    }

    int ans = 0;
    int X = 0, Y = 0;
    bool found[N]; F0R(i, N) found[i] = false;
    int P = 0;
    F0R(i, N) {
        found[2*N-1-V[i]] = true;
        if (p[i] != 0) {
            if ((p[i] == 1 && fl[i]) || (p[i] == 2 && !fl[i])) {
                X++;
            } else Y++;
        }
        while (P < N && found[P]) P++;
        if (P > i) {
            ans += min(X, Y); X = 0; Y = 0;
        }
    }
    ans += min(X, Y);
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