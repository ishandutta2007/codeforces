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
int t, n;
pi w[nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			w[i].ND = 0;
			cin >> w[i].ST;
			ans += w[i].ST;
		}
		for(int a, b, i = 1; i < n; ++i) {
			cin >> a >> b;
			w[a].ND++;
			w[b].ND++;
		}
		sort(w + 1, w + n + 1);
		cout << ans << " ";
		for(int i = n; i >= 1; --i) {
			while((int)w[i].ND > 1) {
				w[i].ND--;
				ans += w[i].ST;
				cout << ans << " ";
			}
		}
		cout << "\n";
	}
		
			
}