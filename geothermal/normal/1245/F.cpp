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
	
	ll pows[35];
	pows[0] = 1;
	FOR(i, 1, 35) pows[i] = 3*pows[i-1];
	ll T; cin >> T;
	F0R(testCase, T) {
		ll cnts[16]; F0R(i, 16) cnts[i] = 0; // first lo, first hi, second lo, second hi
		cnts[15] = 1;
		ll L, R; cin >> L >> R;
		F0Rd(k, 35) {
			if (k <= 3) {
				//F0R(i, 16) cout << i << " " << cnts[i] << endl;
			}
			ll res[16]; F0R(i, 16) res[i] = 0;
			
			bool bL = (L & (1ll << k)); bool bR = (R & (1ll << k));
			
			//case 1: 0, 0
			
			F0R(i, 16) {
				if (bL && (i & 1 || i & 4)) continue;
				int X = i;
				if (bR) X &= 5;
				res[X] += cnts[i];
			}
			
			//case 2: 0, 1
			F0R(i, 16) {
				if (bL && (i & 1)) continue;
				int X = i;
				if (bR) X &= 13;
				if (!bR && (i & 8)) continue;
				if (!bL) X &= 11;
				res[X] += cnts[i];
				//if (i == 15 && k == 2) cout << X << " anded" << endl;
			}
			
			// case 3: 1, 0
			
			F0R(i, 16) {
				if (bL && (i & 4)) continue;
				int X = i;
				if (bR) X &= 7;
				if (!bR && (i & 2)) continue;
				if (!bL) X &= 14;
				res[X] += cnts[i];
			}
			
			
			
			F0R(i, 16) cnts[i] = res[i];
		}
		
		ll ans = 0;
		F0R(i, 16) ans += cnts[i];
		
		cout << ans << endl;
		
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343