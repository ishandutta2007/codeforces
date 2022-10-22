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
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		pii minv(INF, -1);
		pii maxv(INF, -1);
		pii ans(-1, -1);
		for(int i=0; i<n; i++) {
			int v;
			cin >> v;
			minv = min(minv, make_pair(v-i, i+1));
			maxv = min(maxv, make_pair(-v-i, i+1));
			if(v-i - minv.first >= 1) ans = make_pair(minv.second, i+1);
			if(-v-i - maxv.first >= 1) ans = make_pair(maxv.second, i+1);
		}
		if(ans.first != -1) cout << "YES" << nl << ans.first << " " << ans.second << nl;
		else cout << "NO" << nl;
	}

	return 0;
}