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

int dfs(int v, int power, bool last, bool cur) {
	if (v <= power) {
		int res = 1;
		res += dfs(v*2, power, last, !cur);
		if (res % 2 == 1) last = !last;
		res += dfs(v*2+1, power, last, cur);
		return res;
	} else {
		if (last == cur) {
			return 1;
		} else return 0;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int powers[21];
	powers[0] = 1;
	FOR(i, 1, 21) powers[i] = powers[i-1] * 2;
	
	int N; cin >> N;
	
	if (N == 1) {
		cout << 1 << endl; return 0;
	}
	
	int P;
	F0Rd(i, 21) {
		if (powers[i] - 1 <= N) {
			P = powers[i] - 1;
			break;
		}
	}
	int ans = 0;
	if (dfs(1, P, false, true) == N) {
		ans++;
	}
	if (dfs(1, P, false, false) == N) {
		ans++;
	}
	
	cout << ans << endl;
	
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE