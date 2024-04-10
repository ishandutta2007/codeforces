#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

long long a,b,n,ans;
long long cnt[100005];

int main()
{
	cin >> a >> b;
	if (b == 0)
	{
		cout << a * a << endl;
		for (int i = 1;i <= a;i++)
			cout << 'o';
		cout << endl;
		return 0;
	}
	if (b == 1)
	{
		cout << a * a - 1 << endl;
		for (int i = 1;i <= a;i++)
			cout << 'o';
		cout << 'x' << endl;
		return 0;
	}
	if (a == 0)
	{
		cout << -b * b << endl;
		for (int i = 1;i <= b;i++)
			cout << 'x';
		cout << endl;
		return 0;
	}
	ans = -(1ll << 60) - 1;
	for (long long i = 2;i <= min(a + 1,b);i++)
	{
		long long tmp = (a - i + 2) * (a - i + 2) + (i - 2) - (b % i) * (b / i + 1) * (b / i + 1) - (i - b % i) * (b / i) * (b / i);
		if (tmp > ans)
		{
			ans = tmp;
			n = i;
		}
	}
	int bb = b;
	while (bb)
	{
		for (int i = 1;i <= n;i++)
		{
			cnt[i]++,bb--;
			if (!bb)
				break;
		}
	}
	int space = n - 1;
	cout << ans << endl;
	for (int i = 1;i <= cnt[1];i++)
		cout << 'x';
	for (int i = 1;i <= space;i++)
	{
		long long cur = 0;
		if (i == 1)
			cur = a - space + 1;
		else
			cur = 1;
		for (int j = 1;j <= cur;j++)
			cout << 'o';
		for (int j = 1;j <= cnt[i + 1];j++)
			cout << 'x';
	}
	cout << endl;
	return 0;
}