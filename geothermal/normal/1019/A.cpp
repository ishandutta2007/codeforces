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
	
    int N, M; cin >> N >> M;
    vector<vl> voters(M);
    F0R(i, N) {
        int X; cin >> X; X--;
        ll cost; cin >> cost;

        voters[X].pb(cost);
    }

    F0R(i, M) sort(all(voters[i])), reverse(all(voters[i]));
    ll ans = 10000000000000;
    FOR(v, 1, N+1) {
        vl rems;
        ll curAns = 0;
        int cnt = 0;
        FOR(i, 1, M) {
            F0R(j, min(v-1, sz(voters[i]))) {
                rems.pb(voters[i][j]);
            }
            FOR(j, v-1, sz(voters[i])) {
                curAns += voters[i][j]; cnt++;
            }
        }
//        if (v == 2) cout << curAns << " " << cnt << endl;
        sort(all(rems));
        F0R(i, v - cnt - sz(voters[0])) curAns += rems[i];
//        if (curAns == 0) cout << v << endl;
        if (curAns < ans) ans = curAns;
    }
    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343