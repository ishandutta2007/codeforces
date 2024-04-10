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
const int nax = 1e5 + 10, INF = 1e9 + 10;
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
	    ll pw = 1;
		bool ok = true;
		for(int i = 1; i <= n; ++i) {
			pw = (pw * (i + 1)) / __gcd(pw, (ll)(i + 1));
			pw = min(pw, (ll)INF);
			if(a[i] % pw == 0) {
				ok = false;
			}
		}
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}