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

const int nax = 100 * 1000 + 10;
int n;
int a[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << "1";
		return 0;
	}
	int b = -1, c = -1;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(b == c && b == a[i]) continue;
		if(b == c) {
			b = a[i];
			ans++;
			continue;
		}
		if(b == a[i]) {
			c = a[i];
		} else if(c == a[i]) {
			b = a[i];
		} else {
			b = a[i];
			c = -1;
		}
		ans++;
	}
	
	cout << ans;
}