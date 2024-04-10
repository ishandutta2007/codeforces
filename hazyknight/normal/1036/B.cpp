#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main()
{
	int q;
	long long n,m,k;
	cin >> q;
	for (int i = 1;i <= q;i++)
	{
		cin >> n >> m >> k;
		if (n > m)
			swap(n,m);
		long long ans = 0,step = 0;
		ans += n;
		step += n;
		ans += (m - n) / 2 * 2;
		step += (m - n) / 2 * 2;
		if (((m - n) & 1))
		{
			step++;
			if (step > k)
			{
				cout << -1 << endl;
				continue;
			}
			ans += k - step;
		}
		else
		{
			if (step > k)
			{
				cout << -1 << endl;
				continue;
			}
			if (k - step == 1)
			{
				cout << ans - 1 << endl;
				continue;
			}
			if ((k - step) & 1)
				ans += (k - step - 3) + 1;
			else
				ans += k - step;
		}
		cout << ans << endl;
	}
	return 0;
}