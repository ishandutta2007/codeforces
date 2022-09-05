#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 101; //check the limits, dummy

int A[MX][MX];

int sum() {
    return A[0][0] + A[0][1] + A[1][1] + A[1][0];
}

void solve() {

    int N, M; cin >> N >> M;
    F0R(i, N) {
        F0R(j, M) {
            char C; cin >> C; A[i][j] = C - '0';
        }
    }
    vector<vpi> ops;
    FORd(i, 2, N) {
        F0R(j, M-1) {
            if (A[i][j] == 0 && A[i][j+1] == 0) continue;
            vpi cur;
            cur.pb({i-1, j});
            A[i-1][j] = 1 - A[i-1][j];
            bool found = false;
            if (A[i][j] == 1) {
                cur.pb({i, j});
                A[i][j] = 1 - A[i][j];
            } else found = true;
            if (A[i][j+1] == 1) {
                cur.pb({i, j+1});
                A[i][j+1] = 1 - A[i][j+1];
            } else found = true;

            if (found) {
                cur.pb({i-1, j+1});
                A[i-1][j+1] = 1 - A[i-1][j+1];
            }
            ops.pb(cur);
        }
    }

    FORd(j, 2, M) {
        if (A[0][j] == 0 && A[1][j] == 0) continue;
        vpi cur;
        cur.pb({0, j-1});
        A[0][j-1] = 1 - A[0][j-1];
        int cnt = 0;
        if (A[0][j] == 1) {
            cur.pb({0, j});
            A[0][j] = 1 - A[0][j];
            cnt++;
        }
        if (A[1][j] == 1) {
            cur.pb({1, j});
            A[1][j] = 1 - A[1][j];
            cnt++;
        }
        if (cnt < 2) {
            cur.pb({1, j-1});
            A[1][j-1] = 1 - A[1][j-1];
        }
        ops.pb(cur);
    }

    if (sum() == 4) {
        vpi cur;
        cur.pb({0, 0}); cur.pb({0, 1}); cur.pb({1, 0});
        trav(a, cur) {
            A[a.f][a.s] = 1 - A[a.f][a.s];
        }
        ops.pb(cur);
    }

    if (sum() == 1) {
        bool found = false;
        vpi cur;
        F0R(i, 2) {
            F0R(j, 2) {
                if (!found && A[i][j] == 0) {
                    found = true;
                } else {
                    cur.pb({i, j});
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        ops.pb(cur);
    }

    if (sum() == 2) {
        bool found = false;
        vpi cur;
        F0R(i, 2) {
            F0R(j, 2) {
                if (!found && A[i][j] == 1) {
                    found = true;
                } else {
                    cur.pb({i, j});
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        ops.pb(cur);

    }

    if (sum() == 3) {
        vpi cur;
        F0R(i, 2) {
            F0R(j, 2) {
                if (A[i][j] == 1) {
                    cur.pb({i, j});
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        ops.pb(cur);
    }

    cout << sz(ops) << nl;
    trav(a, ops) {
        trav(b, a) {
            cout << b.f + 1 << " " << b.s + 1 << " ";
        }
        cout << nl;
    }
    bool found = false;
    F0R(i, N) {
        F0R(j, M) {
            if (A[i][j] != 0) found = true;
        }
    }
    if (found) {
        cout << "ERROR\n";
        F0R(i, N) {
            F0R(j, M) {
                cout << A[i][j];
            }
            cout << nl;
        }
    }

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343