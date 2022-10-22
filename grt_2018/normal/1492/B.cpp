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

const int nax = 100 * 1000 + 10, INF = 1e9 + 10;
int t, n;
int p[nax];
int ans[nax];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		vi S = {INF};
		for(int i = n; i >= 1; --i) {
			while(S.back() < p[i]) {
				S.pop_back();
			}
			S.PB(p[i]);
		}
		int id = 1, last = n + 1, nr = 1;
		for(int i = n; i >= 1; --i) {
			if(id < (int)S.size()) {
				if(p[i] == S[id]) {
					for(int j = i; j < last; ++j) {
						ans[nr++] = p[j];
					}
					last = i;
					id++;
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}