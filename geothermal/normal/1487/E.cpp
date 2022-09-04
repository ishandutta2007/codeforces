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
const int MX = 150001; //check the limits, dummy

void solve() {

    int N[4]; F0R(i, 4) cin >> N[i];
    ll A[4][MX]; F0R(i, 4) F0R(j, N[i]) cin >> A[i][j];
    vector<set<int>> graph[3];
    F0R(i, 3) {
        graph[i] = vector<set<int>>(N[i+1]);
        int M; cin >> M;
        F0R(j, M) {
            int X, Y; cin >> X >> Y; X--; Y--; graph[i][Y].ins(X);
        }
    }

    set<pl> cost[4];
    F0R(i, N[0]) cost[0].ins({A[0][i], i});
    FOR(i, 1, 4) {
        F0R(j, N[i]) {
            auto it = cost[i-1].begin();
            while (it != cost[i-1].end() && graph[i-1][j].count(it->s)) {
                it++;
            }
            if (it != cost[i-1].end()) {
                cost[i].ins({it->f + A[i][j], j});
            }
        }
    }
    if (sz(cost[3]) == 0) {
        cout << -1 << nl;
    } else {
        cout << cost[3].begin()->f << nl;
    }
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