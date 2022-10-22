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
const int nax = 5010;
int s[nax];
int cnt[nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> s[i];
			cnt[i] = 0;
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += max(0, s[i] - 1 - cnt[i]);
			cnt[i] = max(0, cnt[i] - (s[i] - 1));
			s[i] = min(n - i, s[i]);
			while(s[i] > 1) {
				cnt[i + s[i]]++;
				s[i]--;
			}
			cnt[i + 1] += cnt[i];
		}
		cout << ans << "\n";
	}
}