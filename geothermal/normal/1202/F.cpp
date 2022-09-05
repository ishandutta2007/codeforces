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
    ll A, B; cin >> A >> B;
    
    ll ans = 0;
    
	int M = A+B; //M must be floor(N / x) for some x, so x*M <= N < x*M+x
	//x*M <= N, x <= N/M
	while (M != 0) {
		
		ll K = A+B; ll maxVal, minVal;
		if (A/M < (A+M)/(M+1) || B/M < (B+M)/(M+1)) goto done;
		maxVal = A/M + B/M; //ensuring we have enough
		//if (M != 1) maxVal = min(maxVal, (K+M-2)/(M-1)-1);
		maxVal = min(maxVal, K/M); //ensuring appropriate length
		
		//how do we ensure continuance?
		
		minVal = (A+M)/(M+1) + (B+M)/(M+1);
		//if (M != 1) minVal = max(minVal, (K+M-1)/M);
		minVal = max(minVal, (K)/(M+1)+1);
		if (maxVal >= minVal) {
			ans += maxVal - minVal + 1;
		}
		
		//if (M == 2) cout << M << " " << maxVal << " " << minVal << endl;
		
		done:;
		ll maxX = K/M; maxX++;
		M = K/maxX;
	
	}
	cout << ans << endl;
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343