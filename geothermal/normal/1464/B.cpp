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
	
    string S;
    ll X, Y; cin >> S >> X >> Y;
    int N = sz(S);
    if (X > Y) { //X is smaller, i.e. do 0s then 1s
        swap(X, Y); 
        F0R(i, N) {
            if (S[i] != '?') S[i] = '0' + '1' - S[i];
        }
    }
    int zb[N+1];
    zb[0] = 0;
    int nz = 0;
    vi pos;
    F0R(i, N) {
        zb[i+1] = zb[i]; if (S[i] == '0') zb[i+1]++;
        if (S[i] == '0') nz++;
        if (S[i] == '?') pos.pb(i);
    }
    //initially, put all ones

    ll ans = 0;
    F0R(i, N) {
        if (S[i] == '0') {
            ans += Y * (i - zb[i]);
            ans += X * (N - 1 - i - (nz - zb[i+1]));
        } else {
            ans += X * zb[i];
            ans += Y * (nz - zb[i]);
        }
    }
    ans /= 2;
    ll res = ans;
    F0R(i, sz(pos)) {
        ans -= X * (zb[pos[i]] + i);
        ans -= Y * (nz - zb[pos[i]]);
        
        ans += Y * (pos[i] - zb[pos[i]] - i);
        ans += X * (N - 1 - pos[i] - (nz - zb[pos[i]]));
        ckmin(res, ans);
    }
    cout << res << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343