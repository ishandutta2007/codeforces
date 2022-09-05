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
	
    int A, B, C; cin >> A >> B >> C;
    vl X(A), Y(B), Z(C);
    F0R(i, A) cin >> X[i];
    F0R(i, B) cin >> Y[i];
    F0R(i, C) cin >> Z[i];
    sort(all(X)); sort(all(Y)); sort(all(Z));
    ll s1 = 0, s2 = 0, s3 = 0;
    F0R(i, A) s1 += X[i];
    F0R(i, B) s2 += Y[i];
    F0R(i, C) s3 += Z[i];
    cout << s1+s2+s3-2*min(min(s1, min(s2, s3)), min(X[0]+min(Y[0], Z[0]), Y[0]+Z[0])) << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343