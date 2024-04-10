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
const ll MOD = 1e9+7;
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
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> val(m);
		for(int i=0; i<m; i++) {
			cin >> val[i];
		}
		val.push_back(INF);
		sort(val.begin(), val.end(), greater<int>());
		vector<ll> ans(26);
		for(int i=n-1, j=0, cnt=0; i>=0; i--) {
			while(j < val.size() && val[j] > i) {
				j++;
				cnt++;
			}
			ans[s[i]-'a'] += cnt;
		}
		for(int i=0; i<26; i++) {
			cout << ans[i] << " ";
		}
		cout << nl;
	}

	return 0;
}