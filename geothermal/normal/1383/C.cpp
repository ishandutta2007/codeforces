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
const int MX = 20; //check the limits, dummy

int in[MX], out[MX];
bool vis[(1 << MX)];
int dp[(1 << MX)];

int solve(int m) {
    if (vis[m]) return dp[m];
    vis[m] = true;
    if (m == 0) {
        return dp[0] = 0;
    }

    int ans = 40;
    F0R(i, MX) {
        if (m & (1 << i)) {
            int cur = 0; if ((in[i] & m) && (out[i] & m)) cur++;
            ckmin(ans, cur + solve(m - (1 << i)));
        }
    }

    return dp[m] = ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        F0R(i, 1 << MX) {
            vis[i] = false; 
        }
        int N; cin >> N;
        string S, T; cin >> S >> T;
        F0R(i, MX) {
            in[i] = 0; out[i] = 0;
        }
        F0R(i, N) {
            if (S[i] != T[i]) {
                in[S[i] - 'a'] |= 1 << (T[i] - 'a');
                out[T[i] - 'a'] |= 1 << (S[i] - 'a');
            }
        }

        bool F[MX];
        F0R(i, MX) F[i] = false;
        int cc = 0;
        F0R(r, 20) {
            if (F[r]) continue;
            F[r] = true; cc++;
            queue<int> q; q.push(r);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                F0R(i, 20) {
                    if ((in[cur] & (1 << i)) || (in[i] & (1 << cur))) {
                        if (F[i]) continue;
                        F[i] = true;
                        q.push(i);
                    }
                }
            }
        }

        cout << solve((1 << 20) - 1) + 20 - cc << nl;

/*        F0R(i, 8) {
            cout << i << " " << dp[i] << nl;
        }*/
    }

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343