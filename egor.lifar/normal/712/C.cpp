#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int main() {
	int x, y;
	cin >> x >> y;
	if (x < y) {
		swap(x, y);
	}
	if (x == y) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	int a = y, b = y, c = y;
	while (a != x || b != x || c != x) {
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(), v.end());
		a = v[0];
		b = v[1];
		c = v[2];
		a = min(x, b + c - 1);
		ans++;
	}
	cout << ans << endl;

	return 0;
}