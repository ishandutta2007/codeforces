#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ld A, B, C; cin >> A >> B >> C;
    ld X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
    vector<vector<pd> > points(2);
    ld ans = abs(X2 - X1) + abs(Y2 - Y1);

    if (B != 0) {
        points[0].pb({X1, (-1 * C - A * X1) / B});
        points[1].pb({X2, (-1 * C - A * X2) / B});
    }
    if (A != 0) {
        points[0].pb({(-1 * C - B * Y1) / A, Y1});
        points[1].pb({(-1 * C - B * Y2) / A, Y2});
    }

    F0R(i, sz(points[0])) {
        F0R(j, sz(points[1])) {
            pd fir = points[0][i], sec = points[1][j];
            ld cur = abs(fir.f - X1) + abs(fir.s - Y1) + abs(sec.f - X2) + abs(sec.s - Y2) + sqrt((fir.f-sec.f)*(fir.f-sec.f) + (fir.s-sec.s)*(fir.s-sec.s));
            ans = min(ans, cur);
        }
    }
    cout << setprecision(20) << ans << endl;
        
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343