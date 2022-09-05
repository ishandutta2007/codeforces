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

int N, M;
string S;
string T;

bool ok(int K) {
    int dp[N+1][2];
    F0R(i, N+1) F0R(j, 2) dp[i][j] = -1;
    dp[0][0] = 0;
    F0R(i, N) {
        if (i+K <= N && dp[i][0] > 0) {
            ckmax(dp[i+K-1][1], min(dp[i][0], M-1));
        }
        F0R(j, 2) {
            int mat = 0;
            if (dp[i][j] > -1 && dp[i][j] < M && S[i] == T[dp[i][j]]) {
                mat = 1;
            }
            ckmax(dp[i+1][j], dp[i][j]+mat);
        }
    }
    return dp[N][1] == M;
}

void solve() {

    cin >> N >> M >> S >> T;
    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (ok(mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << lo << nl;
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