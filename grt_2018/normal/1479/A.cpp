#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

int n;
const int INF = 1e9;

int qr(int x) {
	if(x == 0 || x == n + 1) {
		return INF;
	}
	cout << "? " << x << endl;
	int y;
	cin >> y;
	return y;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int l = 1, r = n, mid;
	for(int i = 0; i < 30; ++i) {
		if(l >= r) break;
		mid = (l + r)/2;
		int x = qr(mid);
		int y = qr(mid + 1);
		if(x < y) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << "! " << r << endl;
	
}