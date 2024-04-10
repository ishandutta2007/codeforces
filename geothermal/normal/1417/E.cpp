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

ll ans[30][2];

void solve(vi& A, int bit) {
    vi nxt[2];
    ll cnt[2]; cnt[0] = 0, cnt[1] = 0;
    F0R(i, sz(A)) {
        if (A[i] & (1 << bit)) {
            cnt[1]++;
            ans[bit][0] += cnt[0];
            nxt[1].pb(A[i] - (1 << bit));
        } else {
            cnt[0]++;
            ans[bit][1] += cnt[1]; //1-0s, i.e. default
            nxt[0].pb(A[i]);
        }
    }
    if (bit == 0) return;
    if (sz(nxt[0])) solve(nxt[0], bit-1);
    if (sz(nxt[1])) solve(nxt[1], bit-1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    vi A(N); F0R(i, N) cin >> A[i];
    F0R(i, 30) F0R(j, 2) ans[i][j] = 0;
    solve(A, 29);
    ll a1 = 0, a2 = 0;
    F0R(i, 30) {
        a1 += min(ans[i][0], ans[i][1]);
        if (ans[i][0] < ans[i][1]) {
            a2 += (1 << i);
        }
    }
    cout << a1 << " " << a2 << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343