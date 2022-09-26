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

long long n,ans;

int main()
{
	cin >> n;
	while (n)
	{
		long long D = 0;
		for (long long i = 2;i * i <= n;i++)
			if (n % i == 0)
			{
				D = i;
				break;
			}
		if (!D)
			D = n;
		if (D == 2)
		{
			ans += n / 2;
			break;
		}
		n -= D;
		ans++;
	}
	cout << ans << endl;
	return 0;
}