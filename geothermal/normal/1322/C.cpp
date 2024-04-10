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
        int N, M; cin >> N >> M;
        int comp[N+1]; F0R(i, N+1) comp[i] = 0;
        int nc = 1;
        int sc[N+1]; F0R(i, N+1) sc[i] = 0;
        sc[0] = N;

        ll C[N]; F0R(i, N) cin >> C[i];

        vector<vi> graph(N);
        F0R(i, M) {
            int U, V; cin >> U >> V; U--; V--;
            graph[U].pb(V);
        }

        F0R(v, N) {
            map<int, vi> cnts;
            trav(a, graph[v]) {
                cnts[comp[a]].pb(a);
            }

            trav(a, cnts) {
//                cout << a.f << " " << sz(a.s) << nl;
                if (sz(a.s) != sc[a.f] || a.f == 0) {
                    sc[a.f] -= sz(a.s);
                    sc[nc] = sz(a.s);
                    trav(b, a.s) {
                        comp[b] = nc;
                    }
                    nc++;
                }
            }
/*            F0R(i, N) {
                cout << comp[i] << " ";
            }
            cout << nl;*/
        }

        ll val[N+1]; F0R(i, N+1) val[i] = 0;
        F0R(i, N) val[comp[i]] += C[i];

        ll ans = val[1];
        FOR(i, 1, N+1) {
            if (val[i] != 0) ans = __gcd(ans, val[i]);
        }

        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343