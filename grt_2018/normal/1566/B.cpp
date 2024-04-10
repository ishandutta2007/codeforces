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

int t;
string s;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> s;
		bool one = true;
		for(auto c : s) {
			if(c != '1') one = false;
		}
		if(one) {
			cout << "0\n";
			continue;
		}
		int x = -1, y = -1, cnt = 0;
		for(int i = 0; i < (int)s.size(); ++i) {
			if(s[i] == '0') {
				y = i;
				if(x == -1) {
					x = i;
				}
				cnt++;
			}
		}
		if(y - x + 1 == cnt) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}