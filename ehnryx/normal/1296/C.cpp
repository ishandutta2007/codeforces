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
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<pair<int,int>,vector<int>> idx;
		int x = 0;
		int y = 0;
		for(int i=0; i<n; i++) {
			idx[make_pair(x, y)].push_back(i);
			if(s[i] == 'L') x--;
			if(s[i] == 'R') x++;
			if(s[i] == 'U') y--;
			if(s[i] == 'D') y++;
		}
		idx[make_pair(x, y)].push_back(n);
		pair<int,int> best(0, INF);
		for(const auto& [_, v] : idx) {
			for(int i=1; i<v.size(); i++) {
				if(v[i] - v[i-1] < best.second - best.first) {
					best = make_pair(v[i-1], v[i]);
				}
			}
		}
		if(best.second == INF) {
			cout << -1 << nl;
		} else {
			cout << best.first + 1 << " " << best.second << nl;
		}
	}

	return 0;
}