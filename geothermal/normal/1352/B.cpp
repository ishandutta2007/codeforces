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
	
    int T; cin >> T;
    while(T--) {
        ll N; int K; cin >> N >> K;
        vi a1, a2;
        F0R(i, K-1) {
            a1.pb(1);
            a2.pb(2);
        }
        a1.pb(N-K+1); a2.pb(N-2*K+2);
        vi ans; 
        if (a1[sz(a1)-1] > 0 && a1[sz(a1)-1] % 2) {
            ans = a1;
        } else if (a2[sz(a2)-1] > 0 && a2[sz(a2)-1] % 2 == 0) {
            ans = a2;
        } else {
            cout << "NO" << nl; continue;
        }
        cout << "YES" << nl;
        F0R(i, sz(ans)) {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343