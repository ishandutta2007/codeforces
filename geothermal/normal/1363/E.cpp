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
const char nl = '\n';
const int MX = 200001; //check the limits, dummy
int N;
ll ans;
ll A[MX];
vector<vi> graph(MX);
int S[MX], E[MX];

pi dfs(int v, int p, ll c) {
    c = min(c, A[v]);
    pi res = {0, 0};
    if (S[v] != E[v]) {
        if (S[v] == 0) {
            res.f++;
        } else res.s++;
    }
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i]; if (nxt == p) continue;
        pi cur = dfs(nxt, v, c);
        res.f += cur.f;
        res.s += cur.s;
    }
    ll val = min(res.f, res.s);
    ans += c*val;
    res.f -= val; res.s -= val;
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    F0R(i, N) {
        cin >> A[i] >> S[i] >> E[i];
    }
    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }
    pi val = dfs(0, 0, 1e10);
    if (val.f != 0 || val.s != 0) {
        cout << -1 << nl; return 0;
    }
    cout << ans*2 << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343