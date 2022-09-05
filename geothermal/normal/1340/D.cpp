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
const int MX = 100011; //check the limits, dummy
vpi ans;
int M;
vector<vi> graph(MX);

void dfs(int v, int x, int p) {
    ans.pb({v, x});
    if (sz(graph[v]) == 1) {
        ans.pb({v, x-1}); return;
    }
    int tot = sz(graph[v]) - 1;
    int cur = 0;
    int goal = x-1; //have x-1 when you leave
    bool found = false;
    F0R(i, sz(graph[v])) {
        if (graph[v][i] == p) continue;
        if (tot - cur <= goal && !found) {
            x = goal - tot + cur;
            ans.pb({v, x});
            found = true;
        }
        x++;
        dfs(graph[v][i], x, v);
        ans.pb({v, x});
        cur++;
    }
    if (tot - cur <= goal && !found) {
        x = goal - tot + cur;
        ans.pb({v, x});
        found = true;
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y;
        graph[X].pb(Y);
        graph[Y].pb(X);
    }
    ans.pb({1, 0});
    M = 0; F0R(i, N) M = max(M, sz(graph[i]));
    F0R(i, sz(graph[1])) {
        dfs(graph[1][i], i+1, 1);
        ans.pb({1, i+1});
    }

    cout << sz(ans) << nl;
    F0R(i, sz(ans)) {
        cout << ans[i].f << " " << ans[i].s << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343