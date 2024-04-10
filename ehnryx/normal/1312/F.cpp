//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int BIG_NIMBER = 7;

int mex(int a, int b, int c) {
	if(b < a) swap(a, b);
	if(c < a) swap(a, c);
	if(c < b) swap(b, c);
	if(0 < a) return 0;
	if(a+1 < b) return a+1;
	if(b+1 < c) return b+1;
	return c+1;
}

const int M = 1789;
int nim[M][3];

pair<int,int> get_period(int x, int y, int z) {
	unordered_map<int,int> seen;
	int ha = 0;
	for(int i=1; ; i++) {
		assert(i < M);
		int px = max(0, i-x);
		int py = max(0, i-y);
		int pz = max(0, i-z);
		nim[i][0] = mex(nim[px][0], nim[py][1], nim[pz][2]);
		nim[i][1] = mex(nim[px][0], BIG_NIMBER, nim[pz][2]);
		nim[i][2] = mex(nim[px][0], nim[py][1], BIG_NIMBER);
		int cur = nim[i][0] | nim[i][1] << 2 | nim[i][2] << 4;
		ha = ha >> 6 | cur << 24;
		if(i >= 5) {
			if(seen.count(ha)) {
				return make_pair(seen[ha] - 4, i - seen[ha]);
			}
			seen[ha] = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		auto [start, period] = get_period(x, y, z);

		function<int(ll,int)> query = [=] (ll v, int t) {
			if(v < start) return nim[v][t];
			v = (v - start) % period;
			return nim[start + v][t];
		};

		vector<ll> a(n);
		int res = 0;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			res ^= query(a[i], 0);
		}
		int ans = 0;
		for(int i=0; i<n; i++) {
			ll nx = max((ll)0, a[i] - x);
			ll ny = max((ll)0, a[i] - y);
			ll nz = max((ll)0, a[i] - z);
			ans += ((res ^ query(nx, 0) ^ query(a[i], 0)) == 0);
			ans += ((res ^ query(ny, 1) ^ query(a[i], 0)) == 0);
			ans += ((res ^ query(nz, 2) ^ query(a[i], 0)) == 0);
		}
		cout << ans << nl;
	}

	return 0;
}