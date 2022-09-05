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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    vl inData(N); F0R(i, N) cin >> inData[i];

    vl data(N); F0R(i, N) data[i] = __builtin_popcountll(inData[i]);

    ll op = 0, ep = 1;
    int cur = 0;
    F0R(i, N) {
        if (data[i] % 2) {
            cur = 1 - cur;
        }
        if (cur) {
            op++;
        } else {
            ep++;
        }
    }

    ll ans = (op * (op - 1))/2 + (ep * (ep-1))/2;
    F0R(r, N) {
        vi eb, ob;
        int curSum = 0;
        eb.pb(0);
        F0Rd(i, r) {
            curSum += data[i];
            if (curSum > data[r]) break;
            if (curSum % 2) {
                ob.pb(curSum);
            } else eb.pb(curSum);
        }

        auto oP = ob.rbegin(), eP = eb.rbegin();
        FOR(i, r, N) {
            curSum += data[i];
            if (i == r) curSum = 0;
            if (curSum > data[r]) break;
            if (curSum % 2 != data[r] % 2) {
                while (oP != ob.rend() && *oP + curSum >= data[r]) oP++;
                ans -= (ob.rend() - oP);
            } else {
                while (eP != eb.rend() && *eP + curSum >= data[r]) eP++;
                ans -= (eb.rend() - eP);
            }
        }
    }

    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343