#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 

using namespace std;

long long k,d,t;

double ans;

int main()
{
	cin >> k >> d >> t;
	t <<= 1;
	long long p = ((k - 1) / d + 1) * d;
	long long turn = (k << 1) + (p - k);
	ans += t / turn * p;
	t %= turn;
	if (t <= (k << 1))
		printf("%.10lf\n",ans + (double)t / 2.0000000000);
	else
	{
		t -= (k << 1);
		printf("%.10lf\n",ans + k + t);
	}
	return 0;
}