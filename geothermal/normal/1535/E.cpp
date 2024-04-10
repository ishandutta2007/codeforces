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
const int MX = 400001; 

void solve() {
    int Q; cin >> Q;
    ll A[MX], C[MX];
    cin >> A[0] >> C[0];
    int p[MX][19];
    F0R(i, 19) p[0][i] = -1;
    FOR(q, 1, Q+1) {
        int T; cin >> T;
        if (T == 1) {
            int P; cin >> P;
            cin >> A[q] >> C[q];
            p[q][0] = P;
            FOR(i, 1, 19) {
                p[q][i] = p[p[q][i-1]][i-1];
            }
        } else {
            int V; cin >> V;
            ll W; cin >> W;
            ll rem = W;
            ll ans = 0;
            while (rem > 0 && A[V] > 0) {
                int v = V;
                F0Rd(i, 19) {
                    while (p[v][i] != -1 && A[p[v][i]]) {
                        v = p[v][i];
                    }
                }
                ll cur = min(rem, A[v]);
                rem -= cur; A[v] -= cur; ans += cur * C[v];
            }
            cout << W-rem << " " << ans << endl;
        }
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