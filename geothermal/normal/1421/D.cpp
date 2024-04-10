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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        ll X, Y; cin >> X >> Y;
        ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
        ll ans = 4e18;
        if (Y >= X && X >= 0) {
            ckmin(ans, A * X + B * (Y - X));
        }
        if (Y >= 0 && X <= Y) {
            ckmin(ans, Y * A + (Y-X) * C);
        }
        if (X >= 0 && Y <= X) {
            ckmin(ans, X * A + (X-Y) * E);
        }
        if (X >= Y && Y >= 0) {
            ckmin(ans, A * Y + F * (X-Y));
        }

        if (Y <= X && X <= 0) {
            ckmin(ans, D * (-X) + E * (X-Y));
        }
        if (X <= Y && Y <= 0) {
            ckmin(ans, D * (-Y) + C * (Y-X));
        }
        if (Y <= 0 && Y <= X) {
            ckmin(ans, D * (-Y) + F * (X-Y));
        }
        if (X <= 0 && X <= Y) {
            ckmin(ans, D * (-X) + B * (Y-X));
        }

        ll xc = X * F; if (X < 0) xc = (-X) * C;
        ll yc = Y * B; if (Y < 0) yc = (-Y) * E;

        cout << min(ans, xc + yc) << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343