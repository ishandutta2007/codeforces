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
const int MX = 200001; //check the limits, dummy

int N;
int F[30];
vector<set<int>> graph(MX);
int sub[MX];
int par[MX];

int find(int v, int k, int p) {
    //cout << v << nl;
    par[v] = p;
    sub[v] = 1;
    int ans = -1;
    trav(a, graph[v]) {
        if (a != p) {
            ans = max(ans, find(a, k, v));
            sub[v] += sub[a];
        }
    }
    if (sub[v] == F[k]) return v;
    return ans;
}

int getCent(int v, int k, int p) {
    trav(a, graph[v]) {
        if (a != p && sub[a] * 2 >= F[k]) return getCent(a, k, v);
    }
    return v;
}

bool ok(int v, int k) {
    //cout << "Starting " << v << " " << k << nl;
    if (k <= 2) return true;
    //cout << "Go " << v << " " << k << nl;
    find(v, k, -1);
    int c = getCent(v, k, -1);
    int nxt = find(c, k-2, -1);
    if (nxt == -1) return false;
    graph[nxt].erase(par[nxt]);
    graph[par[nxt]].erase(nxt);
    return ok(nxt, k-2) && ok(c, k-1);
}


void solve() {

    F[0] = 1;
    F[1] = 1;
    FOR(i, 2, 30) {
        F[i] = F[i-1] + F[i-2];
    }
    cin >> N;
    int K = -1;
    F0R(i, 30) if (N == F[i]) K = i;
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--; graph[X].ins(Y); graph[Y].ins(X);
    }
    if (K == -1) {
        cout << "NO" << nl; return;
    }
    cout << (ok(0, K)?"YES":"NO") << nl;

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