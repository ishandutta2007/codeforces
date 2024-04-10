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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int n; cin >> n;
    int dp[n][3];
    int last[n][3];
    F0R(i, n) {
        F0R(j, 3) {
            dp[i][j] = 10000000; last[i][j] = -1;
        }
    }
    vi data(n); string str; cin >> str;
    F0R(i, n) {
        if (str[i] == 'R') {
            data[i] = 0;
        } else if (str[i] == 'G') {
            data[i] = 1;
        } else data[i] = 2;
    }
    dp[0][data[0]] = 0;

    F0R(i, n-1) {
        F0R(j, 3) {
            if (j != 0) {
                int cur = dp[i][j];
                if (data[i+1] != 0) {
                    cur++;
                }
                if (cur < dp[i+1][0]) {
                    dp[i+1][0] = cur;
                    last[i+1][0] = j;
                }
            }
            if (j != 1) {
                int cur = dp[i][j];
                if (data[i+1] != 1) {
                    cur++;
                }
                if (cur < dp[i+1][1]) {
                    dp[i+1][1] = cur;
                    last[i+1][1] = j;
                }
            }
            if (j != 2) {
                int cur = dp[i][j];
                if (data[i+1] != 2) {
                    cur++;
                }
                if (cur < dp[i+1][2]) {
                    dp[i+1][2] = cur;
                    last[i+1][2] = j;
                }
            }
        }
    }

    int best = 0;
    if (dp[n-1][1] < dp[n-1][0]) {
        best = 1;
    }
    if (dp[n-1][2] < dp[n-1][best]) best = 2;

    vi reconstruction;
    int cur = best;
    F0Rd(i, n) {
        reconstruction.pb(cur);
        if (i > 0) {
            cur = last[i][cur];
        }
    }

    cout << dp[n-1][best] << endl;

    F0Rd(i, n) {
        if (reconstruction[i] == 0) {
            cout << 'R';
        } else if (reconstruction[i] == 1) {
            cout << 'G';
        } else cout << 'B';
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343