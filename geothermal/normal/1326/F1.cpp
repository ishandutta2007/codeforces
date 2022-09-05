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
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    bool adj[N][N]; F0R(i, N) F0R(j, N) {
        char C; cin >> C; adj[i][j] = C == '1';
    }

    vector<vl> dp[1 << N];
    F0R(i, 1 << N) {
        if (i == 0) continue;
        int cnt = 0;
        F0R(j, N) {
            if (i & (1 << j)) {
                cnt++;
            }
        }
        F0R(j, (1 << (cnt-1))) {
            vl blank(N, 0);
            dp[i].pb(blank);
        }
    }
    F0R(i, N) {
        dp[(1 << i)][0][i] = 1;
    }
    FOR(used, 1, (1 << N)) {
        vi in, out;
        F0R(i, N) {
            if (used & (1 << i)) {
                in.pb(i);
            } else {
                out.pb(i);
            }
        }
        F0R(mask, (1 << (sz(in)-1))) {
            F0R(i, sz(in)) {
                F0R(j, sz(out)) {
                    int nxt = mask << 1 ; if (adj[in[i]][out[j]]) nxt++;
                    int nxtUsed = used | (1 << out[j]);
/*                    cout << used << " " << nxtUsed << " " << mask << " " << nxt << " " << in[i] << " " << out[j] << endl;
                    cout << sz(dp[nxtUsed]) << endl;
                    cout << sz(dp[nxtUsed][nxt]) << endl;
                    cout << sz(dp[used]) << endl;
                    cout << sz(dp[used][mask]) << endl;*/
                    dp[nxtUsed][nxt][out[j]] += dp[used][mask][in[i]];
                }
            }
        }


    }

    ll ans[(1 << (N-1))];
    F0R(i, (1 << (N-1))) {
        ans[i] = 0;
        F0R(j, N) {
            ans[i] += dp[(1 << N) - 1][i][j];
        }
        cout << ans[i] << " ";
    }
    cout << endl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343