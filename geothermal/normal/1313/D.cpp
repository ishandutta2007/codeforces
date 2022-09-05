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

int dp[200010][256];

int ad(int x, int p) {
    int lo = x % (1 << p);
    int hi = x / (1 << p);
    hi *= 2;
    return hi+lo;
}
int re(int x, int p) {
    int lo = x % (1 << p);
    int hi = x / (1 << p);
    hi >>= 1; hi <<= p;
    return hi+lo;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    int K; cin >> K; 

    vpi E;
    F0R(i, N) {
        int A, B; cin >> A >> B;
        E.pb({A, i});
        E.pb({B+1, -i-1});
    }

    set<int> blank;
    sort(all(E));
    F0R(i, 2*N+1) F0R(j, (1 << K)) dp[i][j] = -1000000000;
    dp[0][0] = 0;
    list<int> curEntries;

    F0R(i, 2*N) {
        int p = 0;
        if (E[i].s < 0) {
            for (auto it = curEntries.begin(); it != curEntries.end(); it++) {
                if (*it == -E[i].s - 1) {
                    curEntries.erase(it);
                    break;
                }
                p++;
            }
        } else {
            curEntries.push_front(E[i].s);
        }
/*        cout << "CUR " << i << " " << E[i].f << " " << E[i].s << nl;
        trav(a, curEntries) cout << a << " ";
        cout << nl;
        F0R(j, 8) cout << dp[i][j] << " ";
        cout << nl;*/
        F0R(j, (1 << K)) {
            int cur = dp[i][j];
            if (i > 0) cur += (__builtin_popcount(j) % 2) * (E[i].f - E[i-1].f);
            if (E[i].s < 0) {
                ckmax(dp[i+1][re(j, p)], cur);
            } else {
                ckmax(dp[i+1][2*j], cur);
                ckmax(dp[i+1][2*j+1], cur);
            }
        }
    }

    int ans = 0;
    F0R(i, (1 << K)) {
        ckmax(ans, dp[2*N][i]); 
    }
    cout << ans << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343