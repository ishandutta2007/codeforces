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
	
	int N, K; cin >> N >> K;
	
	int Q[N]; F0R(i, N) { cin >> Q[i]; Q[i]--; }
	
	int P[N]; F0R(i, N) { cin >> P[i]; P[i]--; }
	
	int invQ[N]; F0R(i, N) invQ[Q[i]] = i;
	
	F0R(i, N) P[i] = invQ[P[i]];
	
	
	
	//F0R(i, N) cout << P[i] << " ";
	

	
	vi starts, ends;
	//int biggestSoFar = 0;
	F0R(i, N-1) {
		//biggestSoFar = max(biggestSoFar, P[i]);
		if(P[i] > P[i+1]) {
			
			ends.pb(P[i]);
			starts.pb(P[i+1]+1);
		}
		
	}
	
	sort(all(starts));
	sort(all(ends));
	
	
	string res;
	
	int nxt = -1;
	int nS = 0, nE = 0;
	int count = 0;

	
	F0R(i, N) {
		while (nS < sz(starts) && starts[nS] == i) {
			nS++; count++;
		}
		
		
		if (count == 0 && nxt < 25) {
			nxt++;
		}
		
		res += ('a' + nxt);
		while (nE < sz(ends) && ends[nE] == i) {
			nE++;
			count--;
		}
	}
	
	string res2; F0R(i, N) res2 += 'a';
	
	//cout << res << endl;
	
	F0R(i, N) {
		res2[Q[i]] = res[i];
	}
	
	if (nxt + 1 >= K) {
		cout << "YES" << endl;
		F0R(i, N) cout << res2[i];
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343