//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct BIT {
	static const int N = 2e5 + 7;
	ll bit[N];
	ll query(int x) {
		ll res = 0;
		for(++x; x>0; x-=x&-x) {
			res += bit[x];
		}
		return res;
	}
	ll query(int l, int r) {
		return query(r) - query(l-1);
	}
	void insert(int x, int v) {
		for(++x; x<N; x+=x&-x) {
			bit[x] += v;
		}
	}
} cntbit, sumbit;

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<int> x(n);
	map<int,int> remap;
	for(int i=0; i<n; i++) {
		cin >> x[i];
		remap[x[i]];
	}
	vector<pair<int,int>> p;
	for(int i=0; i<n; i++) {
		int v;
		cin >> v;
		p.push_back(make_pair(v, x[i]));
	}
	sort(p.begin(), p.end());

	int uid = 0;
	for(auto& it : remap) {
		it.second = ++uid;
	}

	ll ans = 0;
	for(auto [vel, pos] : p) {
		int r = remap[pos];
		ll cnt = cntbit.query(1, r);
		ll sum = sumbit.query(1, r);
		ans += cnt*pos - sum;
		cntbit.insert(r, 1);
		sumbit.insert(r, pos);
	}
	cout << ans << nl;

	return 0;
}