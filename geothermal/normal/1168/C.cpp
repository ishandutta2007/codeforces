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
const int MX = 300001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, Q; cin >> N >> Q;
    int data[N];
    F0R(i, N) cin >> data[i];

    int go[N][20];
    int last[20];
    F0R(i, 20) last[i] = MX;

    F0Rd(i, N) {
        F0R(j, 20) go[i][j] = MX;
        F0R(j, 20) {
            if (data[i] & (1 << j)) {

                go[i][j] = last[j];
            }
        }



        F0R(j, 20) {
            if (go[i][j] != MX) {
                F0R(k, 20) {
                    go[i][k] = min(go[i][k], go[go[i][j]][k]);
                }
            }
        }
        F0R(j, 20) if (data[i] & (1 << j)) { go[i][j] = i; last[j] = i; }
    }

    F0R(testCase, Q) {
        int X, Y; cin >> X >> Y; X--; Y--;
        bool done = false;
        F0R(i, 20) {
            if (data[Y] & (1 << i) && go[X][i] <= Y) {
                if (!done) cout << "Shi" << endl;
                done = true;
            }
        }
        if (!done) cout << "Fou" << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343