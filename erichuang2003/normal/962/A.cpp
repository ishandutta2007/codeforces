#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

long long n,su,sum;
long long a[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i],sum += a[i];
	for (int i = 1;i <= n;i++)
	{
		su += a[i];
		if (su * 2 >= sum)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}