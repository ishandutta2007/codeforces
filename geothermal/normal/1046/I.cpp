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

    int N; cin >> N;

    int lo, hi; cin >> lo >> hi; lo = lo * lo; hi = hi * hi;

    int a, b, c, d; cin >> a >> b >> c >> d; //(a, b) (c, d)

    int count = 0;
    bool reachable = true;
    if ((c - a) * (c-a) + (d-b) * (d-b) <= lo) {
        count++;
        reachable = false;
    }

    FOR(cur, 1, N) {
        int nA, nB, nC, nD; cin >> nA >> nB >> nC >> nD;
        int sx = c - a;
        int sy = d - b;
        int dx = nC - nA - sx;
        int dy = nD - nB - sy;

        a = nA; b = nB; c = nC; d = nD;

        int sum = -1 * sx * dx - sy * dy;
        if (sum > 0 && dx * dx + dy * dy > sum) {
            double t = sum;
            t = t / (dx * dx + dy * dy);
            double distance = (t * dx + sx) * (t * dx + sx) + (t * dy + sy) * (t * dy + sy);
            if (reachable) {
                if (distance <= (double) lo) {
                    count++;
                    reachable = false;
                }
            } else {
                if (distance > (double) hi) {
                    reachable = true;
                }
            }
        }

        if (reachable && (c - a) * (c-a) + (d-b) * (d-b) <= lo) {
            count++;
            reachable = false;
        } else if ((c - a) * (c-a) + (d-b) * (d-b) > hi) {
            reachable = true;
        }
    }

    cout << count << endl;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343