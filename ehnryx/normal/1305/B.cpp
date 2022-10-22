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

	string s;
	cin >> s;
	vector<vector<int>> ans;
	for(;;) {
		int n = s.size();
		set<int> cur;
		for(int i=0, j=n-1; i<j; i++, j--) {
			while(i<j && s[i]!='(') {
				i++;
			}
			while(i<j && s[j]!=')') {
				j--;
			}
			if(i == j) break;
			cur.insert(i);
			cur.insert(j);
		}
		if(cur.empty()) {
			break;
		}
		string t;
		vector<int> rem;
		for(int i=0; i<n; i++) {
			if(cur.count(i)) {
				rem.push_back(i+1);
			} else {
				t.push_back(s[i]);
			}
		}
		ans.push_back(move(rem));
		s = move(t);
	}

	cout << ans.size() << nl;
	for(const auto& v : ans) {
		cout << v.size() << nl;
		for(int it : v) {
			cout << it << " ";
		}
		cout << nl;
	}

	return 0;
}