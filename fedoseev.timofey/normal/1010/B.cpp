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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int query(int x) {
	cout << x << endl;
	int t;
	cin >> t;
	if (t == 0 || t == -2) exit(0);
	return t; 
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int m, n;
	cin >> m >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = query(1);
	}
	int l = 0, r = m + 1;
	int uk = 0;
	while (true) {
		int mid = (l + r) >> 1;
		int t = query(mid);
		t *= a[uk];
		++uk;
		if (uk == n) uk = 0;
		if (t == -1) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
}