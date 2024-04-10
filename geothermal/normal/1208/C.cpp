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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    int old[4][4] = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};
    int ans[N][N];
    F0R(i, 4) {
        F0R(j, 4) {
            F0R(x, N/4) {
                F0R(y, N/4) {
                    int val = x * (N/4) + y;
                    val *= 16; val += old[i][j];
                    ans[i * (N/4) + x][j * (N / 4) + y] = val;
                }
            }
        }
    }

    F0R(i, N) {
        F0R(j, N) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    int val = 0;
    F0R(i, N) {
        val = val ^ (ans[0][i]);
    }

    F0R(i, N) {
        int cur = 0;
        F0R(j, N) {
            cur = cur ^ (ans[i][j]);
        }
        if (cur != val) {
            cout << "BAD" << endl;
        }
    }

    F0R(j, N) {
        int cur = 0;
        F0R(i, N) {
            cur = cur ^ (ans[i][j]);
        }
        if (cur != val) {
            cout << "BAD" << endl;
        }
    }
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE