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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	string S; cin >> S;
	int N = sz(S);
	int zero = 0, one = 0;
	int ourZero = 0, ourOne = 0;
	vi result;
	F0Rd(i, N) {
		
		if (S[i] == '0') {
			zero = max(zero+1, one+1);
		} else {
			one++;
		}
		if (max(zero, one) == max(ourZero+1, ourOne+1)) {
			result.pb(0);
			ourZero = max(ourZero+1, ourOne+1);
		} else {
			result.pb(1);
			ourOne++;
		}
	}
	reverse(all(result));
	F0R(i, N) cout << result[i];
	cout << endl;
	/*int countZero[N+1]; //number of zeroes before S[i].
	int countOne[N+1]; //number of ones at or after S[i].
	countZero[0] = 0;
	FOR(i, 1, N+1) {
		countZero[i] = countZero[i-1];
		if (S[i-1] == '0') countZero[i]++;
	}
	countOne[N] = 0;
	F0Rd(i, N) {
		countOne[i] = countOne[i+1];
		if (S[i] == '1') countOne[i]++;
	}
	
	int maxRes = 0;
	F0R(i, N) {
		//maxRes = max(maxRes, countZero[i] + countOne[i]);
		if (S[i] == '1') {
			maxRes = max(maxRes, countZero[i] + countOne[i]);
		}
		if (S[i] == '1' && maxRes > countZero[i] + countOne[i]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << endl;*/
	
	/*F0R(i, N-maxRes) {
		cout << 1;
	}
	F0R(i, maxRes) cout << 0;*/
	
	cout << endl;
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE