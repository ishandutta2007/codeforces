#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>

using namespace std;

int n;
double a,MIN = 99999999,final_ans;
double each;

int main()
{
	cin >> n >> a;
	double each = ((double)n - 2) * 180.00 / (double)n;
	for (int i = 3;i <= n;i++)
	{
		double ans = (double)(i - 2) * (180.00 - each) / 2;
		if (fabs(a - ans) < MIN)
		{
			MIN = fabs(a - ans);
			final_ans = i;
		}
	}
	cout << final_ans << " 1 2" << endl;
	return 0;
}