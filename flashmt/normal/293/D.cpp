#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;
const int OFFSET = 1000100;
const double oo = 1e18;
const double EPS = 1e-8;

int n, x[100100], y[100100];
double yLow[2000200], yHigh[2000200];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i), x[i] += OFFSET, y[i] += OFFSET;
	x[n] = x[0]; y[n] = y[0];
	
	int xLow = x[0], xHigh = x[0];
	for (int i = 1; i < n; i++) 
	{
		xLow = min(xLow, x[i]);
		xHigh = max(xHigh, x[i]);
	}
	
	for (int i = xLow; i <= xHigh; i++) yLow[i] = oo, yHigh[i] = -oo;
	
	for (int i = 0; i < n; i++)
		if (x[i] == x[i + 1])
		{
			yLow[x[i]] = min(yLow[x[i]], 1.0 * min(y[i], y[i + 1]));
			yHigh[x[i]] = min(yHigh[x[i]], 1.0 * max(y[i], y[i + 1]));
		}
		else
		{
			double A = y[i] - y[i + 1], B = x[i + 1] - x[i], C = - A * x[i] - B * y[i];
			int xL = min(x[i], x[i + 1]), xR = max(x[i], x[i + 1]);
			for (int curX = xL; curX <= xR; curX++)
			{
				double curY = (- C - A * curX) / B;
				yLow[curX] = min(yLow[curX], curY);
				yHigh[curX] = max(yHigh[curX], curY);
			}
		}
	
	double sumX = 0, sumY = 0, sumXSqr = 0, sumYSqr = 0, point = 0;
	for (int curX = xLow; curX <= xHigh; curX++)
	{
		int ylow = int(yLow[curX] + 1 - EPS), yhigh = int(yHigh[curX] + EPS);
		point += yhigh - ylow + 1;
		sumX += (yhigh - ylow + 1.0) * curX;
		sumXSqr += (yhigh - ylow + 1.0) * curX * curX;
		sumY += (yhigh + ylow) * (yhigh - ylow + 1.0) / 2;
		sumYSqr += yhigh * (yhigh + 1.0) * (yhigh * 2 + 1) / 6 - (ylow - 1.0) * (ylow) * (ylow * 2 - 1) / 6;
	}
	
	double ans = (sumXSqr + sumYSqr) - (sumX * sumX + sumY * sumY) / point;
	ans /= (point - 1);
	printf("%.12lf\n", ans);
}