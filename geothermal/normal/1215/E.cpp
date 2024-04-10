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
	
	vi data(N);
	F0R(i, N) {
		cin >> data[i];
		data[i]--;
	}
	
	ll inv[20][20];
	
	ll dp[1 << 20];
	
	F0R(i, 1 << 20) dp[i] = 1000000000000000;
	dp[0] = 0;
	ll countRem[20];
	F0R(i, 20) {
		countRem[i] = 0;
		F0R(j, 20) {
			inv[i][j] = 0;
		}
	}
	
	F0R(i, N) {
		countRem[data[i]]++;
	}
	
	F0R(i, N) {
		countRem[data[i]]--;
		F0R(j, 20) {
			if (j == data[i]) continue;
			inv[j][data[i]] += countRem[j];
		}
	}
	
	F0R(i, 1 << 20) {
		F0R(nxt, 20) {
			if (i & (1 << nxt)) continue;
			ll cost = 0;
			F0R(j, 20) if (!(i & (1 << j))) cost += inv[nxt][j];
			dp[i+(1 << nxt)] = min(dp[i+(1 << nxt)], dp[i] + cost);
		}
	}
	
	cout << dp[(1 << 20) - 1] << endl;
	

		
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343