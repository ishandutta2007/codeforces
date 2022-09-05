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
	
	string ans;
	string S, T; cin >> S >> T;
	
	cout << "YES" << endl;
	
	if (S[0] == T[0] && (S[0] != S[1] && T[0] != T[1])) {
		F0R(i, 3) {
			if (i == S[0] - 'a') continue;
			F0R(j, N) {
				ans += ('a' + i);
			}
		}
		
		F0R(i, N) ans += S[0];
	} else if (S[1] == T[1]&& (S[0] != S[1] && T[0] != T[1])) {
		F0R(i, N) ans += S[1];
		
		F0R(i, 3) {
			if (i == S[1] - 'a') continue;
			F0R(j, N) ans += ('a' + i);
		}
		
	} else if (S[0] == T[1] && T[0] == S[1]&& (S[0] != S[1] && T[0] != T[1])) {
		F0R(i, N) {
			ans += S[0];
		}
		F0R(i, 3) {
			if (i == S[1] - 'a' || i == S[0] - 'a') continue;
			F0R(j, N) ans += ('a' + i);
		}
		
		F0R(i, N) ans += S[1];
	} else{
		char succ[3];
		succ[0] = 1;
		succ[1] = 2;
		succ[2] = 0;
		if ((S[0] - 'a' + 1) % 3 == S[1] - 'a' || (S[0] == S[1] && (T[0] - 'a' + 1) % 3 == T[1] - 'a')) {
			succ[0] = 2;
			succ[1] = 0;
			succ[2] = 1;
		}
		
		
		
		int nxt = 0;
		
		F0R(i, 3*N) {
			ans += ('a' + nxt);
			nxt = succ[nxt];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343