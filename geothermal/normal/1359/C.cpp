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
struct cmp {
    bool operator() (const pl& lhs, const pl& rhs) const {
        return lhs.f * rhs.s < lhs.s * rhs.f;
    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	map<pl, ll, cmp> vals;
    vals.ins({{1, 1}, 1});
    vals.ins({{1, 2}, 2});
    FOR(i, 2, 2000000) {
        vals.ins({{i, 2*i-1}, i*2-1});
    }
    int T; cin >> T;
    while(T--) {
        ll H, C, T; cin >> H >> C >> T;
        pl R = {T-C, H-C};
        auto B = (vals.ub(R));
        if (B == vals.begin()) {
            cout << B->s << nl; continue;
        } 
        auto A = B; A--;
        if ((B != vals.end() && (abs(A->f.f * R.s - A->f.s * R.f)*B->f.s >= abs(B->f.f * R.s - B->f.s * R.f)*A->f.s))) {
            cout << B->s << nl;
        } else {
            cout << A->s << nl;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343