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

    int n, m; cin >> n >> m;

    int data[n][m]; F0R(i, n) F0R(j, m) cin >> data[i][j];

    F0R(val, m) {
        int curData[n][m]; F0R(i, n) F0R(j, m) curData[i][j] = data[i][j];

        int colInv[m];
        F0R(i, val) { // goal: 0
            if (curData[0][i] == 1) {
                colInv[i] = 1;
            } else {
                colInv[i] = 0;
            }
        }
        FOR(i, val, m) {
            if (curData[0][i] == 0) {
                colInv[i] = 1;
            } else {
                colInv[i] = 0;
            }
        }
        F0R(i, m) {
            if (colInv[i]) {
                F0R(j, n) {
                    curData[j][i] = 1 - curData[j][i];
                }
            }
        }

        int rowInv[n]; rowInv[0] = 0;
        FOR(i, 1, n) {
            int invert = 1 - curData[i][0];
            FOR(j, 1, m) {
                if (curData[i][j] == invert) goto bad;
            }
            rowInv[i] = invert;

        }

        cout << "YES" << endl;
        F0R(i, n) cout << rowInv[i];
        cout << endl;
        F0R(i, m) cout << colInv[i];
        cout << endl;
        return 0;

        bad:;

    }

    int val = m;

    int curData[n][m]; F0R(i, n) F0R(j, m) curData[i][j] = data[i][j];

    int colInv[m];
    F0R(i, val) { // goal: 0
        if (curData[0][i] == 1) {
            colInv[i] = 1;
        } else {
            colInv[i] = 0;
        }
    }
    FOR(i, val, m) {
        if (curData[0][i] == 0) {
            colInv[i] = 1;
        } else {
            colInv[i] = 0;
        }
    }
    F0R(i, m) {
        if (colInv[i]) {
            F0R(j, n) {
                curData[j][i] = 1 - curData[j][i];
            }
        }
    }

    bool ones = false;
    int rowInv[n]; rowInv[0] = 0;
    FOR(i, 1, n) {
        //need either constant or monotonic;
        int type = 0;
        int curVal = curData[i][0];
        FOR(j, 1, m) {
            if (curData[i][j] != curVal) {
                type++; if (type == 2) goto done;
                curVal = curData[i][j];
            }
        }

        if (type == 0) {
            if (ones) {
                rowInv[i] = 1-curVal;
            } else {
                rowInv[i] = curVal;
            }
        } else {
            if (ones) goto done;
            ones = true;
            rowInv[i] = 1-curVal;
        }
    }

    cout << "YES" << endl;
    F0R(i, n) cout << rowInv[i];
    cout << endl;
    F0R(i, m) cout << colInv[i];
    cout << endl;
    return 0;

    done:;

    cout << "NO" << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343