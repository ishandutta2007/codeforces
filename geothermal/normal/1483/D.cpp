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
    vector<vector<pair<int, pair<ll, int>>>> graph(N);
    F0R(i, M) {
        int X, Y, Z; cin >> X >> Y >> Z; X--; Y--;
        graph[X].pb({Y, {Z, i}}); graph[Y].pb({X, {Z, i}}); 
    }
    int Q; cin >> Q;
    ll mind[N][N]; F0R(i, N) F0R(j, N) mind[i][j] = 0;
    while(Q--) {
        int U, V; ll L;
        cin >> U >> V >> L;
        U--; V--;
        mind[U][V] = L; mind[V][U] = L;
    }

    ll dist[N][N]; F0R(i, N) F0R(j, N) dist[i][j] = 1e18;
    F0R(i, N) {
        trav(a, graph[i]) {
            dist[i][a.f] = a.s.f;
        }
    }
    F0R(i, N) dist[i][i] = 0;
    F0R(k, N) {
        F0R(i, N) {
            F0R(j, N) {
                ckmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    F0R(i, N) {
        F0R(j, N) {
            F0R(k, N) {
                ckmax(mind[i][j], mind[i][k] - dist[k][j]);
            }
        }
    }

    bool val[M]; F0R(i, M) val[i] = false;
    F0R(r, N) {
        /*ll dist[N]; F0R(i, N) dist[i] = 1e18;
        dist[r] = 0;
        priority_queue<pl, vpl, greater<pl>> q;
        q.push({0, r});
        while (!q.empty()) {
            int v = q.top().s; ll d =  q.top().f; q.pop();
            if (d != dist[v]) continue;
            trav(a, graph[v]) {
                if (ckmin(dist[a.f], dist[v]+a.s.f)) {
                    q.push({dist[a.f], a.f});
                }
            }
        }

        priority_queue<pl> q2;
        F0R(i, N) {
            q2.push({mind[r][i], i});
        }
        while (!q2.empty()) {
            int v = q2.top().s; ll d = q2.top().f; q2.pop();
            if (d != mind[r][v]) continue;
            trav(a, graph[v]) {
                if (ckmax(mind[r][a.f], mind[r][v] - a.s.f)) {
                    q2.push({mind[r][a.f], a.f});
                }
            }
        }*/

        F0R(i, N) {
            trav(a, graph[i]) {
                if (dist[r][i] + a.s.f <= mind[r][a.f]) val[a.s.s] = true;
            }
        }
    }
    int ans = 0; F0R(i, M) if (val[i]) ans++;
    cout << ans << nl;

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