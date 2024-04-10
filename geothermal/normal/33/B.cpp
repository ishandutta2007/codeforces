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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string S, T; cin >> S >> T;
    int N = sz(S);
    if (sz(T) != N) {
        cout << -1 << nl; return 0;
    }
    int M; cin >> M;
    ll cost[26][26]; F0R(i, 26) F0R(j, 26) cost[i][j] = 1e10;

    F0R(i, M) {
        char A, B; cin >> A >> B;
        ll C; cin >> C;
        cost[A-'a'][B-'a'] = min(cost[A-'a'][B-'a'], C);
    }
    F0R(i, 26) cost[i][i] = 0;

    F0R(iter, 56) {
        F0R(i, 26) {
            F0R(j, 26) {
                F0R(k, 26) {
                    cost[i][k] = min(cost[i][k], cost[i][j] + cost[j][k]);
                }
            }
        }
    }

    ll ans = 0;
    string res;
    F0R(i, N) {
        char best = 'a';
        ll val = 1e10;
        F0R(j, 26) {
            if (cost[S[i]-'a'][j] + cost[T[i]-'a'][j] < val) {
                val = cost[S[i]-'a'][j] + cost[T[i]-'a'][j];
                best = 'a'+j;
            }
        }
        res += best;
        ans += val;
    }
    if (ans > 1e9) {
        cout << -1 << nl; return 0;
    }
    cout << ans << nl; cout << res << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343