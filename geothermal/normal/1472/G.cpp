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
        vector<vi> g1(N);
        F0R(i, M) {
            int X, Y; cin >> X >> Y;
            X--; Y--;
            g1[X].pb(Y); 
        }
        int dist[N]; F0R(i, N) dist[i] = N+1;
        dist[0] = 0;
        queue<int> q1; q1.push(0);
        while (!q1.empty()) {
            int cur = q1.front(); q1.pop();
            trav(a, g1[cur]) {
                if (dist[cur] + 1 < dist[a]) {
                    dist[a] = dist[cur] + 1; q1.push(a);
                }
            }
        }
        vector<vi> graph(2*N);
        F0R(i, N) {
            trav(a, g1[i]) {
                if (dist[a] > dist[i]) {
                    graph[a].pb(i); graph[a+N].pb(i+N);
                } else {
                    graph[a+N].pb(i);
                }
            }
        }
        int fdist[2*N]; F0R(i, 2*N) fdist[i] = dist[i%N];
        priority_queue<pi, vpi, greater<pi>> q;
        bool vis[2*N]; F0R(i, 2*N) vis[i] = false;
        F0R(i, 2*N) {
            q.push({fdist[i], i});
        }
        while (!q.empty()) {
            int cur = q.top().s; q.pop();
            if (vis[cur]) continue;
            vis[cur] = true;
            trav(a, graph[cur]) {
                if (ckmin(fdist[a], fdist[cur])) {
                    q.push({fdist[a], a}); 
                }
            }
        }
        F0R(i, N) {
            cout << min(fdist[i], fdist[i+N]) << " ";
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343