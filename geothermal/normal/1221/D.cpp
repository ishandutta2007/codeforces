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
	
	
	int Q; cin >> Q;
	
	F0R(testCase, Q) {
		int N; cin >> N;
		ll data[N];
		ll cost[N];
		F0R(i, N) cin >> data[i] >> cost[i];
		
		/*vector<vl> data;
		
		ll lo = preData[0];
		ll totalCost = cost[0];
		
		FOR(i, 1, N) {
			if (preData[i] - preData[i-1] != 1) {
				vl cur;
				cur.pb(lo); cur.pb(preData[i-1]);
				cur.pb(totalCost);
				data.pb(cur);
				lo = preData[i];
				totalCost = 0;
			}
			totalCost += cost[i];
		}
		
		vl cur;
		cur.pb(lo); cur.pb(preData[i-1]);
		cur.pb(totalCost);
		data.pb(cur);
		
		N = sz(data);*/
		
		ll dp[N][5];
		F0R(i, N) F0R(j, 5) dp[i][j] = 2000000000000000000;
		F0R(i, 5) dp[0][i] = cost[0] * i;
		
		FOR(i, 1, N) {
			F0R(j, 5) {
				F0R(k, 5) {
				    if (data[i-1] + j != data[i] + k) {
						dp[i][k] = min(dp[i][k], dp[i-1][j] + cost[i] * k);
					}
				}
			}
		}
		
		ll ans = 2000000000000000000; F0R(i, 5) ans = min(ans, dp[N-1][i]);
		cout << ans << endl;
		
	}
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343