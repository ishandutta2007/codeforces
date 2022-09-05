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
	
    ll K; cin >> K;
    int A, B; cin >> A >> B;
    int X[3][3], Y[3][3]; F0R(i, 3) F0R(j, 3) cin >> X[i][j];
    F0R(i, 3) F0R(j, 3) cin >> Y[i][j];
    A--; B--;
    F0R(i, 3) F0R(j, 3) { X[i][j]--, Y[i][j]--; }

    int ans = 0, ans2 = 0;
    const ll val = 362880;
    F0R(i, val+K%val) {
        if (i < K && (A-B+3)%3 == 1) {
            ans++;
        } else if (i < K && (B-A+3)%3 == 1) {
            ans2++;
        }
        int oA = A;
        A = X[A][B]; B = Y[oA][B];
    }
    int num = 0, num2 = 0;
    FOR(i, val+K%val, 2*val+K%val) {
        if (i < K && (A-B+3)%3 == 1) {
            num++;
        }  else if (i < K && (B-A+3)%3 == 1) {
            num2++;
        }
        int oA = A;
        A = X[A][B]; B = Y[oA][B];
    }

    cout << ans + (K-val-K%val) / val * num << " " << ans2 + (K-val-K%val) / val * num2  << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343