#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e3+1;
bool adj[N][N];
int deg[N], vals[N];

ll factorial(int n) {
	ll res = 1;
	for(int i=n; i>1; i--) {
		res *= i;
	}
	return res;
}

void flip(int n, int s) {
	for(int i=0; i<n; i++) {
		adj[i][s] ^= 1;
		deg[i] += (adj[i][s] ? 1 : -1);
		adj[s][i] ^= 1;
		deg[s] += (adj[s][i] ? 1 : -1);
	}
}

bool valid(int n) {
	for(int i=0; i<n; i++) {
		vals[i] = deg[i];
	}
	sort(vals, vals+n, greater<int>());
	int out = 0;
	for(int k=1; k<n; k++) {
		out += vals[k-1];
		if(out == k*(k-1)/2 + k*(n-k)) {
			return false;
		}
	}
	return true;
}


void solve_small(int n) {
	int best = INF;
	int cnt = 0;
	for(int bm=0; bm<1<<n; bm++) {
		for(int j=0; j<n; j++) {
			if(bm & 1<<j) flip(n, j);
		}
		if(valid(n)) {
			int cur = __builtin_popcount(bm);
			if(cur < best) {
				best = cur;
				cnt = 0;
			}
			cnt += (cur == best);
		}
		for(int j=0; j<n; j++) {
			if(bm & 1<<j) flip(n, j);
		}
	}
	if(best == INF) {
		cout << -1 << nl;
	} else {
		cout << best << " " << cnt * factorial(best) << nl;
	}
}

void solve_big(int n) {
	if(valid(n)) {
		cout << 0 << " " << 1 << nl;
	} else {
		int ans = 0;
		for(int i=0; i<n; i++) {
			flip(n, i);
			ans += valid(n);
			flip(n, i);
		}
		assert(ans > 0);
		cout << 1 << " " << ans << nl;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<n; j++) {
			adj[i][j] = (s[j] == '1');
			if(adj[i][j]) deg[i]++;
		}
	}

	if(n < 17) {
		solve_small(n);
	} else {
		solve_big(n);
	}

	return 0;
}