#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,q;

long long k;
long long a[200005];
long long sum[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	a[n + 1] = (1ll << 60) - 1;
	long long cur = 1,dec = 0;
	for (int i = 1;i <= q;i++)
	{
		cin >> k;
		int low = cur,high = n + 1;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			if (sum[mid] - sum[cur] + a[cur] - dec > k)
				high = mid;
			else
				low = mid + 1;
		}
		if (low == n + 1)
			cur = 1,dec = 0;
		else
		{
			dec = a[low] - (sum[low] - sum[cur] + a[cur] - dec - k);
			cur = low;
		}
		cout << n - cur + 1 << endl;
	}
	return 0;
}