#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

long long n,r,k;
long long a[500005];
long long b[500005];

bool check(long long tar)
{
	memcpy(b,a,sizeof(b));
	long long sum = 0,need = 0;
	for (int i = 1;i <= r;i++)
		sum += a[i];
	for (int i = r + 1;i <= n + r;i++)
	{
		if (i <= n)
			sum += a[i];
		if (i - r - r - 1 >= 1)
			sum -= a[i - r - r - 1];
		if (sum < tar)
		{
			need += tar - sum;
			a[min((long long)i,n)] += tar - sum;
			sum = tar;
		}
		if (need > k)
		{
			memcpy(a,b,sizeof(a));
			return false;
		}
	}
	memcpy(a,b,sizeof(a));
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> r >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	long long low = 0,high = 2000000000000000000ll;
	while (low < high)
	{
		long long mid = (low + high + 1) >> 1;
		if (check(mid))
			low = mid;
		else
			high = mid - 1; 
	}
	cout << low << endl;
	return 0;
}