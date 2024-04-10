#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, k, res, ad[11111], rr[11111], xr[11111], a[11111], pos, msk, aa, pp;
int qand(int x, int y)
{
	printf("and %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &res);
	return res;
}
int qor(int x, int y)
{
	printf("or %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &res);
	return res;
}
void fin(int r)
{
	printf("finish %d\n", r);
	fflush(stdout);
}
int main()
{
	test = 1;
	while(test--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 2; i <= n; i++)
		{
			ad[i] = qand(1, i);
			rr[i] = qor(1, i);
			xr[i] = rr[i] - ad[i];
		}
		for (int i = 0; i < 30; i++)
		{
			pos = -1;
			for (int j = 2; j <= n; j++)
			{
				if (xr[j] & (1 << i));
				else 
				{
					pos = j;
					break;
				}
			}
			if (!~pos)
			{
				msk |= (1 << i);
			}
			else
			{
				if (ad[pos] & (1 << i)) a[1] |= (1 << i);
				for (int j = 2; j <= n; j++) a[j] |= (((((ad[pos] ^ xr[j]) >> i) & 1)) << i);
			}
		}
		aa = qand(2, 3);
		for (int i = 0; i < 30; i++)
		{
			if (msk & (1 << i))
			{
				if (aa & (1 << i)) 
				{
					for (int j = 2; j <= n; j++) a[j] |= (1 << i);
				}
				else
				{
					a[1] |= (1 << i);
				}
			}
		}
		sort(a + 1, a + n + 1);
		fin(a[k]);
	}
	return Accepted;
}