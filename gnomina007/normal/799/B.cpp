#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;
long long n, i, j, t[4], p[200005], p1[200005], p2[200005], p3[200005], c1, c2, c3, m, ct[200005], t1, a, km, used[200005];
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> p1[i];

	}
	for (i = 0; i < n; i++)
	{
		cin >> p2[i];

	}
	for (i = 0; i < n; i++)
	{
		cin >> p3[i];

	}
	for (i = 0; i < n; i++)
	{
		p[i] = p1[i] * 16 + p2[i] * 4 + p3[i];
	}
	sort(p, p + n);
	reverse(p, p + n);
	t[1] = n - 1;
	t[2] = n - 1;
	t[3] = n - 1;
	t1 = n - 1;
	for (j = 1; j < 4; j++)
	{
		if (t[j] == t1)
		{
			a = 0;
			km = t1;
			while (a == 0)
			{
				if (km >= 0)
				{
					if ((p[km] % 16) / 4 != j)
					{
						if ((p[km] % 16) % 4 != j)
						{
							km--;
							a--;
						}
					}
				}
				a++;
			}
			t[j] = km;
		}
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin>>ct[i];
	}
	for (i = 0; i < m; i++)
	{
		t1 = t[ct[i]];
		if (t1 != -1)
		{
			used[t1] = 1;
			cout << p[t1] / 16 << ' ';
			for (j = 1; j < 4; j++)
			{
				if (t[j] == t1)
				{
					a = 0;
					km = t1 - 1;
					while (a == 0)
					{
						if (km >= 0)
						{
							if (used[km] == 1)
							{
								km--;
								a--;
							}
							else
							{
								if ((p[km] % 16) / 4 != j)
								{
									if ((p[km] % 16) % 4 != j)
									{
										km--;
										a--;
									}
								}
							}
						}
						a++;
					}
					t[j] = km;
				}
			}
		}
		else
		{
			cout << -1<<' ';
		}
	}
}