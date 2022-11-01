#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 
using namespace std;

int main() {
	ll x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> x5 >> y5 >> x6 >> y6;

	x3 = max(x3, x1);
	x4 = min(x4, x2);
	y3 = max(y3, y1);
	y4 = min(y4, y2);
	if (x3 > x2 || x4 < x1 || y3 > y2 || y4 < y1) {
		x3 = 0LL;
		x4 = 0LL;
		y3 = 0LL;
		y4 = 0LL;
	}

	x5 = max(x5, x1);
	x6 = min(x6, x2);
	y5 = max(y5, y1);
	y6 = min(y6, y2);
	if (x5 > x2 || x6 < x1 || y5 > y2 || y6 < y1) {
		x5 = 0LL;
		x6 = 0LL;
		y5 = 0LL;
		y6 = 0LL;
	}

	ll left = max(x3, x5);
	ll top = min(y4, y6);
	ll right = min(x4, x6);
	ll bottom = max(y3, y5);

	ll width = right - left;
	ll height = top - bottom;

	ll s = 0LL;
	if (width > 0 && height > 0)
		s = width * height;

	if (((x4 - x3) * (y4 - y3) + (x6 - x5) * (y6 - y5) - s) == (x2 - x1) * (y2 - y1))
		cout << "NO";
	else
		cout << "YES";
	return 0;
}