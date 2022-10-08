#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

int main() {
	long long x, y, m;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> x >> y >> m;
	if (max(x, y) >= m) {
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;

	if (x <= 0 && y <= 0) {
		if (max(x, y) >= m)
			cout << 0 << endl;
		else
			cout << -1 << endl;
		return 0;
	}

	if (x < y)
		swap(x, y);
	ans = 0;
	if (y < 0) {
		if (m <= 0) {
			if (m <= y) {
				cout << 0 << endl;
				return 0;
			}
			long long d = m - y;
			cout << (d + x - 1) / x << endl;
			return 0;
		}
		ans = (-y) / x;
		y += x * ans;
	}
	
	while (max(x, y) < m) {
		if (x < y)
			swap(x, y);
		y = x + y;
		ans++;
	}

	cout << ans << endl;

	return 0;
}