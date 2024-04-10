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

const int nax = 100 * 1000 + 10;
int n, m, t;
int last, cnt;
int ans[nax];
vi a[nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		cnt = 0;
		for(int i = 1; i <= m; ++i) {
			int k;
			cin >> k;
			a[i].resize(k);
			for(int j = 0; j < k; ++j) {
				cin >> a[i][j];
			}
			if(k == 1) {
				ans[i] = a[i][0];
				if(cnt == 0) {
					cnt = 1;
					last = a[i][0];
				} else if(last != a[i][0]) {
					cnt--;
				} else {
					cnt++;
				}
			}
		}
		//cout << last << " " << cnt << ":\n";
		for(int i = 1; i <= m; ++i) {
			if((int)a[i].size() == 1) continue;
			if(cnt == 0) {
				cnt = 1;
				last = a[i][0];
				ans[i] = a[i][0];
			} else if(last == a[i][0]) {
				cnt--;
				ans[i] = a[i][1];
			} else {
				cnt--;
				ans[i] = a[i][0];
			}
		}
		cnt = 0;
		for(int i = 1; i <= m; ++i) {
			if(ans[i] == last) cnt++;
		}
		if(cnt > (m-1)/2+1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for(int i = 1; i <= m; ++i) {
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
	}
}