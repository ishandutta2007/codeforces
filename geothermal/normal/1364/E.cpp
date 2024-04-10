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
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

vi M, corr; int cq = 0;
int query(int X, int Y) {
    cq++;
    cout << "? " << M[X]+1 << " " << M[Y]+1 << endl;
    int res; cin >> res;
/*    res = corr[M[X]] | corr[M[Y]];*/
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N; cin >> N;
    F0R(i, N) M.pb(i);
    random_shuffle(all(M));

    vi dp[2048];
    int ans[N]; F0R(i, N) ans[i] = 2047;
    int cur = N-1;
    uniform_int_distribution<int> dist(0, N-1);
    while (sz(dp[2047]) == 0) {
        int A = dist(rng);
        int B = dist(rng);
        while (A == B) B = dist(rng);
        int X = query(A, B);
        ans[A] &= X; ans[B] &= X;
        if (X == -1) return 0;
        F0R(i, 2048) {
            if (i != 0 && sz(dp[i]) == 0) continue;
            int val = i | (2047 - ans[A]);
            if (val == i) continue;
            if (sz(dp[val]) == 0 || sz(dp[val]) > sz(dp[i]) + 1) {
                dp[val] = dp[i]; dp[val].pb(A);
            }
        }
        F0R(i, 2048) {
            if (i != 0 && sz(dp[i]) == 0) continue;
            int val = i | (2047 - ans[B]);
            if (val == i) continue;
            if (sz(dp[val]) == 0 || sz(dp[val]) > sz(dp[i]) + 1) {
                dp[val] = dp[i]; dp[val].pb(B);
            }
        }
        cur -= 2;
    }

/*    cout << "DONE" << endl;
    F0R(i, sz(dp[2047])) {
        cout << M[dp[2047][i]] << " " << ans[dp[2047][i]] << endl;
    }*/

    F0R(v, N) {
        int X = 2047;
        F0R(j, sz(dp[2047])) {
            int K;
            if (v == dp[2047][j]) {
                K = ans[v];
            } else K = (query(v, dp[2047][j]));
            if (K == -1) return 0;
            X = X & K;
        }
        dp[2047-X].clear();
        dp[2047-X].pb(v);
        ans[v] = X;
        if (sz(dp[2047]) > 2) {
            F0R(i, 2048) {
                if (i != 0 && sz(dp[i]) == 0) continue;
                int val = i | (2047 - X);
                if (val == i) continue;
                if (sz(dp[val]) == 0 || sz(dp[val]) > sz(dp[i]) + 1) {
                    dp[val] = dp[i]; dp[val].pb(v);
                }
            }
        }
/*        cout << sz(dp[2047]) << " ";
        F0R(i, sz(dp[2047])) cout << ans[dp[2047][i]] << " ";
        cout << endl;*/
    }

    int fin[N];
    F0R(i, N) {
        fin[M[i]] = ans[i];
    }
    cout << "! ";
    F0R(i, N) {
        cout << fin[i] << " ";
    }
    cout << endl;

    /*F0R(i, N) {
        if (corr[i] != fin[i]) {
            cout << "BAD" << nl; 
            F0R(j, N) {
                cout << corr[j] << " ";
            }
            cout << nl;
            F0R(j, N) {
                cout << fin[j] << " ";
            }
            cout << nl; return 0;
        }
    }
    cout << "GOOD" << nl;
    cout << cq << nl;*/


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343