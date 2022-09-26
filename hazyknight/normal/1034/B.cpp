#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> 

using namespace std;

long long x,y;
long long ans;

int main()
{
	cin >> x >> y;
	ans = x * y;
	if (x > y)
		swap(x,y);
	if (x == 1)
	{
		if (y % 6 == 1 || y % 6 == 5)
			ans--;
		if (y % 6 == 2 || y % 6 == 4)
			ans -= 2;
		if (y % 6 == 3)
			ans -= 3;
	}
	if (x == 2)
	{
		if (y == 2)
			ans -= 4;
		if (y == 1 || y == 3 || y == 7)
			ans -= 2;
	}
	if (x > 2)
	{
		if ((x * y) & 1)
			ans--;
	}
	cout << ans << endl;
	return 0;
}