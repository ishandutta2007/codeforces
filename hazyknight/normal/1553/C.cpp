#include <bits/stdc++.h>

using namespace std;

int T,n;
int a[10];
int b[10];

string s,t;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> s;
		for (int i = 0;i < 10;i++)
		{
			a[i] = s[i] - '0';
			if (a[i] == '?' - '0')
				a[i] = -1;
		}
		int ans = 10;
		for (int i = 0;i < (1 << 10);i++)
		{
			bool ok = 1;
			for (int j = 0;j < 10;j++)
			{
				b[j] = (i >> j & 1);
				if (a[j] != -1 && a[j] != b[j])
					ok = 0;
			}
			if (!ok)
				continue;
			int sum1 = 0,sum2 = 0,l1 = 5,l2 = 5;
			for (int j = 0;j < 10;j++)
			{
				if (j & 1)
					sum1 += b[j],l1--;
				else
					sum2 += b[j],l2--;
				if (sum1 + l1 < sum2 || sum2 + l2 < sum1)
				{
					ans = min(ans,j + 1);
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}