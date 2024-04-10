#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

long long n,ans;
long long pow10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000ll};
long long map[10] = {5,50,500,5000,50000,500000,5000000,50000000,500000000,5000000000ll};
long long tar[10] = {0,9,99,999,9999,99999,999999,9999999,99999999,999999999ll};

int main()
{
	cin >> n;
	if (n == 2)
	{
		cout << 1 << endl;
		return 0;
	}
	else if (n == 3)
	{
		cout << 3 << endl;
		return 0;
	}
	else if (n == 4)
	{
		cout << 6 << endl;
		return 0;
	}
	long long MAX = 0;
	for (int i = 0;i <= 10;i++)
		if (map[i] > n)
		{
			MAX = i;
			break;
		}
	for (int i = 0;i < 9;i++)
	{
		long long to = tar[MAX] + pow10[MAX] * i;
		if (to <= n)
			ans += to / 2;
		else if (to <= n + n - 1)
			ans += (n + n - 1 - to) / 2 + 1;
	}
	cout << ans << endl;
	return 0;
}