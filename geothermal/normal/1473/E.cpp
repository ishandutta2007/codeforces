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

void solve() {

    int N, M; cin >> N >> M;
    vector<vpl> graph(4*N);
    while(M--) {
        int X, Y, W; cin >> X >> Y >> W;
        X--; Y--;
        F0R(i, 4) {
            graph[X+i*N].pb({Y+i*N, W});
            graph[Y+i*N].pb({X+i*N, W});
            if ((i & 1) == 0) {
                graph[X+i*N].pb({Y+i*N+N, 0});
                graph[Y+i*N].pb({X+i*N+N, 0});
            }
            if ((i & 2) == 0) {
                graph[X+i*N].pb({Y+i*N+2*N, W*2});
                graph[Y+i*N].pb({X+i*N+2*N, W*2});
            }
        }
    }

    ll dist[4*N]; F0R(i, 4*N) dist[i] = 1e18;
    dist[0] = 0;
    priority_queue<pl, vpl, greater<pl> > q;
    q.push({0, 0});
    bool vis[4*N]; F0R(i, 4*N) vis[i] = false;
    while (!q.empty()) {
        int v = q.top().s; q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        trav(a, graph[v]) {
            if (ckmin(dist[a.f], dist[v] + a.s)) {
                q.push({dist[a.f], a.f});
            }
        }
    }
    trav(a, graph[0]) {
        if (a.f < N) ckmin(dist[3*N+a.f], a.s);
    }

    FOR(i, 1, N) {
        cout << dist[3*N+i] << " ";
    }
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