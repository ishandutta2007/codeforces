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
int t, n, q;
int a[nax];
map<int,int>licz;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		licz.clear();
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			int ilo = 1;
			for(int d = 2; (ll)d * d <= a[i]; ++d) {
				int cnt = 0;
				while(a[i] % d == 0) {
					a[i] /= d;
					cnt++;
				}
				if(cnt & 1) ilo *= d;
			}
			if(a[i] > 0) ilo *= a[i];
			a[i] = ilo;
			licz[a[i]]++;
		}
		//cout << "nxt\n";
		int mx = -1, sum = 0;
		for(auto it : licz) {
			mx = max(mx, it.ND);
			if(it.ND % 2 == 0 || it.ST == 1) sum += it.ND;
		}
		cin >> q;
		while(q--) {
			ll x;
			cin >> x;
			if(x == 0) {
				cout << mx << "\n";
			} else {
				cout << max(mx, sum) << "\n";
			}
		}
			
	}
}