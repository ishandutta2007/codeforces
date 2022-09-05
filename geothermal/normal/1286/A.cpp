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
    bool odd[N];
    bool cont[N];
    F0R(i, N) {
        int cur; cin >> cur;
        if (cur % 2 == 1) {
            odd[i] = true;
        } else {
            odd[i] = false;
        }
        if (cur > 0) {
            cont[i] = true;
        } else {
            cont[i] = false;
        }
    }

    int nO = (N+1)/2, nE = N/2;
    F0R(i, N) {
        if (cont[i]) {
            if (odd[i]) {
                nO--;
            } else {
                nE--;
            }
        }
    }

    int dp[N+1][nO+1][nE+1][2];
    F0R(i, N+1) {
        F0R(j, nO+1) {
            F0R(k, nE+1) {
                F0R(p, 2) {
                    dp[i][j][k][p] = 1000;
                }
            }
        }
    }
/*    if (cont[0]) {
        if (odd[0]) {
            dp[0][0][0][1] = 0;
        } else {
            dp[0][0][0][0] = 0;
        }
    } else {
        if (nO > 0) {
            dp[0][1][0][1] = 0;
        } 
        if (nE > 0) {
            dp[0][0][1][1] = 0;
        }
    }*/

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    F0R(i, N) {
        F0R(a, nO+1) {
            F0R(b, nE+1) {
                F0R(p, 2) {
                    //transition to odd
                    if (cont[i] && odd[i]) {
                        dp[i+1][a][b][1] = min(dp[i+1][a][b][1], dp[i][a][b][p] + 1-p);
                    }
                    if (!cont[i] && a < nO) {
                        dp[i+1][a+1][b][1] = min(dp[i+1][a+1][b][1], dp[i][a][b][p] + 1-p);
                    }

                    if (cont[i] && !odd[i]) {
                        dp[i+1][a][b][0] = min(dp[i+1][a][b][0], dp[i][a][b][p] + p);
                    }
                    if (!cont[i] && b < nE) {
                        dp[i+1][a][b+1][0] = min(dp[i+1][a][b+1][0], dp[i][a][b][p] + p);
                    }
                }
            }
        }
    }

    cout << min(dp[N][nO][nE][0], dp[N][nO][nE][1]) << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343