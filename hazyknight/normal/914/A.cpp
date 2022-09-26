#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cmath>

using namespace std;

int n,a,ans = -1000001;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		if (a < 0 || sqrt(a) - (int)sqrt(a) > 1e-6)
			ans = max(ans,a);
	}
	cout << ans << endl;
	return 0;
}