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

int N;
ll S;
vpl sal;

bool poss(ll med) {
	vpl options;
	vpl others;
	F0R(i, N) {
		if (sal[i].s >= med) {
			options.pb(sal[i]);
		} else {
			others.pb(sal[i]);
		}
	}
	if (sz(options) < (N+1) / 2) return false;
	sort(all(options));
	reverse(all(options));
	FOR(i, (N+1)/2, sz(options)) {
		others.pb(options[i]);
	}
	ll cur = S;
	F0R(i, (N+1)/2) {
		cur -= max(options[i].f, med);
	}
	F0R(i, sz(others)) {
		cur -= others[i].f;
	}
	if (cur >= 0) {
		return true;
	}
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int T; cin >> T;
	F0R(testCase, T) {
		cin >> N >> S;
		sal.clear();
		F0R(i, N) {
			ll A, B; cin >> A >> B; sal.pb({A, B});
			
		}
		
		
		ll lo = 1, hi = 1000000000;
		F0R(i, 33) {
			ll mid = (lo+hi)/2;
			if (poss(mid)) {
				lo = mid;
			} else {
				hi = mid-1;
			}
		}
		
		if (poss(max(lo, hi))) {
			cout << max(lo, hi) << endl;
		} else {
			cout << min(lo, hi) << endl;
		}
	}
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343