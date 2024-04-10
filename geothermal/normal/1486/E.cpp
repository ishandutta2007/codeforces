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
    vector<vpi> graph(N);
    F0R(i, M) {
        int X, Y, Z; cin >> X >> Y >> Z; X--; Y--;
        graph[X].pb({Y, Z});
        graph[Y].pb({X, Z});
    }
    priority_queue<pair<ll, pi> , vector<pair<ll, pi>>, greater<pair<ll, pi>>> q;
    ll dist[N][51]; F0R(i, N) F0R(j, 51) dist[i][j] = 1e18;
    dist[0][0] = 0;
    q.push({0, {0, 0}});
    bool vis[N][51]; F0R(i, N) F0R(j, 51) vis[i][j] = false;
    while (!q.empty()) {
        int x = q.top().s.f, y = q.top().s.s;
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        trav(a, graph[x]) {
            ll cost = 0;
            if (y != 0) cost = y*y+a.s*a.s+2*y*a.s;
            int ny = a.s; if (y != 0) ny = 0;
            if (ckmin(dist[a.f][ny], dist[x][y] + cost)) {
                q.push({dist[a.f][ny], {a.f, ny}});
            }
        }
    }
    F0R(i, N) {
        if (dist[i][0] > 1e17) {
            cout << -1 << " ";
        } else cout << dist[i][0] << " ";
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