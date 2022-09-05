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
#define shandom_ruffle random_shuffle

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    int data[N]; F0R(i, N) cin >> data[i];
    F0R(i, N) data[i]--;
    ll dp[N][N];
    F0R(i, N) dp[i][i] = 1;
    FOR(len, 1, N) {
        F0R(i, N-len) {
            int minPos = -1;
            int minVal = N+1;
            FOR(j, i, i+len+1) {
                if (data[j] < minVal) {
                    minVal = data[j];
                    minPos = j;
                }
            }

            ll loCount;
            ll hiCount;
            if (i != minPos) {
                loCount = 2*dp[i][minPos-1];
            } else {
                loCount = 1;
            }
            if (minPos != i+len) {
                hiCount = 2*dp[minPos+1][i+len];
            } else hiCount = 1;
            FOR(j, i+1, i+len) {
                if (j < minPos) {
                    loCount += dp[i][j-1] * dp[j][minPos-1];
                    loCount %= MOD;
                } else if (j > minPos) {
                    hiCount += dp[minPos+1][j] * dp[j+1][i+len];
                    if (i == 0 && len == 3) {
                        //cout << j << " " << dp[minPos+1][j] << " " << dp[j][i+len] << endl;
                    }
                    hiCount %= MOD;
                }
            }

            dp[i][i+len] = loCount * hiCount;
            dp[i][i+len] = dp[i][i+len] % MOD;
        }
    }

    cout << dp[0][N-1] << endl;

    /*F0R(i, N) {
        F0R(j, N) {
            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }*/

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343