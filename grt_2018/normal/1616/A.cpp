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
int t, n;
int b[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int a, i = 0; i < n; ++i) {
			cin >> a;
			b[abs(a)]++;
		}
		int ans = 0;
		for(int i = 1; i <= 100; ++i) {
			ans += min(b[i], 2);
			b[i] = 0;
		}
		ans += min(b[0], 1);
		b[0] = 0;
		cout << ans << "\n";
	}
}