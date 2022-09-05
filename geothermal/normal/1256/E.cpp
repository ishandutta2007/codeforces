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
	vpi data(N);
	F0R(i, N)  {
		int A; cin >> A; data[i] = {A, i};
	}
	sort(all(data));
	
	ll dp[N+1];
	ll lst[N+1];
	F0R(i, N+1) {
		dp[i] = 1000000000;
		lst[i] = -1;
	}
	dp[0] = -1*data[0].f;
	ll minVal = 1000000000;
	ll minPos = -1;
	FOR(i, 1, N+1) {
		if (i >= 3 && dp[i-3] < minVal) {
			minPos = i-3; minVal = dp[i-3];
		}
		
		dp[i] = data[i-1].f + minVal;
		if (i < N) dp[i] -= data[i].f;
		lst[i] = minPos;
	}
	
	cout << dp[N] << " ";
	int team[N];
	int cur = N;
	int nxtTeam = 1;
	while (cur > 0) {
		FOR(i, lst[cur], cur) {
			team[data[i].s] = nxtTeam;
		}
		nxtTeam++;
		cur = lst[cur];
	}
	
	cout << nxtTeam-1 << endl;
	
	F0R(i, N) {
		cout << team[i] << " ";
	}
	cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343