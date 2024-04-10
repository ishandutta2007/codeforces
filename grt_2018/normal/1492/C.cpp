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

const int nax = 2e5 + 10;
int n, m;
string s, t;
int a[nax], b[nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	int ptr = 0;
	for(int i = 0; i < m; ++i) {
		while(s[ptr] != t[i]) {
			ptr++;
		}
		a[i] = ptr;
		ptr++;
	}
	ptr = n - 1;
	for(int i = m-1; i >=0; --i) {
		while(s[ptr] != t[i]) {
			ptr--;
		}
		b[i] = ptr;
		ptr--;
	}
	int ans = 0;
	for(int i = 0; i < m - 1; ++i) {
		ans = max(ans, b[i + 1] - a[i]);
	}
	cout << ans;
}