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
    int N;
    string S;
    cin >> N >> S;

    int dp[N+1][3][2]; 
    F0R(i, N+1) {
        F0R(j, 3) {
            F0R(k, 2) {
                dp[i][j][k] = -1*MX*2;
            }
        }
    }

    dp[0][0][0] = 0; dp[0][0][1] = 0;

    vi data(N); F0R(i, N) data[i] = S[i] - '0';

    F0R(i, N) {
        F0R(iState, 3) {
            F0R(trans, 2) {
                int nState = iState+trans;
                if (nState == 3) continue;
                F0R(last, 2) {
                    int val = data[i];
                    if (nState == 1) val = 1-val;
                    if (val == last) {
                        dp[i+1][nState][last] = max(dp[i+1][nState][last], dp[i][iState][last]);
                    } else {
                        dp[i+1][nState][val] = max(dp[i+1][nState][val], dp[i][iState][last] + 1);
                    }
                }
            }
        }
    }
    int ans = 0;
    F0R(i, 3) {
        F0R(j, 2) {
            ans = max(ans, dp[N][i][j]);
        }
    }
    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343