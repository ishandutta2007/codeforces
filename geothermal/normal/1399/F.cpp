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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int L[N], R[N]; F0R(i, N) cin >> L[i] >> R[i];
        set<int> usedSet; F0R(i, N) {
            usedSet.ins(L[i]); usedSet.ins(R[i]);
        }
        map<int, int> comp;
        trav(a, usedSet) {
            comp[a] = sz(comp);
        }
        int M = sz(comp);
        int dp[M][M];
        bool ex[M][M]; F0R(i, M) F0R(j, M) ex[i][j] = false;
        vi rl[M];
        F0R(i, N) {
            L[i] = comp[L[i]];
            R[i] = comp[R[i]];
            rl[L[i]].pb(R[i]);
            ex[L[i]][R[i]] = true;
        }
        F0R(i, M) sort(all(rl[i]));
        F0R(d, M) {
            F0R(i, M) {
                int j = i+d;
                if (j >= M) continue;
                dp[i][j] = 0;
                trav(a, rl[i]) {
                    if (a >= j) break;
                    int in = dp[i][a];
                    if (ex[i][a]) in--;
                    int out = 0;
                    if (j-a >= 1) {
                        out = dp[a+1][j];
                    }
                    ckmax(dp[i][j], in+out+1);
                }
                if (i < j) {
                    ckmax(dp[i][j], dp[i+1][j]);
                }
                if (ex[i][j]) dp[i][j]++;
            }
        }
        cout << dp[0][M-1] << nl;


    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343