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
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    int data[N]; F0R(i, N) cin >> data[i];
    int onesBefore[N], twosAfter[N];
    onesBefore[0] = 0; if (data[0] == 1) onesBefore[0]++;
    FOR(i, 1, N) {
        onesBefore[i] = onesBefore[i-1];
        if (data[i] == 1) onesBefore[i]++;
    }

    twosAfter[N-1] = 0;
    if (data[N-1] == 2) twosAfter[N-1]++;
    F0Rd(i, N-1) {
        twosAfter[i] = twosAfter[i+1];
        if (data[i] == 2) twosAfter[i]++;
    }
    int ans = 0;
    F0R(i, N) {
        ans = max(ans, onesBefore[i] + twosAfter[i]);
    }

    F0R(i, N) {
        int valStart = 0; if (i != 0) valStart = onesBefore[i-1];
        int curTotal = 0;
        int curTwos = 0;
        if (data[i] == 2) {
            curTotal++;
            curTwos++;
        }
        FOR(j, i+1, N) {
            if (data[j] == 2) {
                curTwos++;
                if (curTwos > curTotal) {
                    curTotal = curTwos;
                }
            } else {
                curTotal++;
            }
            int valEnd = 0;
            if (j != N-1) valEnd += twosAfter[j+1];
            ans = max(ans, curTotal + valStart + valEnd);
        }

    }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343