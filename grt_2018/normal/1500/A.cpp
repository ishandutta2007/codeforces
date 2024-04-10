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

const int nax = 200 * 1000 + 10, mx = 5000000 + 10;
int n;
int a[nax];
vi was[mx];
pi pre[mx];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		was[a[i]].PB(i);
	}
	int p = -1;
	for(int i = 1; i <= 2500000; ++i) {
		if((int)was[i].size() >= 4) {
			cout << "YES\n";
			for(int j = 0; j < 4; ++j) cout << was[i][j] << " ";
			return 0;
		}
		if((int)was[i].size() >= 2) {
			if(p == -1) p = i;
			else {
				cout << "YES\n";
				cout << was[p][0] << " " << was[i][0] << " " << was[p][1] << " " << was[i][1];
				return 0;
			}
		}
	}
	//int cnt = 0;
	if(p != -1) pre[2 * p] = {was[p][0], was[p][1]};
	for(int i = 1; i <= n; ++i) {
		if(a[i] == p && i != was[p][0]) {
			continue;
		}
		for(int j = i + 1; j <= n; ++j) {
			if(p != -1 && a[j] == p && j != was[p][0]) continue;
			if(pre[a[i] + a[j]].ST != 0) {
				cout << "YES\n" << i << " " << j << " " << pre[a[i] + a[j]].ST << " " << pre[a[i] + a[j]].ND;
				return 0;
			}
			pre[a[i] + a[j]] = {i, j};
		}
	}
	cout << "NO";
	
}