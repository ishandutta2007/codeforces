#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, x[111], xx[111], y[111], v[111];

double getIntersect(int y, int x, int yy, int xx, int curY)
{
	long long A = y - yy, B = xx - x, C = - x * A - y * B;
	return (-1.0 * C - B * curY) / A;
}

int solve(int hl, int hr, int direction)
{
	int res = 0;
	for (int reflex = 1; reflex <= n; reflex++)
	{
		int hTarget = hr + 200 * (reflex / 2) * direction;
		if (reflex % 2)
			hTarget += (direction == 1) * 200 - hr * 2;
			
		int actualY = (direction == 1) * 100, curY = actualY, touch[111] = {0}, ok, point = 0;
		for (int i = 0; i < reflex; i++) 
		{
			double curX = getIntersect(hl, 0, hTarget, 100000, curY);
			ok = 0;
			for (int j = 0; j < n; j++)
				if (curX >= x[j] && curX <= xx[j] && actualY == y[j] && !touch[j])
					touch[j] = 1, ok = 1, point += v[j];
			
			if (!ok) break;
				
			curY += direction * 100;
			actualY = 100 - actualY;
		}
		
		if (ok)	res = max(res, point);
	}
	return res;
}

int main()
{
	int hl, hr;
	string s;
	cin >> hl >> hr >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> s >> x[i] >> xx[i];
		y[i] = (s == "T") * 100;
	}
	
	cout << max(solve(hl, hr, -1), solve(hl, hr, 1)) << endl;
}