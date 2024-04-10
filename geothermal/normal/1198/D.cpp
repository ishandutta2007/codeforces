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
    bool grid[N][N];
    F0R(i, N) {
        F0R(j, N) {
            char C; cin >> C;
            grid[i][j] = C == '#';
        }
    }

    int prefSums[N][N];
    F0R(i, N) {
        F0R(j, N) {
            prefSums[i][j] = 0; if (grid[i][j]) prefSums[i][j] = 1;
            if (i > 0) prefSums[i][j] += prefSums[i-1][j];
            if (j > 0) prefSums[i][j] += prefSums[i][j-1];
            if (i > 0 && j > 0) prefSums[i][j] -= prefSums[i-1][j-1];
        }
    }

    int dp[N][N][N][N];
    FOR(dx, 0, N) {
        FOR(dy, 0, N) { // cost of (i, j) to (x, y), inclusive
           F0R(i, N-dx) {
               F0R(j, N - dy) {
                    int x = i + dx;
                    int y = j + dy;
                    dp[i][j][x][y] = max(x-i+1, y-j+1);
                    int countSums = prefSums[x][y];
                    if (i > 0) countSums -= prefSums[i-1][y];
                    if (j > 0) countSums -= prefSums[x][j-1];
                    if (i > 0 && j > 0) countSums += prefSums[i-1][j-1];
                    if (countSums == 0) dp[i][j][x][y] = 0;
                    FOR(bp, i, x) {
                        dp[i][j][x][y] = min(dp[i][j][x][y], dp[i][j][bp][y] + dp[bp+1][j][x][y]);
                    }
                    FOR(bp, j, y) {
                        dp[i][j][x][y] = min(dp[i][j][x][y], dp[i][j][x][bp] + dp[i][bp+1][x][y]);
                    }
                }
            }
        }
    }

    cout << dp[0][0][N-1][N-1] << endl;
    
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343