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

const int nax = 200 * 1000 + 10;
const ll INF = 1e18;
int t, n, m;
pi seg[nax];
ll pt[nax];
vi ind;
vi occ[nax];
ll dp[nax][2];

void test_case() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> pt[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> seg[i].ST >> seg[i].ND;
	}
	for(int i = 0; i <= n; ++i) {
		occ[i].clear();
	}
	ind.clear();
	sort(pt + 1, pt + n + 1);
	sort(seg + 1, seg + m + 1);
	for(int i = 1; i <= m; ++i) {
		while((int)ind.size() > 0 && seg[ind.back()].ND >= seg[i].ND) {
			ind.pop_back();
		}
		ind.PB(i);
	}
	int ptr = 0;
	m = (int)ind.size();
	//for(int x : ind) {
		//cout << seg[x].ST << " " << seg[x].ND << "\n";
	//}
	//cout << "---\n";
	for(int i = 1; i <= n; ++i) {
		while(ptr < m && seg[ind[ptr]].ND < pt[i]) {
			occ[i - 1].PB(ind[ptr]);
			ptr++;
		}
		while(ptr < m && seg[ind[ptr]].ST <= pt[i] && pt[i] <= seg[ind[ptr]].ND) {
			ptr++;
		}
	}
	for(int i = ptr; i < m; ++i) {
		occ[n].PB(ind[i]);
	}
	pt[0] = -INF;
	pt[n + 1] = INF;
	for(int i = 1; i <= n + 1; ++i) {
		//cout << i << ":\n";
		//for(int x : occ[i - 1]) {
			//cout << seg[x].ST << " " << seg[x].ND << "\n";
		//}
		dp[i][0] = dp[i - 1][0] + ((int)occ[i - 1].size() > 0 ? abs(pt[i] - seg[occ[i - 1][0]].ND) : 0);
		dp[i][1] = dp[i - 1][0] + 2 * ((int)occ[i - 1].size() > 0 ? abs(pt[i] - seg[occ[i - 1][0]].ND) : 0);
		int nxt = 0;
		for(auto id : occ[i - 1]) {
			ll tmp = min(dp[i - 1][1] + seg[id].ST - pt[i - 1], dp[i - 1][0] + 2 * (seg[id].ST - pt[i - 1]));
			ll d = (nxt == (int)occ[i - 1].size() - 1 ? 0 : pt[i] - seg[occ[i - 1][nxt + 1]].ND);
			dp[i][0] = min(dp[i][0], tmp + d);
			dp[i][1] = min(dp[i][1], tmp + 2 * d);
			nxt++;
		}
		//cout << dp[i][0] << " " << dp[i][1] << "\n";
	}
	cout << min(dp[n + 1][0], dp[n + 1][1]) << "\n";
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		test_case();
	}
}