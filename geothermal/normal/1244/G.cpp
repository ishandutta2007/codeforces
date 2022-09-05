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
	
	ll N, K; cin >> N >> K;
	
	if (K < N*(N+1) / 2) {
		cout << -1 << endl; return 0;
	}
	
	K -= N*(N+1) / 2;
	
	ll count = 0;
	ll rem = 0;
	F0R(i, (N+1)/2) {
		if (K >= N-1-i*2) {
			count++;
			K -= N-1-i*2;
		} else {
			rem = K+i; break;
		}
	}
	ll ans[N];
	ll res = 0;
	F0R(i, N) {
		
		if (i >= N-count) {
			ans[i] = N-1-i;
		} else if (i == rem) {
			ans[i] = count;
		} else if (i > rem) {
			ans[i] = i+count;
			
		} else {
			ans[i] = i + count + 1;
		}
		
		res += 1 + max((ll) i, ans[i]);
		
	}
	
	cout << res << endl;
	F0R(i, N) {
		cout << i+1 << " ";
	}
	cout << endl;
	F0R(i, N) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE