#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll A, B; cin >> A >> B;
    if (A > B) swap(A, B);
    if (A == B) {
        cout << 0 << endl;
    } else {
        
        ll val = B-A;
        ll best = 4000000000000000000;
        ll ans = -1;
        FOR(i, 1, 100000) {
            if (val % i != 0) continue;
            ll val1 = i;
            ll res1 = val1 - (A%val1);
            res1 %= val1;
            ll lcm1 = (A+res1)*(B+res1)/__gcd(A+res1, B+res1);
            if (lcm1 < best || (lcm1 == best && res1 < ans)) {
                best = lcm1; ans = res1;
            }
            ll val2 = val / i;
            ll res2 = val2 - (A%val2);
            res2 %= val2;
            ll lcm2 = (A+res2)*(B+res2)/__gcd(A+res2, B+res2);
            if (lcm2 < best || (lcm2 == best && res2 < ans)) {
                best = lcm2; ans = res2;
            }
        }
        cout << ans << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343