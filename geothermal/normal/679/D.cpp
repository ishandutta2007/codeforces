#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
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
    vector<vi> graph(N);
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }
 
    int dist[N][N]; F0R(i, N) F0R(j, N) dist[i][j] = N+1;
    F0R(r, N) {
        dist[r][r] = 0;
        queue<int> q; q.push(r);
        while (!q.empty()) {
            int X = q.front(); q.pop();
            trav(a, graph[X]) {
                if (ckmin(dist[r][a], dist[r][X] + 1)) {
                    q.push(a);
                }
            }
        }
    }
    ld ans = 0;
    F0R(r, N) {
        vector<vi> atDist(N);
        F0R(i, N) {
            atDist[dist[r][i]].pb(i);
        }
        ld curAns = 0;
        F0R(d, N) {
            if (sz(atDist[d]) == 0) continue;
            ld prob[N]; F0R(i, N) prob[i] = 0;
            bool inClose[N]; F0R(i, N) inClose[i] = false;
            trav(a, atDist[d]) {
                trav(b, graph[a]) {
                    ld num = sz(atDist[d]) * sz(graph[a]);
                    prob[b] += 1 / num;
                    inClose[b] = true;
                }
            }
            vi close; F0R(i, N) if (inClose[i]) close.pb(i);
 
            ld best = 0;
            ld sum[N], hi[N]; F0R(i, N) sum[i] = 0, hi[i] = 0;
            F0R(i, N) {
                vi used;
                ld tnum = 0;
                trav(a, close) {
                    sum[dist[i][a]] += prob[a];
                    tnum += prob[a];
                    hi[dist[i][a]] = max(hi[dist[i][a]], prob[a]);
                    used.pb(dist[i][a]);
                }
                ld cur = 0;
                trav(a, used) {
                    if (sum[a] > 0) {
                        cur += hi[a] / tnum;
                        hi[a] = 0; sum[a] = 0;
                    }
                }
                ckmax(best, cur);
            }
            curAns += max(1 / ((ld) sz(atDist[d])), best) * ((ld) sz(atDist[d])) / ((ld) N);
 
        }
        ckmax(ans, curAns);
    }
    cout << setprecision(20) << ans << nl;
 
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