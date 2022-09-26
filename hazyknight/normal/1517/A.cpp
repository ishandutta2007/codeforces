#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		ll n;
		scanf("%lld",&n);
		if (n % 2050 != 0)
		{
			puts("-1");
			continue;
		}
		n /= 2050;
		int sum = 0;
		while (n)
		{
			sum += n % 10;
			n /= 10;
		}
		printf("%d\n",sum);
	}
	return 0;
}