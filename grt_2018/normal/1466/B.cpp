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

int t, n;
int cnt[200 * 1000 + 10];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= 2 * n + 2; ++i) {
			cnt[i] = 0;
		}
		for(int a, i = 0; i < n; ++i) {
			cin >> a;
			cnt[a]++;
		}
		int mx = 0;
		for(int i = 1; i <= 2 * n + 2; ++i) {
			if(cnt[i - 1]) {
				mx++;
			} else if(cnt[i]) {
				cnt[i]--;
				mx++;
			}
		}
		cout << mx << "\n";
	}
		
}