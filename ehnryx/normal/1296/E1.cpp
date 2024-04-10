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

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<set<int>> cols(26);
	vector<int> ans;
	for(char c : s) {
		set<int> skip;
		for(int i=c-'a'+1; i<26; i++) {
			skip.insert(cols[i].begin(), cols[i].end());
		}
		int colour = -1;
		for(int i=1; i<=26; i++) {
			if(!skip.count(i)) {
				colour = i;
				break;
			}
		}
		assert(colour != -1);
		ans.push_back(colour);
		cols[c-'a'].insert(colour);
	}

	if(*max_element(ans.begin(), ans.end()) <= 2) {
		cout << "YES" << nl;
		for(int it : ans) {
			cout << it-1;
		}
		cout << nl;
	} else {
		cout << "NO" << nl;
	}

	return 0;
}