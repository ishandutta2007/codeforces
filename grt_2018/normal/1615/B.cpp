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

const int nax = 200 * 1000 + 10;
int t, l, r;
int cnt[nax][20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int bit = 0; bit < 20; ++bit) {
		for(int i = 1; i <= 200 * 1000; ++i) {
			cnt[i][bit] = cnt[i - 1][bit] + (((1<<bit) & i) > 0);
		}
	}
	while(t--) {
		cin >> l >> r;
		int mx = -1;
		for(int bit = 0; bit < 20; ++bit) {
			int a = cnt[r][bit] - cnt[l - 1][bit];
			mx = max(mx, a);
		}
		cout << r - l + 1 - mx << "\n";
	}
}