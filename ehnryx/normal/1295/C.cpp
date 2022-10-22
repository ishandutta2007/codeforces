//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;
		int n = s.size();
		vector<vector<int>> idx(26);
		for(int i=0; i<n; i++) {
			idx[s[i]-'a'].push_back(i);
		}

		int ans = 1;
		int cur = 0;
		for(char c : t) {
			if(idx[c-'a'].empty()) {
				ans = -1;
				break;
			}
			auto it = lower_bound(idx[c-'a'].begin(), idx[c-'a'].end(), cur);
			if(it == idx[c-'a'].end()) {
				ans++;
				it = idx[c-'a'].begin();
			}
			cur = *it + 1;
		}
		cout << ans << nl;
	}

	return 0;
}