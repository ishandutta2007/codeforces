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
const int MX = 501000; //check the limits, dummy

template<int SZ> struct DSU {
    int parent[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        parent[y] = x;

    }
};

void solve() {

    int N; cin >> N;
    map<int, vpi> costs;
    int A[N][N]; F0R(i, N) F0R(j, N) cin >> A[i][j];
    F0R(i, N) {
        FOR(j, i+1, N) {
            costs[A[i][j]].pb({i, j});
        }
    }
    DSU<MX> dsu;
    vi sal;
    vpi tree;
    F0R(i, N) sal.pb(A[i][i]);
    trav(a, costs) {
        sort(all(a.s));
        trav(b, a.s) {
            int X = dsu.get(b.f), Y = dsu.get(b.s);
            if (sal[X] == a.f && sal[Y] != a.f) {
                dsu.unify(X, Y);
                tree.pb({Y, X});
            } else if (sal[X] != a.f && sal[Y] == a.f) {
                dsu.unify(Y, X);
                tree.pb({X, Y});
            } else if (sal[X] != a.f && sal[Y] != a.f) {
                int K = sz(sal);
                sal.pb(a.f);
                dsu.unify(K, X);
                dsu.unify(K, Y);
                tree.pb({X, K});
                tree.pb({Y, K});
            }
        }
    }
    cout << sz(sal) << nl;
    trav(a, sal) cout << a << " ";
    cout << nl;
    cout << sz(sal) << nl;
    trav(a, tree) cout << a.f+1 << " " << a.s+1 << nl;

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