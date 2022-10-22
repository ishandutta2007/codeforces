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

const int nax = 300 * 1000 + 10;
int n, m, t;
int a[nax], b[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for(int j = 1; j <= m; ++j) {
			cin >> b[j];
		}
		ll ans = 0;
		int last = 1;
		sort(a + 1, a + n + 1);
		for(int i = n; i >= 1; --i) {
			if(last <= a[i]) {
				ans += b[last++];
			} else ans += b[a[i]];
		}
		cout << ans << "\n";
	}
			
		
}