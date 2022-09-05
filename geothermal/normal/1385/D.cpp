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
        string S; cin >> S;
        ll cost[N][26]; 
        F0R(i, N) {
            F0R(j, 26) {
                cost[i][j] = 1;
            }
            cost[i][S[i] - 'a'] = 0;
        }

        int cnt[N+1][26]; F0R(i, 26) cnt[0][i] = 0;
        F0R(i, N) {
            F0R(j, 26) {
                cnt[i+1][j] = cnt[i][j];

            }
            cnt[i+1][S[i] - 'a']++;
        }

        int cur = 2;
        while (cur <= N) {
            for (int i = 0; i < N; i += cur) {
                ll nxt[26];
                nxt[25] = 1e9;
                F0R(j, 25) {
                    nxt[j] = min((cur/2 - cnt[i+cur/2][j] + cnt[i][j]) + cost[i+cur/2][j+1], cost[i][j+1] + (cur / 2 - cnt[i+cur][j] + cnt[i+cur/2][j]));
                    nxt[j] = min(nxt[j], (ll) 1e9);
                }
                F0R(j, 26) {
                    cost[i][j] = nxt[j];
                }
            }
            cur *= 2;
        }
        cout << cost[0][0] << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343