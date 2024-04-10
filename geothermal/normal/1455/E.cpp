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
const ll INF = 1e12;

ll solve(vpl &A, int var, int l1, int l2, int l3) {
    vpl G(4);
    if (var == 1) {
        //lock Y's
        if (l1 > 1 || l2 <= 1) return INF;
        if (A[l1].s >= A[l2].s) return INF;
        G[l1].s = A[l1].s; G[l2].s = A[l2].s;
        G[1-l1].s = A[l1].s; G[5-l2].s = A[l2].s;
        ll X = A[l3].f; if (l3 % 2) X -= A[l2].s - A[l1].s;
        G[0].f = X; G[1].f = X + A[l2].s - A[l1].s;
        G[2].f = X; G[3].f = X + A[l2].s - A[l1].s;
    } else {
        //Lock X
        if (l1 % 2 || l2 % 2 == 0) return INF;
        if (A[l1].f >= A[l2].f) return INF;
        G[l1].f = A[l1].f; G[l2].f = A[l2].f;
        G[2-l1].f = A[l1].f; G[4-l2].f = A[l2].f;
        ll X = A[l3].s; if (l3 > 1) X -= A[l2].f - A[l1].f;
        G[0].s = X; G[1].s = X;
        G[2].s = X + A[l2].f - A[l1].f;G[3].s = X + A[l2].f - A[l1].f;
    }
    ll ans = 0;
    F0R(i, 4) {
        ans += abs(G[i].f - A[i].f) + abs(G[i].s - A[i].s);
    }
    return ans;

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        vpl A(4); F0R(i, 4) cin >> A[i].f >> A[i].s;
        sort(all(A)); 
        ll ans = 1e12;
        do {
            F0R(a, 2) {
                F0R(b, 2) {
                    F0R(c, 2) {
                        F0R(d, 4) {
                            int x, y;
                            if (a == 0) {
                                if (b == 1) {
                                    x = 2;
                                } else {
                                    x = 0;
                                }
                                if (c == 1) {
                                    y = 3;
                                } else y = 1;
                                if (A[x].f >= A[y].f) continue;
                            } else {
                                x = b;
                                y = c + 2;
                                if (A[x].s >= A[y].s) continue;
                            }

                            ckmin(ans, solve(A, a, x, y, d));
                        }
                    }
                }
            }
        } while (next_permutation(all(A)));
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343