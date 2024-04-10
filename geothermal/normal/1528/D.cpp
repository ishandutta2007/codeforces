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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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
const int MX = 100001; 

void solve() {
    int N, M; cin >> N >> M;
    ll D[N][N]; F0R(i, N) F0R(j, N) D[i][j] = 1e18;
    //D[i][j] = dist from i to j at time 0.  At time 1 this represents dist from i to j+1.  
    F0R(i, M) {
        int X, Y, Z; cin >> X >> Y >> Z;
        D[X][Y] = Z;
    }

    F0R(iter, N+2) {
        F0R(i, N) {
            F0R(j, N) {
                ckmin(D[i][j], D[i][(j+N-1)%N]+1); 
            }
        }
    }

    F0R(r, N) {
        bool found[N]; F0R(i, N) found[i] = false;
        ll dist[N]; F0R(i, N) dist[i] = 1e18;
        dist[r] = 0;
        F0R(iter, N) {
            int p = -1;
            F0R(i, N) {
                if (!found[i] && (p == -1 || dist[i] < dist[p])) {
                    p = i;
                }
            }

            found[p] = true;
            ll T = dist[p]%N;
            F0R(i, N) {
                ckmin(dist[i], dist[p] + D[p][(i+N-T)%N]);
            }
        }
        F0R(i, N) {
            cout << dist[i] << " ";
        }
        cout << nl;
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}