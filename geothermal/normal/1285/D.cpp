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

ll best(vi data, int cur) {
    if (cur < 0) return 0;
    //is it possible to stay under 1 << cur?
    bool found[2]; F0R(i, 2) found[i] = false;
    vi oData = data;
    F0R(i, sz(data)) {
        if (data[i] & (1 << cur)) {
            found[1] = true;
        } else {
            found[0] = true;
        }
    }
    vi data2, data1;
    F0R(i, sz(data)) {
        if (data[i] >= 1 << cur) {

            data[i] -= 1 << cur;
            data2.pb(data[i]);
        } else data1.pb(data[i]);
    }
    ll res;
    if (found[1] && found[0]) {
        res = min(best(data1, cur-1), best(data2, cur-1));
//        cout << " res " << res << endl;
        res += 1 << cur;
    } else {
        res = best(data, cur-1);
    }
/*    if (cur <= 2) {
        cout << cur << endl;
        F0R(i, sz(data)) cout << oData[i] << " " ;
        cout << endl;
        cout << res << " " << found[0] << " " << found[1] << endl;
    }*/
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N; vi data;
    F0R(i, N) {
        ll cur; cin >> cur;
        data.pb(cur);
    }


    cout << best(data, 29) << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343