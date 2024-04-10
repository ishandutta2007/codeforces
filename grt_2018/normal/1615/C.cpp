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

const int INF = 1e9 + 10;
int T, n;
string s, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n >> s >> t;
		if(s == t) {
			cout << "0\n";
			continue;
		}
		int cnt[2];
		cnt[0] = cnt[1] = 0;
		for(int i = 0; i < n; ++i) {
			if((s[i] ^ t[i]) == 1) {
				cnt[(s[i] & 1)]++;
			}
		}
		int ans = INF;
		if(cnt[0] == cnt[1]) {
			ans = min(ans, 2 * cnt[0]);
		}
		cnt[0] = cnt[1] = 0;
		for(int i = 0; i < n; ++i) {
			if((s[i] ^ t[i]) == 0) {
				cnt[(s[i] & 1)]++;
			}
		}
		if(cnt[1] == cnt[0] + 1) {
			ans = min(ans, cnt[1] + cnt[0]);
		}
		if(ans == INF) {
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
	}
}