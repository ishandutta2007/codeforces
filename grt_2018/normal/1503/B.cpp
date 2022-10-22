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

const int nax = 110;
int n;

int nxt() {
	int a;
	cin >> a;
	return a;
}

void ask(int x, int y, int c) {
	cout << c << " " << x << " " << y << endl;
}

vector<pi>even, odd;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if((i + j) & 1) {
				odd.PB({i,j});
			} else {
				even.PB({i,j});
			}
		}
	}
	while((int)even.size() > 0 && (int)odd.size() > 0) {
		int c = nxt();
		if(c == 1) {
			int x = even.back().ST;
			int y = even.back().ND;
			ask(x, y, 2);
			even.pop_back();
		} else {
			int x = odd.back().ST;
			int y = odd.back().ND;
			ask(x, y, 1);
			odd.pop_back();
		}
	}
	if((int)odd.size() == 0) {
		while(true) {
			int c = nxt();
			if(c == 2) {
				int x = even.back().ST;
				int y = even.back().ND;
				ask(x, y, 3);
				even.pop_back();
			} else {
				int x = even.back().ST;
				int y = even.back().ND;
				ask(x, y, 2);
				even.pop_back();
			}
			if((int)even.size() == 0) break;
		}
	} else {
		swap(even, odd);
		while(true) {
			int c = nxt();
			if(c == 1) {
				int x = even.back().ST;
				int y = even.back().ND;
				ask(x, y, 3);
				even.pop_back();
			} else {
				int x = even.back().ST;
				int y = even.back().ND;
				ask(x, y, 1);
				even.pop_back();
			}
			if((int)even.size() == 0) break;
		}
	}
	
}