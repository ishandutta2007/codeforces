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

int t;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> s;
		int cnt = 0;
		for(int i = 1; i < (int)s.size(); ++i) {
			if(s[i] == s[i - 1] || (i > 1 && s[i - 2] == s[i])) {
				s[i] = '0';
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
		
}