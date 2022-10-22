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

const int nax = 1e5 + 10;
int t;
int n;
string s1, s2;
bool matchd[nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> s1 >> s2;
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			matchd[i] = 0;
		}
		for(int i = 0; i < n; ++i) {
			if(s1[i] == s2[i] && s1[i] == '0') ans++;
			if(s1[i] != s2[i]) {
				ans+=2;
			}
			else if(i < n - 1) {
				//if(i == 1) {
					//cout << matchd[i] << "\n";
				//}
				if(s1[i + 1] == s2[i + 1] && s1[i + 1] != s1[i] && !matchd[i]) {
					matchd[i] = matchd[i + 1] = true;
					ans++;
				}
			}
			//cout << ans << "\n";
		}
		cout << ans << "\n";
	}
	
}