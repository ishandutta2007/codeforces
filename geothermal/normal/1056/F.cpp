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

void solve() {
	int N; cin >> N;
	ld C, T; cin >> C >> T;
	vpi problems;
	F0R(i, N) {
		int A, B; cin >> A >> B;
		problems.pb({A, B});
	}
	sort(all(problems));
	
	
	ld minSum[1001][101];
	bool found[1001][101];
	F0R(i, 1001) {
		F0R(j, 101) {
			minSum[i][j] = 1000000000000000;
			found[i][j] = false;
		}
	}
	minSum[0][0] = 0;
	found[0][0] = true;
	
	ld mult = (ld) 1.0 / (ld) 0.9;
	
	F0R(i, N) {
		F0Rd(j, 100) {
			F0R(k, 1001) {
				if (!found[k][j]) continue;
				if (k + problems[i].s > 1000) continue;
				minSum[k+problems[i].s][j+1] = min(minSum[k+problems[i].s][j+1], mult * (minSum[k][j] + problems[i].f));
				found[k+problems[i].s][j+1] = true;
			}
		}
	}
	
	int ans = 0;
	
	FOR(i, 1, 1001) {
		F0R(j, 101) {
			if (!found[i][j]) continue;
			ld x = pow(minSum[i][j]*C, (ld) 0.5) - 1;
			x = max(x, (ld) 0);
			if (x/C + 10*j + minSum[i][j] / (1+x) <= T) {
				ans = max(ans, i);
			}
		}
	}
	cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int tc; cin >> tc;
	F0R(testCase, tc) {
		solve();
	}
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE