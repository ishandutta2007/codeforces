#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 505;

int T,n,m;
int a[MAXN << 1];
int b[MAXN << 1];

bitset<500001> f[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int tota = 0,totb = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			tota += a[i];
		}
		scanf("%d",&m);
		for (int i = 1;i <= m;i++)
		{
			scanf("%d",&b[i]);
			totb += b[i];
		}
		if (n != m || (tota & 1) || (totb & 1))
		{
			puts("No");
			continue;
		}
		tota /= 2;
		totb /= 2;
		vector<int> xadd,xsub,yadd,ysub;
		f[0][0] = 1;
		for (int i = 1;i <= n;i++)
			f[i] = f[i - 1] | (f[i - 1] << a[i]);
		if (!f[n][tota])
		{
			puts("No");
			continue;
		}
		for (int i = n;i >= 1;i--)
			if (f[i - 1][tota])
				xsub.push_back(a[i]);
			else
			{
				xadd.push_back(a[i]);
				tota -= a[i];
			}
		f[0][0] = 1;
		for (int i = 1;i <= n;i++)
			f[i] = f[i - 1] | (f[i - 1] << b[i]);
		if (!f[n][totb])
		{
			puts("No");
			continue;
		}
		for (int i = n;i >= 1;i--)
			if (f[i - 1][totb])
				ysub.push_back(b[i]);
			else
			{
				yadd.push_back(b[i]);
				totb -= b[i];
			}
		sort(xadd.begin(),xadd.end());
		sort(xsub.begin(),xsub.end());
		sort(yadd.begin(),yadd.end());
		sort(ysub.begin(),ysub.end());
		puts("Yes");
		if (xadd.size() <= yadd.size())
		{
			reverse(yadd.begin(),yadd.end());
			reverse(ysub.begin(),ysub.end());
			int X = 0,Y = 0;
			for (int i = 1,side = 0;i <= n * 2;i++,side ^= 1)
			{
				if (!side)
				{
					if (xadd.size())
					{
						X += xadd.back();
						xadd.pop_back();
					}
					else
					{
						X -= xsub.back();
						xsub.pop_back();
					}
				}
				else
				{
					if (yadd.size())
					{
						Y += yadd.back();
						yadd.pop_back();
					}
					else
					{
						Y -= ysub.back();
						ysub.pop_back();
					}
				}
				printf("%d %d\n",X,Y);
			}
		}
		else
		{
			reverse(xadd.begin(),xadd.end());
			reverse(xsub.begin(),xsub.end());
			int X = 0,Y = 0;
			for (int i = 1,side = 0;i <= n * 2;i++,side ^= 1)
			{
				if (side)
				{
					if (xadd.size())
					{
						X += xadd.back();
						xadd.pop_back();
					}
					else
					{
						X -= xsub.back();
						xsub.pop_back();
					}
				}
				else
				{
					if (yadd.size())
					{
						Y += yadd.back();
						yadd.pop_back();
					}
					else
					{
						Y -= ysub.back();
						ysub.pop_back();
					}
				}
				printf("%d %d\n",X,Y);
			}
		}
	}
	return 0;
}