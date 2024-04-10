#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		ll p,q;
		scanf("%lld%lld",&p,&q);
		if (p % q != 0)
		{
			printf("%lld\n",p);
			continue;
		}
		ll ans = 0;
		for (int i = 2;i * i <= q;i++)
			if (q % i == 0)
			{
				ll t = 1;
				while (q % i == 0)
				{
					q /= i;
					t *= i;
				}
				ll tmp = p;
				while (tmp % t == 0)
					tmp /= i;
				ans = max(ans,tmp);
			}
		if (q > 1)
		{
			ll tmp = p;
			while (tmp % q == 0)
				tmp /= q;
			ans = max(ans,tmp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}