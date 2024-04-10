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
        int N, K; cin >> N >> K;
        string S; cin >> S;
        int cnt[3]; F0R(i, 3) cnt[i] = 0;
        F0R(i, K) {
            int val = 2;
            for (int j = i; j < sz(S); j += K) {
                if (S[j] == '?') continue;
                if (S[j] == '0' && val != 1) {
                    val = 0;
                } else if (S[j] == '0') {
                    cout << "NO" << nl; goto done;
                }
                if (S[j] == '1' && val != 0) {
                    val = 1;
                } else if (S[j] == '1') {
                    cout << "NO" << nl; goto done;
                }
            }
            cnt[val]++;
        }

        cout << ((cnt[0]<=K/2&&cnt[0]+cnt[2]>=K/2)?"YES":"NO") << nl;


        done:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343