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

    int N, M; cin >> N >> M;

    pi data[N][M];
    int first[N][M]; F0R(i, N) F0R(j, M) cin >> first[i][j];

    F0R(i, N) {
    	F0R(j, M) {
    		int cur; cin >> cur;
    		data[i][j] = mp(first[i][j], cur);
    	}
    }

    /*F0R(i, N) {
    	F0R(j, M) {
    		if (i == 0 && j == 0) continue;
    		if (i == 0 || j == 0) {
    			pi datLast;
    			if (i == 0) datLast = data[i][j-1];
    			if (j == 0) datLast = data[i-1][j];

    			vi prev; prev.pb(datLast.f); prev.pb(datLast.s);
    			vi cur; cur.pb(data[i][j].f); cur.pb(data[i][j].s);
    			sort(all(prev)); sort(all(cur));
    			if (prev[0] >= cur[0] || prev[1] >= cur[1]) {
    				cout << "Impossible" << endl;
    				return 0;
    			}
    		} else {
    			vi prev;
    			prev.pb(data[i-1][j].f); prev.pb(data[i][j-1].f); prev.pb(data[i-1][j].s); prev.pb(data[i][j-1].s);
    			vi cur; cur.pb(data[i][j].f); cur.pb(data[i][j].s);
    			sort(all(prev)); sort(all(cur));
    			if (prev[1] >= cur[0] || prev[3] >= cur[1]) {
    				cout << "Impossible" << endl;
    				return 0;
    			}
    		}
    	}
    }

    cout << "Possible" << endl;*/

    int lo[N][M], hi[N][M];
    F0R(i, N) {
        F0R(j, M) {
            lo[i][j] = min(data[i][j].f, data[i][j].s);
            hi[i][j] = max(data[i][j].f, data[i][j].s);
        }
    }

    F0R(i, N) {
        FOR(j, 1, M) {
            if (lo[i][j] <= lo[i][j-1] || hi[i][j] <= hi[i][j-1]) {
                cout << "Impossible" << endl; return 0;
            }
        }
    }

    FOR(i, 1, N) {
        F0R(j, M) {
            if (lo[i][j] <= lo[i-1][j] || hi[i][j] <= hi[i-1][j]) {
                cout << "Impossible" << endl; return 0;
            }
        }
    }

    cout << "Possible" << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343