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
vector<vi> graph; 
ll sub[MX];
ll H[MX];
ll P[MX];

void dfs1(int v, int p) {
    sub[v] = P[v];
    trav(a, graph[v]) {
        if (a == p) continue;
        dfs1(a, v);
        sub[v] += sub[a];
    }
}

bool dfs2(int v, int p) {
    ll sum = 0;
    if (abs(H[v]) > sub[v] || abs(H[v]) % 2 != sub[v] % 2) return false;
    trav(a, graph[v]) {
        if (a == p) continue;
        if (!dfs2(a, v)) return false;
        sum += H[a];
    }
    if (sum > H[v] + P[v]) return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        graph.clear();
        int N, M; cin >> N >> M;
        F0R(i, N) graph.pb(vi());
        F0R(i, N) cin >> P[i];
        F0R(i, N) cin >> H[i];
        F0R(i, N-1) {
            int X, Y; cin >> X >> Y; X--; Y--; graph[X].pb(Y); graph[Y].pb(X);
        }

        dfs1(0, -1);
        cout << (dfs2(0, -1)?"YES":"NO") << nl;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343