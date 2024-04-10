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

int N, M; 
vector<vi> A;
vi ans;

void go(vi& att, int err) {
    F0R(i, N) {
        vi ers;
        F0R(j, M) {
            if (att[j] != A[i][j]) ers.pb(j);
        }
        if (sz(ers) > 4) return;
        if (sz(ers) == 4) {
            if (err < 2) return;
            F0R(m, 16) {
                if (__builtin_popcount(m) != 2) continue;
                vi nxt = att;
                F0R(j, 4) {
                    if (m & (1 << j)) {
                        nxt[ers[j]] = A[i][ers[j]];
                    }
                }
                go(nxt, err-2);
            }
            return;
        } else if (sz(ers) == 3) {
            if (err == 0) return;
            F0R(j, 3) {
                vi nxt = att;
                nxt[ers[j]] = A[i][ers[j]];
                go(nxt, err-1);
            }
            return;
        }
    }
    ans = att;
}

void solve() {

    cin >> N >> M;
    F0R(i, N) {
        A.pb(vi(M));
        F0R(j, M) cin >> A[i][j];
    }

    go(A[0], 2);
    if (sz(ans) == 0) {
        cout << "No" << nl;
        return;
    }
    cout << "Yes" << nl;
    F0R(i, sz(ans)) cout << ans[i] << " ";
    cout << nl;

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