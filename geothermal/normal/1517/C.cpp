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
const int MX = 100001; //check the limits, dummy

void solve() {

    int N; cin >> N;
    int A[N];
    F0R(i, N) cin >> A[i];
    int ans[N][N]; F0R(i, N) F0R(j, N) ans[i][j] = 0;
    int dx[3] = {0, 1, 0}, dy[3] = {1, 0, -1};
    F0Rd(it, N) {
        int x = it, y = it;
        ans[x][y] = A[it];
        F0R(iter, A[it]-1) {
            F0R(k, 3) {
                int i = x + dx[k], j = y + dy[k];
                if (i >= j && i < N && j < N && i >= 0 && j >= 0 && ans[i][j] == 0) {
                    x = i; y = j;
                    ans[x][y] = A[it]; goto done;
                }
            }
            done:
            ;
        }
    }
    F0R(i, N) {
        F0R(j, i+1) {
            cout << ans[i][j] << " ";
        }
        cout << nl;
    }

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343