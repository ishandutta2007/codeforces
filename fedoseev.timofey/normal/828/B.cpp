#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	set <int> x, y;
	int cnt = 0;
	vector <vector <int>> g(n, vector <int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == 'W') {
				g[i][j] = 1;
			}
			else {
				g[i][j] = 2;
				x.insert(j);
				y.insert(i);
				++cnt;
			}
		}
	}
	int sz = 0;
	if (!x.empty()) {
		sz = max(sz, (*x.rbegin()) - (*x.begin()) + 1);
	}
	if (!y.empty()) {
		sz = max(sz, (*y.rbegin()) - (*y.begin()) + 1);
	}
	if (sz == 0) {
		cout << 1 << endl;
		return 0;
	}
	if (sz > n || sz > m) {
		cout << -1 << endl;
		return 0;
	}
	cout << sz * sz - cnt << endl;
}