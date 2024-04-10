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
	
    vpl nodes;
    ll x0, y0, aX, aY, bX, bY, xS, yS, T; cin >> x0 >> y0 >> aX >> aY >> bX >> bY >> xS >> yS >> T;

    ll cX = x0, cY = y0;
    while (cX + cY < 6e16) {
        nodes.pb({cX, cY});
        cX = aX * cX + bX;
        cY = aY * cY + bY;
    }


    int N = sz(nodes);
    int ans = 0;
    F0R(i, N) {
        FOR(j, i, N) {
            FOR(k, i, N) {
                ll dist = abs(nodes[j].f - xS) + abs(nodes[j].s - yS);
                dist += abs(nodes[i].f - nodes[j].f) + abs(nodes[i].s - nodes[j].s);
                dist += abs(nodes[k].f - nodes[i].f) + abs(nodes[k].s - nodes[i].s);
                if (dist <= T) ans = max(ans, max(j, k)-i+1);
            }
        }
    }

    F0R(i, N) {
        F0R(j, i+1) {
            F0R(k, i+1) {
                ll dist = abs(nodes[j].f - xS) + abs(nodes[j].s - yS);
                dist += abs(nodes[i].f - nodes[j].f) + abs(nodes[i].s - nodes[j].s);
                dist += abs(nodes[k].f - nodes[i].f) + abs(nodes[k].s - nodes[i].s);
                if (dist <= T) ans = max(ans, i - min(j, k)+1);
            }
        }
    }

    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343