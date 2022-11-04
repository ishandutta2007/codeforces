#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int n;
long long p[200005],last;
char c[200005];

long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> p[i] >> c[i];
		if (c[i] == 'P')
		{
			if (last)
			{
				long long tmp = last,reta = 0,retb = 0;
				for (int j = last + 1;j < i;j++)
					if (c[j] == 'R')
					{
						reta = max(reta,p[j] - p[tmp]);
						tmp = j;
					}
				reta = max(reta,p[i] - p[tmp]);
				ans += p[i] - p[last] - reta;
				tmp = last;
				for (int j = last + 1;j < i;j++)
					if (c[j] == 'B')
					{
						retb = max(retb,p[j] - p[tmp]);
						tmp = j;
					}
				retb = max(retb,p[i] - p[tmp]);
				ans += p[i] - p[last] - retb;
				ans += min(reta + retb,p[i] - p[last]);
			}
			else
			{
				for (int j = 1;j < i;j++)
					if (c[j] == 'R')
					{
						ans += p[i] - p[j];
						break;
					}
				for (int j = 1;j < i;j++)
					if (c[j] == 'B')
					{
						ans += p[i] - p[j];
						break;
					}
			}
			last = i;
		}
	}
	if (!last)
	{
		long long MIN = (1 << 30),MAX = 0;
		for (int i = 1;i <= n;i++)
			if (c[i] == 'R')
				MIN = min(MIN,p[i]),MAX = max(MAX,p[i]);
		if (MAX)
			ans += MAX - MIN;
		MIN = (1 << 30),MAX = 0;
		for (int i = 1;i <= n;i++)
			if (c[i] == 'B')
				MIN = min(MIN,p[i]),MAX = max(MAX,p[i]);
		if (MAX)
			ans += MAX - MIN;
		cout << ans << endl;
		return 0;
	}
	for (int i = n;i >= last + 1;i--)
		if (c[i] == 'R')
		{
			ans += p[i] - p[last];
			break;
		}
	for (int i = n;i >= last + 1;i--)
		if (c[i] == 'B')
		{
			ans += p[i] - p[last];
			break;
		}
	cout << ans << endl;
	return 0;
}