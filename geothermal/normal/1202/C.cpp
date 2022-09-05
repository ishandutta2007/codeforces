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
#define shandom_ruffle random_shuffle

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    F0R(i, T) {
        string S; cin >> S;
        ll X = 0, Y = 0;
        ll hX = 0, hY = 0, lX = 0, lY = 0;
        F0R(i, sz(S)) {
            if (S[i] == 'W') {
                X++;
            } else if (S[i] == 'A') {
                Y--;
            } else if (S[i] == 'S') {
                X--;
            } else Y++;
            hX = max(hX, X);
            hY = max(hY, Y);
            lX = min(lX, X);
            lY = min(lY, Y);
        }

        ll ans = (hX-lX+1)*(hY-lY+1);

        if (hX != 0) {
            X = 0, Y = 0;
            bool used = false;
            ll chX = 0, chY = 0, clX = 0, clY = 0;
            F0R(i, sz(S)) {
                if (S[i] == 'W') {
                    X++;
                } else if (S[i] == 'A') {
                    Y--;
                } else if (S[i] == 'S') {
                    X--;
                } else Y++;
                if (!used && X == hX) {
                    X-= 2; used = true;
                    chX = max(chX, X);
                    chY = max(chY, Y);
                    clX = min(clX, X);
                    clY = min(clY, Y);
                    X++;
                }
                chX = max(chX, X);
                chY = max(chY, Y);
                clX = min(clX, X);
                clY = min(clY, Y);
            }
            ans = min(ans, (chX-clX+1)*(chY-clY+1));
        }

        if (hY != 0) {
            X = 0, Y = 0;
            bool used = false;
            ll chX = 0, chY = 0, clX = 0, clY = 0;
            F0R(i, sz(S)) {
                if (S[i] == 'W') {
                    X++;
                } else if (S[i] == 'A') {
                    Y--;
                } else if (S[i] == 'S') {
                    X--;
                } else Y++;
                if (!used && Y == hY) {
                    Y-=2; used = true;
                    chX = max(chX, X);
                    chY = max(chY, Y);
                    clX = min(clX, X);
                    clY = min(clY, Y);
                    Y++;
                }
                chX = max(chX, X);
                chY = max(chY, Y);
                clX = min(clX, X);
                clY = min(clY, Y);
            }
            ans = min(ans, (chX-clX+1)*(chY-clY+1));
        }

        if (lX != 0) {
            X = 0, Y = 0;
            bool used = false;
            ll chX = 0, chY = 0, clX = 0, clY = 0;
            F0R(i, sz(S)) {
                if (S[i] == 'W') {
                    X++;
                } else if (S[i] == 'A') {
                    Y--;
                } else if (S[i] == 'S') {
                    X--;
                } else Y++;
                if (!used && X == lX) {
                    X+=2; used = true;
                    chX = max(chX, X);
                    chY = max(chY, Y);
                    clX = min(clX, X);
                    clY = min(clY, Y);
                    X--;
                }
                chX = max(chX, X);
                chY = max(chY, Y);
                clX = min(clX, X);
                clY = min(clY, Y);
            }
            ans = min(ans, (chX-clX+1)*(chY-clY+1));
        }

        if (lY != 0) {
            X = 0, Y = 0;
            bool used = false;
            ll chX = 0, chY = 0, clX = 0, clY = 0;
            F0R(i, sz(S)) {
                if (S[i] == 'W') {
                    X++;
                } else if (S[i] == 'A') {
                    Y--;
                } else if (S[i] == 'S') {
                    X--;
                } else Y++;
                if (!used && Y == lY) {
                    Y+=2; used = true;
                    chX = max(chX, X);
                    chY = max(chY, Y);
                    clX = min(clX, X);
                    clY = min(clY, Y);
                    Y--;
                }
                chX = max(chX, X);
                chY = max(chY, Y);
                clX = min(clX, X);
                clY = min(clY, Y);
            }
            ans = min(ans, (chX-clX+1)*(chY-clY+1));
            //cout << chX << " " << clX << " " << chY << " " << clY << endl;
        }

        cout << ans << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE