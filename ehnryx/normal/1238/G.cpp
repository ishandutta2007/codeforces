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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin>>T;
	while(T--) {
		int n, m, c, c0;
		cin >> n >> m >> c >> c0;
		map<int,vector<pii>> vals;
		vals[0].push_back(pii(c0,0));
		for(int i=0;i<n;i++) {
			int t, a, b;
			cin >> t >> a >> b;
			vals[t].push_back(pii(a,b));
		}
		vals[m];

		ll ans = 0;
		ll tot = 0;
		int pre = 0;
		map<int,ll> res;
		for(const auto& it:vals) {
			int diff = it.first - pre;
			while(diff > 0 && !res.empty()) {
				auto jt = res.begin();
				if(jt->second <= diff) {
					ans += (ll) jt->first * jt->second;
					diff -= jt->second;
					tot -= jt->second;
					res.erase(jt);
				} else {
					ans += (ll) jt->first * diff;
					jt->second -= diff;
					tot -= diff;
					diff = 0;
				}
			}
			if(diff > 0) {
				ans = -1;
				break;
			}

			// push
			for(const auto& v:it.second) {
				res[v.second] += v.first;
				tot += v.first;
			}
			// pop
			while(tot > c) {
				assert(!res.empty());
				auto jt = prev(res.end());
				if(jt->second <= tot-c) {
					tot -= jt->second;
					res.erase(jt);
				} else {
					jt->second -= tot-c;
					tot = c;
				}
			}
			assert(0 <= tot && tot <= c);
			pre = it.first;
		}
		cout << ans << nl;
	}

	return 0;
}