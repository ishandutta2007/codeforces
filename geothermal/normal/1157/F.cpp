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
const int MX = 200002;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    int counts[MX]; F0R(i, MX) counts[i] = 0;
    F0R(i, N) {int cur; cin >> cur; counts[cur]++; }

    int best = -1;
    int hiBest = 0;

    int oneStart = false;
    int chainLength = 0;
    F0R(i, MX) {
        if (counts[i] >= 2) {
            chainLength+=counts[i];
        } else if (counts[i] == 1) {
            if (chainLength + 1 + (oneStart ? 1 : 0) > best) {
                best = chainLength + 1 + (oneStart ? 1 : 0);
                hiBest = i;
            }
            oneStart = true;

            chainLength = 0;
        } else {
            if (chainLength + (oneStart ? 1 : 0) > best) {
                best = chainLength + (oneStart ? 1 : 0);
                hiBest = i-1;
            }
            oneStart = false;
            chainLength = 0;
        }

    }

    cout << best << endl;
    int lo;
    vector<int> result;
    if (counts[hiBest] > 1) F0R(i, counts[hiBest]-1) result.pb(hiBest);
    F0Rd(i, hiBest) {
        if (counts[i] < 2) {
            lo = counts[i] == 1 ? i : i+1;
            break;
        } else {
            F0R(j, counts[i]-1) result.pb(i);
        }
    }
    FOR(i, lo, hiBest+1) result.pb(i);


    F0R(i, sz(result)) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343