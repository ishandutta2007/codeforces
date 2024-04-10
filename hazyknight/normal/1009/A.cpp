#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 

using namespace std;

int n,m,ans;
int c[1005];
int a[1005];

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	for (int i = 1;i <= m;i++)
		cin >> a[i];
	int p = 1;
	for (int i = 1;i <= m;i++)
	{
		bool ok = false;
		while (p <= n)
		{
			if (c[p] <= a[i])
			{
				ok = true;
				break;
			}
			p++;
		}
		if (!ok)
			break;
		p++;
		ans++;
	}
	cout << ans << endl;
	return 0;
}