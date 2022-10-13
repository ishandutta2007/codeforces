#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int x, y, n;

long long Labs(long long x)
{
	return x < 0 ? -x : x;
}

void update(long long xx, long long yy, long long &ansx, long long &ansy)
{
	if (y < 0 || Labs(xx * y - x * yy) * ansy < Labs(ansx * y - x * ansy) * yy)
	{
		ansx = xx;
		ansy = yy;
	}
}

int main()
{
	long long ansx, ansy = -1;
	cin >> x >> y >> n;
	for (int yy = 1; yy <= n; yy++)
	{
		long long xx = 1LL * x * yy / y;
		update(xx, yy, ansx, ansy);
		update(xx + 1, yy, ansx, ansy);
	}
	cout << ansx << '/' << ansy << endl;
}