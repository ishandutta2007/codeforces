#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 110;
int t, n,u, v;
int a[nax];
	


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> u >> v;
		bool same = true;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(i > 1 && a[i] != a[i - 1]) same = false;
		}
		if(same) {
			cout << v + min(u, v) << "\n";
			continue;
		}
		int ans = min(u, v);
		bool block = true;
		for(int i = 2; i <= n; ++i) {
			if(abs(a[i] - a[i - 1]) > 1) {
				block = false;
			}
		}
		if(!block) cout << "0\n";
		else cout << ans << "\n";
	}
}