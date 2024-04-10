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

int t, n;
const int nax = 500;
const double eps = 0.00000001;
int a[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		if(n == 1) {
			cout << "0\n";
			continue;
		}
		int ans = n - 1;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				long double diff = ((long double)(a[j] - a[i])) / (j - i);
				long double start = (long double)a[i] - diff * (i - 1);
				int res = 0;
				for(int k = 1; k <= n; ++k) {
					if(abs(start - a[k]) < eps) {
						res++;
					}
					start += diff;
				}
				ans = min(ans, n - res);
			}
		}
		cout << ans << "\n";
	}
}