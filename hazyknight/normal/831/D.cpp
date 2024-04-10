#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int n,k,p;
int a[1005];
int b[2005];

bool check(int tar)
{
	int top = 1;
	for (int i = 1;i <= n;i++)
	{
		bool ok = false;
		for (int j = top;j <= k;j++)
			if (abs(a[i] - b[j]) + abs(p - b[j]) <= tar)
			{
				ok = true;
				top = j + 1;
				break;
			}
		if (!ok)
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> k >> p;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= k;i++)
		cin >> b[i];
	sort(a + 1,a + n + 1);
	sort(b + 1,b + k + 1);
	int low = 0,high = 2000000000;
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		bool ret = check(mid);
		if (ret)
			high = mid;
		else
			low = mid + 1;
		if (low == high)
		{
			cout << low << endl;
			return 0;
		}
	}
	return 0;
}