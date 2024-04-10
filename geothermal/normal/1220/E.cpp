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
vector<vi> graph(MX); 
ll W[MX];
bool good[MX];
bool vis[MX];
int cc[MX];
int val[MX];
ll tg = 0;
ll bt = 0;

int dfs1(int v, int p) {
    int cur = 0;
    vis[v] = true;
    cc[v] = 0;
    val[v] = 0;
    trav(a, graph[v]) {
        if (a == p) continue;
        if (vis[a]) {
            cur++; cc[a]++;
        } else {
            cur += dfs1(a, v);
            val[v] += val[a];
        }
    }
    if (cur > 0) {
        good[v] = true;
        val[v]++;
    }
    return cur - cc[v];
}

void dfs2(int v, int p, bool found) {
    found = found || good[v];
    good[v] = found && val[v] > 0;
    if (good[v]) tg += W[v];
    vis[v] = true;
    trav(a, graph[v]) {
        if (!vis[a]) dfs2(a, v, found);
    }
}

void dfs3 (int v, int p, ll cur) {
    cur += W[v];
    ckmax(bt, cur);
    trav(a, graph[v]) {
        if (a == p || good[a]) continue;
        dfs3(a, v, cur);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    F0R(i, N) cin >> W[i];
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }

    F0R(i, N) {
        good[i] = false; vis[i] = false; cc[i] = 0;
    }
    int S; cin >> S; S--;
    dfs1(S, S);
    F0R(i, N) vis[i] = false;
    dfs2(S, S, false);
    
    F0R(i, N) {
        if (good[i]) continue;
        bool found = false;
        trav(a, graph[i]) if (good[a]) found = true;
        if (found) {
            dfs3(i, i, 0);
        }
    }

    ll ans = bt + tg;
    bt = 0;
    if (!good[S]) {
        dfs3(S, S, 0);
        ckmax(ans, bt);
    }

    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343