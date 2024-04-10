#include<bits/stdc++.h>
using namespace std;

int main() {
	int x1, x2, y1, y2; // coordinates of the first square
	{
		int a, b, c, d, e, f, g, h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;
		x1 = min(min(a, c), min(e, g));
		x2 = max(max(a, c), max(e, g));
		y1 = min(min(b, d), min(f, h));
		y2 = max(max(b, d), max(f, h));
	}

	int r; //radius of the second square
	{
		int x0, y0;

		int a, b, c, d, e, f, g, h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;
		x0 = (a + c + e + g) / 4;
		y0 = (b + d + f + h) / 4;
		r = max(max(a,c), max(e,g)) - x0;

		x1 -= x0, y1 -= y0, x2 -= x0, y2 -= y0;
		x0 = 0, y0 = 0;
	}

	int px = min(abs(x1), abs(x2));
	if (x1 * x2 <= 0) px = 0;

	int py = min(abs(y1), abs(y2));
	if (y1 * y2 <= 0) py = 0;

	bool intersects = (px + py <= r);
	cout << (intersects ? "Yes" : "No") << '\n';

	return 0;
}