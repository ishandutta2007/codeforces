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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int Q; cin >> Q;
    while(Q--) {
        int N; cin >> N;
        vi T(N); F0R(i, N) cin >> T[i];
        F0R(i, N-1) {
            if (T[i] != T[i+1]) goto noOne;
        }
        cout << 1 << endl; F0R(i, N) cout << "1 ";
        cout << endl;
        continue;
        noOne:
        ;

        int dp[N][2]; F0R(i, N) F0R(j, 2) dp[i][j] = -1;
        dp[0][0] = 0;
        F0R(i, N-1) {
            F0R(j, 2) {
                if (dp[i][j] == -1) continue;
                dp[i+1][1-j] = j;
                if (T[i] == T[i+1]) dp[i+1][j] = j;
            }
        }

        if ((dp[N-1][0] == -1 || T[N-1] != T[0]) && dp[N-1][1] == -1) {
            cout << 3 << endl;
            F0R(i, N-1) {
                cout << (i%2) + 1 << " ";
            }
            cout << 3 << endl;
            continue;
        }
        vi ans;
        int cur = 0; if (dp[N-1][0] == -1 || T[N-1] != T[0]) cur = 1;
        F0Rd(i, N) {
            ans.pb(cur);
            cur = dp[i][cur];
        }
        reverse(all(ans));
        cout << 2 << endl;
        F0R(i, N) cout << ans[i] + 1 << " ";
        cout << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343