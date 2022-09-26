#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int n;
int a[100005];
int MIN = (1 << 30);

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		MIN = min(MIN,a[i]);
	}
	int last = 0,ans = n + 1;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] == MIN)
		{
			if (!last)
				last = i;
			else
			{
				ans = min(ans,i - last);
				last = i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}