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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    string A, B; cin >> A >> B;

    ll dp[N][2]; //cost of processing the first i elements such that A[i] = j.
    F0R(i, N) F0R(j, 2) dp[i][j] = 1000000000;

    dp[0][A[0] - '0'] = 0;

    F0R(i, N-1) {
        F0R(j, 2) {
            //case 1: no swap
            dp[i+1][A[i+1] - '0'] = min(dp[i+1][A[i+1]-'0'], dp[i][j] + (j == B[i] - '0'?0:1));
            //case 2: swap

            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1 + (A[i+1] - '0' == B[i] - '0'?0:1));
        }
    }

    ll res;
    F0R(j, 2) {
        if (j != B[N-1] - '0') dp[N-1][j]++;
    }

    cout << min(dp[N-1][0], dp[N-1][1]) << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE