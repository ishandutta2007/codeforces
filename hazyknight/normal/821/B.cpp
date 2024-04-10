#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

long long m,b;
long long ans;

int main()
{
	cin >> m >> b;
	for (long long x = 0;;x++)
		if (x % m == 0)
		{
			long long y = -x / m + b;
			if (y < 0)
				break;
			ans = max(ans,((x + y) * (x + 1) * (y + 1)) >> 1);
		}
	cout << ans << endl;
	return 0;
}