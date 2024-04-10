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
const int MX = 100001; //check the limits, dummy
vector<vi> graph(MX);
int sub[MX];
vi ord, moves;

int dfss(int v, int p) {
    sub[v] = 1;
//    if (sz(graph[v]) == 1 && v != p) sub[v] = 1;
    trav(a, graph[v]) {
        if (a == p) continue;
        ckmax(sub[v], 1+dfss(a, v));
    }
    return sub[v];
}

void dfs(int v, int p) {
    ord.pb(v);
    vpi subs;
    trav(a, graph[v]) {
        if (a == p) continue;
        subs.pb({sub[a], a});
    }
    sort(all(subs)); 
    F0R(i, sz(subs)) {
        dfs(subs[i].s, v);
        if (i != sz(subs)-1) {
            F0R(j, subs[i].f) {
                moves.pb(subs[i+1].s);
            }
        }
    }
    
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N; cin >> N;
    FOR(i, 1, N) {
        int V; cin >> V;
        graph[V].pb(i);
        graph[i].pb(V);
    }

    dfss(0, 0);

    dfs(0, 0);

    F0R(i, N) {
        cout << ord[i] << " ";
    }
    cout << nl;
    cout << sz(moves) << nl;
    F0R(i, sz(moves)) {
        cout << moves[i] << " ";
    }
    cout << nl;

    
    return 0;

}
 
// read the question correctly (ll vs int)
// template by bqi343