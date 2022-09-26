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

int t,n,x,y,d;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> x >> y >> d;
		if (abs(x - y) % d == 0)
		{
			cout << abs(x - y) / d << endl;
			continue;
		}
		int ans = 2147483647;
		if ((y - 1) % d == 0)
			ans = min(ans,(x - 2) / d + 1 + (y - 1) / d);
		if ((n - y) % d == 0)
			ans = min(ans,(n - x - 1) / d + 1 + (n - y) / d);
		if (ans == 2147483647)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}