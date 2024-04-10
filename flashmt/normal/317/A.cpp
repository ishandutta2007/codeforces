#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int calc(long long x, long long y, long long m)
{
	if (x >= m || y >= m) return 0;
	for (int i = 1; i < 1000; i++)
	{
		x += y;
		y = x - y;
		if (y > x) swap(x, y);
		if (x >= m) return i;
	}
	return -1;
}

int main()
{
	long long x, y, m;
	cin >> x >> y >> m;
	if (x < y) swap(x, y);
	
	if (x >= m) 
	{
		puts("0"); return 0;
	}
	
	if (x + y > 0) cout << calc(x, y, m) << endl;
	else
		if (x <= 0) puts("-1");
		else
		{
			long long q = (-y + x - 1) / x;
			y = (-y) % x;
			if (y) y = x - y;
			cout << q + calc(x, y, m);
		}
}