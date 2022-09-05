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
        int N, M; cin >> N >> M;
        ll rem = (1ll << M) - N;
        ll goal = (rem-1)/2;
        string A[N];
        F0R(i, N) {
            cin >> A[i];
        }
        string ans;
        F0R(bit, M) {
            ll cnt = (1ll << (M-bit-1));
            F0R(i, bit) {
                if (ans[i] == '1') cnt += (1ll << (M-i-1));
            }
            ans.pb('1');
            F0R(i, N) {
                F0R(j, sz(ans)) {
                    if (A[i][j] != ans[j]) {
                        if (ans[j] == '1') {
                            cnt--; 
                        }
                        goto done;
                    }
                }
                
                done:
                ;
            }
            if (cnt > goal) {
                ans.pop_back();
                ans.pb('0');
            }
        }
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343