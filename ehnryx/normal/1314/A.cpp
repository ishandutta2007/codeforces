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
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	int a[n+1], b[n+1];
	vector<pair<int,int>> p;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> b[i];
		p.push_back(make_pair(a[i], b[i]));
	}
	sort(p.begin(), p.end());

	int pre = 0;
	ll ans = 0;
	ll cur = 0;
	multiset<int> active;
	for(auto [x, t] : p) {
		for(int i=pre+1; i<=x && !active.empty(); i++) {
			cur -= *prev(active.end());
			active.erase(prev(active.end()));
			ans += cur;
		}
		pre = x;
		cur += t;
		active.insert(t);
	}
	while(!active.empty()) {
		cur -= *prev(active.end());
		active.erase(prev(active.end()));
		ans += cur;
	}
	cout << ans << nl;

	return 0;
}