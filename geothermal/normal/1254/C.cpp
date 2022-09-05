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
	
    int N; cin >> N;
    int lo = 1;
    FOR(i, 2, N) {
        cout << "2 1 " << lo+1 << " " << i+1 << endl;
        int res; cin >> res;
        if (res == -1) lo = i;
    }

    vpl areas;
    FOR(i, 1, N) {
        if (i == lo) continue;
        cout << "1 1 " << lo+1 << " " << i+1 << endl;
        ll res; cin >> res;
        areas.pb({res, i});
    }

    int ans[N];
    ans[0] = 0;
    ans[1] = lo;
    int nLo = 2, nHi = N-1;
    sort(all(areas));
    int hi = areas[N-3].s;
    F0R(i, N-3) {
        cout << "2 1 " << areas[i].s + 1 << " " << hi+1 << endl;
        int res; cin >> res;
        if (res == 1) {
            ans[nLo] = areas[i].s;
            nLo++;

        } else {
            ans[nHi] = areas[i].s;
            nHi--;
        }
    }

    ans[nLo] = hi;

    cout << "0 ";
    F0R(i, N) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343