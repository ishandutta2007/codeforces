#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

long long n,l;
long long c[35];
long long cnt,ans = (1ll << 62);

int main()
{
	for (int i = 0;i <= 30;i++)
		c[i] = (1ll << 62);
	cin >> n >> l;
	for (int i = 0;i < n;i++)
		cin >> c[i];
	for (int i = 1;i <= 30;i++)
		c[i] = min(c[i],c[i - 1] << 1);
	for (int i = 29;i >= 0;i--)
		c[i] = min(c[i],c[i + 1]);
	for (int i = 30;i >= 0;i--)
	{
		if (l >= (1ll << i))
		{
			l -= (1ll << i);
			cnt += c[i];
		}
		else
			ans = min(ans,cnt + c[i]);
	}
	cout << min(ans,cnt) << endl;
	return 0;
}