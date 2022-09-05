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
    int data[n]; F0R(i, n) cin >> data[i];

    int remIndex = -1;

    int negCount = 0; F0R(i, n) if(data[i] < 0) negCount++;

    int zeroCount = 0; F0R(i, n) if(data[i] == 0) zeroCount++;

    bool bad[n]; F0R(i, n) bad[i] = false;

    if (zeroCount > 0) {
        if (zeroCount == n || zeroCount == n-1 && negCount % 2 == 1) {

        } else {
            F0R(i, n) if (data[i] == 0) bad[i] = true;
        }
    }

    if (negCount % 2 == 1) {
        int best = -1 * MOD;
        int bestIndex = -1;
        F0R(i, n) {
            if (data[i] < 0 && data[i] > best) {
                best = data[i];
                bestIndex = i;
            }
        }
        bad[bestIndex] = true;
    }

    int firstGood = -1;
    int firstBad = -1;

    F0R(i, n) {
        if (bad[i] == true) {
            if (firstBad == -1) {
                firstBad = i;
            } else {
                cout << "1 " << (i + 1) << " " << (firstBad + 1) << endl;
            }
        } else {
            if (firstGood == -1) {
                firstGood = i;
            } else {
                cout << "1 " << (i + 1) << " " << (firstGood + 1) << endl;
            }
        }
    }

    if (firstBad != -1) {
        cout << "2 " << (firstBad + 1) << endl;
    }

    /*if (zeroIndex != -1) {
        if (negCount % 2 == 0) {
            remIndex = zeroIndex;
        }
    } else {
        if (negCount % 2 == 1) {
            int best = -1 * MOD;
            int bestIndex = -1;
            F0R(i, n) {
                if (data[i] < 0 && data[i] > best) {
                    best = data[i];
                    bestIndex = i;
                }
            }
            remIndex = bestIndex;
        }
    }

    if (remIndex != -1) {
        cout << "2" << " " << (remIndex + 1) << endl;
    }

    int def = 0;
    if (remIndex == 0) def++;
    for (int i = def + 1; i < n; i++) {
        if (remIndex != i) {
            cout << "1 " << (i + 1) << " " << (def + 1) << endl;
        }
    }*/

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343