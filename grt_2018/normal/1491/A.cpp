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
int n, q;
int a[nax];
int cnt[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	while(q--) {
		int t, x;
		cin >> t >> x;
		if(t == 1) {
			cnt[a[x]]--;
			a[x] = 1 - a[x];
			cnt[a[x]]++;
		} else {
			if(cnt[1] >= x) {
				cout << "1\n";
			} else {
				cout << "0\n";
			}
		}
	}
}