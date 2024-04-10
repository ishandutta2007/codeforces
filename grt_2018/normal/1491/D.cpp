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

int q;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		if(x > y) {
			cout << "NO\n";
			continue;
		}
		int a = 0, b = 0;
		bool ok = true;
		for(int i = 0; i < 30; ++i) {
			if((1 << i) & x) a++;
			if((1 << i) & y) b++;
			if(b > a) {
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