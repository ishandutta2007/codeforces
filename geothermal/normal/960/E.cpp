#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef complex<ll> cl;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<cl> vcl;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200001; //check the limits, dummy
int N;
vector<vi> graph(MX);
ll ans = 0;
ll V[MX];
ll C[MX][2];

void dfs1(int v, int p, int d) {
    C[v][0] = 0, C[v][1] = 0;
    C[v][d%2]++;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        dfs1(nxt, v, d+1);
        C[v][0] += C[nxt][0];
        C[v][1] += C[nxt][1];
    }
}

void dfs2(int v, int p, int d) {
    ll cV = V[v];
    ans += cV * N; ans %= MOD;
    int c = d%2;
    ll total = C[0][c] - C[v][c] + MOD - (C[0][1-c] - C[v][1-c]);
    total %= MOD;
    total *= C[v][0] + C[v][1]; total %= MOD;
    ans += total * cV; ans %= MOD;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        dfs2(nxt, v, d+1);
        total = C[nxt][c] + MOD - C[nxt][1-c];
        total %= MOD;
        total *= N - (C[nxt][c] + C[nxt][1-c]);
        total %= MOD;
        ans += total * cV; ans %= MOD;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    F0R(i, N) cin >> V[i];
    F0R(i, N) {
        V[i] += MOD; V[i] %= MOD;
    }

    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }
    dfs1(0, -1, 0);
    dfs2(0, -1, 0);
    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343