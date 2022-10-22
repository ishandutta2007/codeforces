#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10, INF = 1e9;
int n;
int a[nax];
int dp[nax];
multiset<pi>S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vi b = {};
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(i == 1) {
			b.PB(a[i]);
		} else if(a[i] != a[i - 1]) {
			b.PB(a[i]);
		}
	}
	for(int i = 1; i <= (int)b.size(); ++i) {
		dp[i] = dp[i - 1] + 1;
		auto it = S.lower_bound({b[i - 1], -INF});
		if(it != S.end() && (*it).ST == b[i - 1]) {
			dp[i] = min(dp[i], i - 1 + (*it).ND);
		}
		//cout << dp[i] << " ";
		if(i > 1) S.insert({b[i - 2], dp[i] - i});
	}
	cout << dp[(int)b.size()];
	
}