#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int T,n;
int a[MAXN];
int b[MAXN];

bool ok(int v)
{
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		int L = max(0,v - a[i] - 1),R = b[i];
		if (sum >= L && sum <= R)
			sum++;
		if (sum == v)
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d%d",&a[i],&b[i]);
		int low = 0,high = n;
		while (low < high)
		{
			int mid = low + high + 1 >> 1;
			if (ok(mid))
				low = mid;
			else
				high = mid - 1;
		}
		printf("%d\n",low);
	}
	return 0;
}