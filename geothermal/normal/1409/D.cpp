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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        string S; cin >> S;
        int K; cin >> K;
        while (sz(S) < 19) S = "0" + S;
        string res = ""; F0R(i, 19) res += '9';
        F0R(i, 20) {
            string X = S;
            if (i < 19 && S[i] == '9') continue;
            FOR(j, i+1, 19) X[j] = '0';
            if (i < 19) X[i]++;
            int sum = 0; F0R(j, 19) sum += X[j] - '0';
//            cout << sz(X) << nl;
            if (sum <= K) ckmin(res, X);
//            cout << sz(res) << nl;
        }
        ll ans = 0;
        /*cout << S << nl;
        cout << res << nl;
        cout << sz(S) << " " << sz(res) << nl;*/
        F0R(i, 19) {
            ans *= 10;
            ans += res[i] - S[i];
        }
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343