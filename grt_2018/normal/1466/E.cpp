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

const int nax = 500 * 1000 + 10, mod = 1e9 + 7;
int t, n;
ll x[nax];
int cnt[61];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i <= 60; ++i) cnt[i] = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> x[i];
			for(int j = 0; j < 60; ++j) {
				if((1LL << j) & x[i]) cnt[j]++;
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ll s1 = 0, s2 = 0;
			for(int j = 0; j < 60; ++j) {
				int p = (1LL << j) % mod;
				if((1LL << j) & x[i]) {
					s2 = (s2 + (ll)p * n) % mod;
					s1 = (s1 + (ll)p * cnt[j]) % mod;
				} else {
					s2 = (s2 + (ll)p * cnt[j]) % mod;
				}
			}
			ans = (ans + s1 * s2) % mod;
		}
		cout << ans << "\n";
	}
}