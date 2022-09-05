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
ll cnt(ll A, ll B, ll C) {//count <=A + <= B <= > C
    if (A > B) swap(A, B);
    //case 1:
    C++;
    C = max(C, 0ll);
    if (B >= C-1) {
        ll z = B + 1 - C;
        ll p = min(A, C);
        ll m = min(B+1, B + 1 - C + A);
        return ((z+m)*(p+1))/2 + m*(A-p);
    } else if (A + B >= C) {
        ll z = 1;
        ll m = min(B+1, B+1-C+A);
        ll lo = C-B;
        ll hi = A;
        return ((z+m)*(hi-lo+1))/2;
    } else return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll A, B, C, D; cin >> A >> B >> C >> D;
    ll ans = 0;
    F0R(i, D-C+1) {
        ll cap = C + i - A - B;
        ans += cnt(B-A, C-B, cap);
//        cout << ans << " " << cap << nl;
    }
    cout << ans << nl; return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343