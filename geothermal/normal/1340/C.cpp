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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int X, N; cin >> X >> N;
    vi A(N); F0R(i, N) cin >> A[i];
    sort(all(A));
    int G, R; cin >> G >> R;
    ll dp[N][G];
	  queue<pi> q;
    F0R(i, N) {
        F0R(j, G) {
            dp[i][j] = 2e9;
        }
    }
    dp[0][0] = 0;
    vpi cur;
    vpi nxt = {{0,0}};
    q.push({0, 0});
    bool vis[N][G]; F0R(i, N) F0R(j, G) vis[i][j] = false;
    while (true) {
        cur = nxt;
        nxt.clear();
        int i = 0;
        while (i < sz(cur)) {
        int P = cur[i].f;
        int M = cur[i].s;
			int cd = dp[P][M];
        
        if (vis[P][M]) continue;
        vis[P][M] = true;

        if (P > 0) {
            int D = A[P] - A[P-1];
            int nd = cd + 0;
            int nm = M + D;
            if (nm <= G) {
                if (nm == G) {
                    nm = 0; nd += 1;
                }
                if (nd < dp[P-1][nm]) {
                    dp[P-1][nm] = nd;
                    if (nd == cd) {
                    cur.pb({P-1, nm});
                    } else nxt .pb({P-1, nm});
                }
            }
        }
        if (P < N-1) {
            int D = A[P+1] - A[P];
            int nd = cd + 0;
            int nm = M + D;
            if (nm <= G) {
                if (nm == G) {
                    nm = 0; nd += 1;
                }
                if (nd < dp[P+1][nm]) {
                    dp[P+1][nm] = nd;
if (nd == cd) {
                    cur.pb({P+1, nm});
                    } else nxt .pb({P+1, nm});
                    
                }
            }
        }
         i++;
        }
        if (sz(nxt) == 0) break;
    }
    dp[N-1][0] -= 1;
    ll ans = 2e9;
    F0R(i, G) {
        ll cur = 1ll * dp[N-1][i] * (R+G);
        cur += i;
         if (i == 0) cur += G;
        ans = min(ans, cur);
    }
    if (ans < 1e9) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343