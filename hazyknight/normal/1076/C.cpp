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
#include <iomanip>

using namespace std;

const double eps = 1e-10;

int T;

double n;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		double low = 0,high = sqrt(n);
		while (high - low > eps)
		{
			double mid = (low + high) / 2.0;
			if (mid * (n - mid) < n)
				low = mid + eps;
			else
				high = mid;
		}
		if (fabs(low * (n - low) - n) > 1e-6)
			cout << "N" << endl;
		else
			cout << fixed << setprecision(10) << "Y " << low << ' ' << n - low << endl;
	}
	return 0;
}