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
const int MX = 100001; //check the limits, dummy
vi graph[MX]; 

int dp[MX][2];

int ans = 1;

void dfs(int v, int p) {
    int dif = 0, dif2 = 0;
    int sum = 1;
    int cnt = 0;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        dfs(nxt, v);
        cnt++;
        dif = max(dif, max(dp[nxt][0], dp[nxt][1])-1);
        dif2 = max(dif2, dp[nxt][0]);
    }
    dp[v][0] = cnt + dif;
    dp[v][1] = 1+dif2;
}

void dfs2(int v, int p, int A, int B) {
    vi difs; difs.pb(0); difs.pb(0); difs.pb(0); difs.pb(0);
    vi difs2; difs2.pb(0); difs2.pb(0); difs2.pb(0); difs2.pb(0);
    int sum = 1; int cnt = 0; 
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        cnt++;
        difs.pb(max(dp[nxt][0], dp[nxt][1])-1);
        difs2.pb(dp[nxt][0]);
        sum += dp[nxt][0];
    }
    if (p != -1) {
        cnt++; sum += A;
        difs.pb(max(A, B)-1);
        difs2.pb(A);
    }
    sort(all(difs)); reverse(all(difs));
    sort(all(difs2)); reverse(all(difs2));
    ans = max(ans, max(cnt, 0) + difs[0] + difs[1]);
    ans = max(ans, difs2[0] + difs2[1] + 1);
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        int nA = max(cnt-1, 0);
        if (max(dp[nxt][0], dp[nxt][1])-1 == difs[0]) {
            nA += difs[1];
        } else {
            nA += difs[0];
        }
        int nB = difs2[0];
        if (difs2[0] == dp[nxt][0]) nB = difs2[1];
        nB++;
        dfs2(nxt, v, nA, nB);
    }

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }

    dfs(0, -1);
    dfs2(0, -1, 0, 0);

/*    F0R(i, N) {
        cout << dp[i][0] << " " << dp[i][1] << nl;
    }*/

    cout << ans << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343