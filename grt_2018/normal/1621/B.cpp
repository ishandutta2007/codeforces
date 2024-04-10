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

const int INF = 1e9 + 10;
int t, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		int mx = -1, cost = -1;
		int lft = INF, rght = -INF, cl = -1, cr = -1;
		for(int l,r,c, i = 0; i < n; ++i) {
			cin >> l >> r >> c;
			if(r - l + 1 > mx) {
				mx = r - l + 1;
				cost = c;
			} else if(r - l + 1 == mx) {
				cost = min(cost, c);
			}
			if(l < lft) {
				lft = l;
				cl = c;
			} else if(l == lft) {
				cl = min(cl, c);
			}
			if(r > rght) {
				rght = r;
				cr = c;
			} else if(r == rght) {
				cr = min(cr, c);
			}
			int ans = cl + cr;
			if(rght - lft + 1 == mx) {
				ans = min(ans, cost);
			}
			cout << ans << "\n";
		}
	}
}