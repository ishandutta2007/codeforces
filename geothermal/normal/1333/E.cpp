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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 501; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    if (N <= 2) {
        cout << -1 << endl; return 0;
    }

    int giv[3][3] = {{1, 2, 4}, {5, 3, 8}, {9, 6, 7}};
    if (N == 3) {
        F0R(i, 3) {
            F0R(j, 3) {
                cout << giv[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }

    int cur[MX][MX]; F0R(i, 3) F0R(j, 3) cur[i][j] = giv[i][j];
    int nxt[MX][MX];
    FOR(it, 4, N+1) {
        F0R(i, it-1) {
            F0R(j, it-1) {
                nxt[i][j] = cur[i][j] + it * 2 - 1;
            }
        }
        if (it % 2 == 0) {
            F0R(i, it) {
                nxt[i][it-1] = i+1;
            } 
            F0Rd(i, it-1) {
                nxt[it-1][i] = 2*it-1-i;
            }
        } else {
            F0R(i, it) {
                nxt[it-1][i] = i+1;
            } 
            F0Rd(i, it-1) {
                nxt[i][it-1] = 2*it-1-i;
            }
        }
        F0R(i, it) F0R(j, it) cur[i][j] = nxt[i][j];
    }

    F0R(i, N) {
        F0R(j, N) {
            cout << cur[i][j] << " ";
        }
        cout << endl;
    }

    /*if (N == 5) {
        F0R(i, 4) {
            F0R(j, 4) {
                cout << giv[i][j] + 9 << " ";
            }
            cout << 
        }
    }
    int ans[N][N]; int cur = 1;
    F0R(i, N) {
        if (i % 2 == 0) {
            ans[i][N-1] = cur; 
        } else {
            ans[i][N-2] = cur;
        }
        cur++;
        int s = 4;
        if (i < N-4) {
            s = 0;
        }
        FOR(j, s, N-2) {
            ans[i][j] = cur; cur++;
        }
        if (i % 2 == 0) {
            ans[i][N-2] = cur;
        } else {
            ans[i][N-1] = cur;
        }
        cur++;
    }*/

/*    int cur = 1;
    int ans[N][N];
    if (N % 2 == 0) {
        F0R(i, N-2) {
            ans[i][0] = cur; cur++;
        }
        F0Rd(i, N-2) {
            ans[i][1] = cur; cur++;
        }
        F0R(i, N) {
            FOR(j, 2, N) {
                if (i % 2 == 0) {
                    ans[i][j] = cur;
                } else {
                    ans[i][N+1-j] = cur;
                }

                cur++;
            }
        }
        ans[N-1][1] = cur; cur++;
        ans[N-2][0] = cur; cur++;
        ans[N-2][1] = cur; cur++;
        ans[N-1][0] = cur; cur++;
    } else {
        F0R(i, N-2) {
            F0R(j, N) {
                if (i % 2 == 0) {
                    ans[i][j] = cur;
                } else {
                    ans[i][N-1-j] = cur;
                }
                cur++;
            }
        }
        FORd(i, 2, N) {
            F0R(j, 2) {
                if (i % 2) {
                    ans[N-1-j][i] = cur;
                } else {
                    ans[N-2+j][i] = cur;
                }
                cur++;
            }
        }
        int mo = 0;
        ans[N-1-mo][1] = cur; cur++;
        ans[N-2+mo][0] = cur; cur++;
        ans[N-1-mo][0] = cur; cur++;
        ans[N-2+mo][1] = cur; cur++;
    }

    F0R(i, N) {
        F0R(j, N) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343