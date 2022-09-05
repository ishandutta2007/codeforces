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
	
    int N, M; cin >> N >> M;
    ll X, K, Y; cin >> X >> K >> Y;
    int A[N+1], B[M+1]; F0R(i, N) cin >> A[i];
    F0R(i, M) cin >> B[i];
    
    int bp = 0;
    int lv = -1;
    int mx = 0;
    int cnt = 0;
    ll ans = 0;
    A[N] = 0; B[M] = 0;
    F0R(i, N+1) {
        if (bp < M+1 && A[i] == B[bp]) {
            ll res = 1e18;
            if (mx < lv || mx < A[i]) {
                res = Y * cnt;
            }
            for (int j = K; j <= cnt; j += K) {
                ckmin(res, X * (j / K) + Y * (cnt - j));
            }

            if (res > 1e17) {
                cout << -1 << nl; return 0;
            }
            ans += res;

            bp++;
            lv = A[i];
            mx = 0;
            cnt = 0;
        } else {
            ckmax(mx, A[i]);
            cnt++;
        }
    }
    if (bp != M+1) {
        cout << -1 << nl; return 0;
    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343