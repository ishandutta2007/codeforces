#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int getans2(int p)
{
	int ret = p,t = p;
	for (int i = 2;i * i <= p;i++)
	{
		if (p % i == 0)
			ret = min(ret,t - i + 1);
		while (p % i == 0)
			p /= i;
	}
	if (p != 1 && t != p)
		ret = min(ret,t - p + 1);
	return ret;
}

int pre[1000005];

int getans(int p)
{
	int ret = p,t = p;
	for (int i = 2;i * i <= p;i++)
	{
		if (p % i == 0)
			ret = min(ret,t - i + 1);
		while (p % i == 0)
			p /= i;
	}
	if (p != 1 && t != p)
		ret = min(ret,t - p + 1);
	int res = t - 1;
	for (int i = ret;i <= t;i++)
		res = min(res,pre[i]);
	return res;
}

int n;

int main()
{
	cin >> n;
	for (int i = 2;i <= n;i++)
		pre[i] = getans2(i);
	cout << getans(n) << endl;
	return 0;
}