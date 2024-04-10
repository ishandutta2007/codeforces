#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>

using namespace std;

int xa,ya,xb,yb,xc,yc;

int main()
{
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	if (xa > xb)
	{
		swap(xa,xb);
		swap(ya,yb);
	}
	if (xa > xc)
	{
		swap(xa,xc);
		swap(ya,yc);
	}
	if (xb > xc)
	{
		swap(xb,xc);
		swap(yb,yc);
	}
	if (ya <= yb)
	{
		if (yb <= yc)
		{
			cout << xc - xa + yc - ya + 1 << endl;
			for (int i = xa;i <= xb;i++)
				cout << i << ' ' << ya << endl;
			for (int i = ya + 1;i <= yb;i++)
				cout << xb << ' ' << i << endl;
			for (int i = xb + 1;i <= xc;i++)
				cout << i << ' ' << yb << endl;
			for (int i = yb + 1;i <= yc;i++)
				cout << xc << ' ' << i << endl;
		}
		else if (yc >= ya)
		{
			cout << xc - xa + yb - ya + 1 << endl;
			for (int i = xa;i <= xb;i++)
				cout << i << ' ' << ya << endl;
			for (int i = ya + 1;i <= yb;i++)
				cout << xb << ' ' << i << endl;
			for (int i = xb + 1;i <= xc;i++)
				cout << i << ' ' << yc << endl;
		}
		else
		{
			cout << xc - xa + yb - yc + 1 << endl;
			for (int i = xa;i <= xb;i++)
				cout << i << ' ' << ya << endl;
			for (int i = ya + 1;i <= yb;i++)
				cout << xb << ' ' << i << endl;
			for (int i = ya - 1;i >= yc;i--)
				cout << xb << ' ' << i << endl;
			for (int i = xb + 1;i <= xc;i++)
				cout << i << ' ' << yc << endl;
		}
	}
	else
	{
		ya = -ya;
		yb = -yb;
		yc = -yc;
		if (yb <= yc)
		{
			cout << xc - xa + yc - ya + 1 << endl;
			for (int i = xa;i <= xb;i++)
				cout << i << ' ' << -ya << endl;
			for (int i = ya + 1;i <= yb;i++)
				cout << xb << ' ' << -i << endl;
			for (int i = xb + 1;i <= xc;i++)
				cout << i << ' ' << -yb << endl;
			for (int i = yb + 1;i <= yc;i++)
				cout << xc << ' ' << -i << endl;
		}
		else if (yc >= ya)
		{
			cout << xc - xa + yb - ya + 1 << endl;
			for (int i = xa;i <= xb;i++)
				cout << i << ' ' << -ya << endl;
			for (int i = ya + 1;i <= yb;i++)
				cout << xb << ' ' << -i << endl;
			for (int i = xb + 1;i <= xc;i++)
				cout << i << ' ' << -yc << endl;
		}
		else
		{
			cout << xc - xa + yb - yc + 1 << endl;
			for (int i = xa;i <= xb;i++)
				cout << i << ' ' << -ya << endl;
			for (int i = ya + 1;i <= yb;i++)
				cout << xb << ' ' << -i << endl;
			for (int i = ya - 1;i >= yc;i--)
				cout << xb << ' ' << -i << endl;
			for (int i = xb + 1;i <= xc;i++)
				cout << i << ' ' << -yc << endl;
		}
	}
	return 0;
}