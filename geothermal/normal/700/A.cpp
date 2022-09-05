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

bool check(int N, ld L, ld V1, ld V2, ld tt) {
    if (L / V1 <= tt) return true;
    ld bt = L - V1 * tt; bt /= (V2 - V1);
    ld timeTaken = bt + (bt * (V2 - V1)) / (V2 + V1);
    timeTaken *= N; timeTaken -= (bt * (V2 - V1)) / (V2 + V1);
    if (timeTaken <= tt + 1e-10) return true;
    return false;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    cout << setprecision(20);
    int N; ld L, V1, V2; int K; cin >>N >> L >> V1 >> V2 >> K;
    N = (N+K-1)/K;
    ld lo = 0, hi = 1e12;
    F0R(i, 200) {
        ld mid = (lo+hi)/2;
        if (check(N, L, V1, V2, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << lo << nl;
/*    ld cp = 0, ct = 0;
    F0R(i, (N+K-1)/K) {
        ld tim = (L - cp) / V2;
        ld np = cp + tim * V1;
        if (i != (N+K-1)/K - 1) {
            tim += (L - np) / (V1 + V2);
            np = cp + tim * V1;
            if (np >= L) {
                cout << ct + (L - cp) / V1 << nl; return 0;
            }
        }
        ct += tim; cp = np;
    }
    cout << ct << nl;*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343