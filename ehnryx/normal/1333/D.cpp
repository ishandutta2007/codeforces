//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<vector<int>> moves;
	int total = 0;
	for(;;) {
		vector<int> cur;
		for(int i=1; i<n; i++) {
			if(s[i-1] == 'R' && s[i] == 'L') {
				cur.push_back(i);
				swap(s[i-1], s[i]);
				i++; // skip
			}
		}
		if(cur.empty()) break;
		total += cur.size();
		moves.push_back(move(cur));
	}

	if(moves.size() > k || total < k) {
		cout << -1 << nl;
	} else {
		vector<int> expanded;
		while(moves.size() + expanded.size() < k) {
			int last = moves.back().back();
			expanded.push_back(last);
			moves.back().pop_back();
			if(moves.back().empty()) {
				moves.pop_back();
			}
		}
		reverse(expanded.begin(), expanded.end());
		for(const auto& layer : moves) {
			cout << layer.size() << " ";
			for(int it : layer) {
				cout << it << " ";
			}
			cout << nl;
		}
		for(int it : expanded) {
			cout << 1 << " " << it << nl;
		}
	}

	return 0;
}