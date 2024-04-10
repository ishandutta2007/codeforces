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
	
    int N, M; cin >> N >> M;
    int K; cin >> K;
    vector<vpi> graph(N);
    F0R(i, M) {
        int X, Y, W; cin >> X >> Y >> W; X--; Y--;
        graph[X].pb({Y, W});
        graph[Y].pb({X, W});
    }

    int dist[N][N];
    F0R(r, N) {
        F0R(i, N) dist[r][i] = 1e9;
        dist[r][r] = 0;
        priority_queue<pi, vpi, greater<pi> > q;
        bool vis[N]; F0R(i, N) vis[i] = false;
        q.push({0, r});
        while (!q.empty()) {
            int x = q.top().s; q.pop();
            if (vis[x]) continue;
            vis[x] = true;
            trav(a, graph[x]) {
                if (ckmin(dist[r][a.f], dist[r][x] + a.s)) {
                    q.push({dist[r][a.f], a.f});
                }
            }
        }
    }

    int ans = 0;
    vpi R(K); F0R(i, K) cin >> R[i].f >> R[i].s;
    F0R(i, K) {
        R[i].f--; R[i].s--;
    }
    F0R(i, K) ans += dist[R[i].f][R[i].s];

    F0R(x, N) {
        trav(a, graph[x]) {
            int y = a.f; if (y < x) continue;
            int cur = 0;
            F0R(i, K) {
                cur += min(dist[R[i].f][R[i].s], min(dist[R[i].f][x] + dist[y][R[i].s], dist[R[i].f][y] + dist[x][R[i].s]));
            }
            ckmin(ans, cur);
        }
    }
    cout << ans << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343