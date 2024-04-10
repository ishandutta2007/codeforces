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
    
    bool blackCells[N][N];
    F0R(i, N) {
		F0R(j, N) {
			char C; cin >> C;
			blackCells[i][j] = C == 'B';
		}
	}
	
	ll vals[N+1][N+1];
	F0R(i, N+1) {
		F0R(j, N+1) {
			vals[i][j] = 0LL;
		}
	}
	
	F0R(i, N) {
		ll minVal = N;
		ll maxVal = -1;
		ll minB = max(i-K+1, 0);
		ll maxB = i;
		F0R(j, N) {
			if (blackCells[i][j]) {
				minVal = min(minVal, (ll) j);
				maxVal = max(maxVal, (ll) j);
			}
		}
		ll minPos, maxPos;
		if (minVal == N) {
			vals[0][0]++;
			goto done1;
		} else {
			minPos = maxVal - K + 1;
			maxPos = minVal;
			minPos = max(minPos, (ll) 0);
			maxPos = min(maxPos, (ll) N-1);
			if (minPos > maxPos) goto done1;
		}
		
		
		
		vals[minB][minPos]++;
		vals[minB][maxPos+1]--;
		vals[maxB+1][minPos]--;
		vals[maxB+1][maxPos+1]++;
		
		done1:;
	}
	
	
	F0R(i, N) {
		ll minVal = N;
		ll maxVal = -1;
		ll minB = max(i-K+1, 0);
		ll maxB = i;
		F0R(j, N) {
			if (blackCells[j][i]) {
				minVal = min(minVal, (ll) j);
				maxVal = max(maxVal, (ll) j);
			}
		}
		ll minPos, maxPos;
		if (minVal == N) {
			vals[0][0]++; goto done2;
		} else {
			minPos = maxVal - K + 1;
			maxPos = minVal;
			minPos = max(minPos, (ll) 0);
			maxPos = min(maxPos, (ll) N-1);
			if (minPos > maxPos) goto done2;
		}
		
		
		
		vals[minPos][minB]++;
		vals[maxPos+1][minB]--;
		vals[minPos][maxB+1]--;
		vals[maxPos+1][maxB+1]++;
		
		
		done2:;
	}
	
	
	ll prefSums[N][N];
	
	ll ans = 0;

	
	F0R(i, N) {
		if (i == 0) {
			prefSums[0][0] = vals[0][0];
		} else {
			prefSums[i][0] = prefSums[i-1][0] + vals[i][0];
		}
		FOR(j, 1, N) {
			
			if (i != 0) {
				prefSums[i][j] = prefSums[i-1][j] + prefSums[i][j-1] - prefSums[i-1][j-1];
			} else {
				prefSums[i][j] = prefSums[i][j-1];
			}
			
			prefSums[i][j] += vals[i][j];
		}
	}
	
	F0R(i, N) {
		F0R(j, N) {
			ans = max(ans, prefSums[i][j]);
		}
	}
	
	cout << ans << endl;
	
	/*F0R(i, N) {
		F0R(j, N) {
			cout << vals[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	F0R(i, N) {
		F0R(j, N) {
			cout << prefSums[i][j] << " ";
		}
		cout << endl;
	}*/
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343