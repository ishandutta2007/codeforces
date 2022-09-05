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
vector<vi> graph(MX);
int ans = 0;

int dfs(int v, int p) {
    vi ops;
    trav(a, graph[v]) {
        if (a == p) continue;
        ops.pb(dfs(a, v));
    }
    sort(all(ops)); reverse(all(ops));
    if (sz(ops) > 1) ckmax(ans, ops[0] + ops[1]);
    if (sz(ops) > 0) ckmax(ans, ops[0]);
    if (sz(ops) > 0) {
        return ops[0] + 1;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, A, B, X, Y; cin >> N >> A >> B >> X >> Y;
        A--; B--;
        ans = 0; F0R(i, N) graph[i].clear();
        F0R(i, N-1) {
            int U, V; cin >> U >> V; U--; V--;
            graph[U].pb(V);
            graph[V].pb(U);
        }

        dfs(0, 0);

        int dist[N]; F0R(i, N) dist[i] = -1;
        dist[A] = 0;
        queue<int> q;
        q.push(A);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            trav(a, graph[cur]) {
                if (dist[a] == -1) {
                    dist[a] = dist[cur] + 1;
                    q.push(a);
                }
            }
        }
        cout << (Y>=X*2+1&&ans>=X*2+1&&dist[B]>X?"Bob":"Alice") << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343