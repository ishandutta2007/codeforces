#include <bits/stdc++.h>
using namespace std;

int main()
{
	double rr;
	cin >> rr;
	
	for (int a = 1; a <= 10; a++)
		for (int h = 1; h <= 10; h++)
		{
			double r = a / 2.0 * h / sqrt(a * a / 4.0 + h * h);
			if (fabs(r - rr) < 1e-6)
			{
				cout << a << ' ' << h << endl;
				return 0;
			}
		}
}