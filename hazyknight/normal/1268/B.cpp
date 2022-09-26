#include <bits/stdc++.h>

using namespace std;

int n;
int a[300005];

int main()
{
	scanf("%d",&n);
	long long sum[2] = {0};
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		sum[i & 1] += a >> 1;
		sum[~i & 1] += (a + 1) >> 1;
	}
	printf("%lld\n",min(sum[0],sum[1]));
	return 0;
}