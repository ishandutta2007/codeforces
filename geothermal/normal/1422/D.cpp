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
	
    ll M, N; cin >> M >> N;
    ll A, B, C, D; cin >> A >> B >> C >> D;
    ll X[N], Y[N]; F0R(i, N) cin >> X[i] >> Y[i];
    vpl xp; F0R(i, N) xp.pb({X[i], i});
    sort(all(xp));
    vector<vpl> graph(N);
    F0R(i, N-1) {
        ll dist = xp[i+1].f - xp[i].f;
        graph[xp[i].s].pb({xp[i+1].s, dist});
        graph[xp[i+1].s].pb({xp[i].s, dist});
    }
    vpl yp; F0R(i, N) yp.pb({Y[i], i});
    sort(all(yp));
    F0R(i, N-1) {
        ll dist = yp[i+1].f - yp[i].f;
        graph[yp[i].s].pb({yp[i+1].s, dist});
        graph[yp[i+1].s].pb({yp[i].s, dist});
    }

    ll dist[N];
    F0R(i, N) dist[i] = min(abs(A - X[i]), abs(B - Y[i]));

    priority_queue<pl, vpl, greater<pl> > q;
    F0R(i, N) {
        q.push({dist[i], i});
    }
    bool vis[N]; F0R(i, N) vis[i] = false;

    while (!q.empty()) {
        int cur = q.top().s;
        q.pop();
        if (vis[cur]) continue;
        trav(a, graph[cur]) {
            if (dist[cur] + a.s < dist[a.f]) {
                dist[a.f] = dist[cur] + a.s;
                q.push({dist[a.f], a.f});
            }
        }
    }
    ll ans = abs(A-C) + abs(B - D);
    F0R(i, N) {
        ckmin(ans, dist[i] + abs(C - X[i]) + abs(D - Y[i]));
    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343