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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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
const int MX = 100001; 

void solve() {
    int N; cin >> N;
    int dp[1 << N];
    string S; cin >> S; S += ' '; reverse(all(S));
    FORd(i, 1 << (N-1), 1 << N) {
        if (S[i] == '?') {
            dp[i] = 2;
        } else dp[i] = 1;
    }
    FORd(i, 1, 1 << (N-1)) {
        if (S[i] == '0') {
            dp[i] = dp[i*2+1];
        } else if (S[i] == '1') {
            dp[i] = dp[i*2];
        } else {
            dp[i] = dp[i*2]+dp[i*2+1];
        }
    }
    /*FORd(i,1, 1 << N) {
        cout << dp[i] << " ";
    }
    cout << nl;*/

    int Q; cin >> Q;
    F0R(it, Q) {
        int i; char C; cin >> i >> C;
        i = (1 << N) - i;
        S[i] = C;
        while (i > 0) {
            if (i >= (1 << (N-1))) {
                if (S[i] == '?') {
                    dp[i] = 2;
                } else dp[i] = 1;
            } else {
                if (S[i] == '0') {
                    dp[i] = dp[i*2+1];
                } else if (S[i] == '1') {
                    dp[i] = dp[i*2];
                } else {
                    dp[i] = dp[i*2]+dp[i*2+1];
                }
            }
            i /= 2;
        }
        cout << dp[1] << nl;
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}