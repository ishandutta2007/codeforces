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
        ll M; int N; cin >> M >> N;

        ll A[N], B[N]; F0R(i, N) cin >> A[i] >> B[i];

        vpl vals;
        F0R(i, N) vals.pb({A[i], 0});
        vals.pb({1e18, 0});
        sort(all(vals)); reverse(all(vals));
        vals[1].s = vals[1].f;
        FOR(i, 1, N) {
            vals[i+1].s = vals[i].s + vals[i+1].f;
        }
        ll ans = 0;
        F0R(i, N) {
            pl temp = {B[i], 2e18};
            auto it = --upper_bound(all(vals), temp, greater<pl>());
            int cnt = it - vals.begin();
            ll ps = it->s;
            if (cnt > M) {
                cnt = M;
                ps = vals[M].s;
            }
            if (cnt == M && A[i] < vals[M].f) {
                cnt = M-1;
                ps = vals[M-1].s;
            }
            
            if (A[i] < vals[cnt].f) {
                cnt++;
                ps += A[i];
            }
            ps += (M - cnt) * B[i];
            ckmax(ans, ps);
//            cout << ps << nl;
        }
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343