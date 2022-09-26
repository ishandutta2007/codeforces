#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int a[5005];
int f[5005];
int st[5005];
int ed[5005];

bool check[5005];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (!st[a[i]])
			st[a[i]] = i;
		ed[a[i]] = i;
	}
	for (int i = 1;i <= n;i++)
	{
		memset(check,0,sizeof(check));
		f[i] = f[i - 1];
		if (i != ed[a[i]])
			continue;
		int s = 5005,cxor = 0;
		for (int j = i;j >= 1;j--)
		{
			if (ed[a[j]] > i)
				break;
			s = min(s,st[a[j]]);
			if (!check[a[j]])
			{
				check[a[j]] = true;
				cxor ^= a[j];
			}
			if (s == j)
				f[i] = max(f[i],f[j - 1] + cxor);
		}
	}
	cout << f[n] << endl;
	return 0;
}