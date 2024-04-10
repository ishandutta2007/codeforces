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
    int dontcare[N]; F0R(i, N) cin >> dontcare[i];
    int data[N]; F0R(i, N) cin >> data[i];

    int suffix = -1;
    F0R(i, N) {
        if (suffix == -1) {
            if (data[i] == 1) {
                suffix = i;
            }
        } else {
            if (data[i] != i - suffix + 1) {
                suffix = -1;
            }
        }
    }
    bool found[N];
    F0R(i, N) found[i] = false;
    F0R(i, N) {
        if (dontcare[i] > 0) found[dontcare[i]-1] = true;
    }
    int cur = N-suffix;
    bool bad = false;
    F0R(i, suffix) {
        if (!found[cur]) {
            bad = true;
        }
        cur++;
        if (data[i] != 0) found[data[i]-1] = true;
    }
    if (suffix != -1 && !bad) {
        cout << suffix << endl;
        return 0;
    }

    int mx = 0;
    F0R(i, N) {
        if (data[i] != 0) mx = max(mx, i - data[i] + 2);
    }
    cout << N+mx << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343