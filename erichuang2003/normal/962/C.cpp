#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

string s;

int n,ans = (1 << 30) - 1;

int main()
{
	cin >> s;
	int n = s.size();
	for (int i = 1;i < (1 << n);i++)
	{
		int now = 0,cur = n,flag = 0;
		for (int j = 0;j < n;j++)
			if (i & (1 << j))
			{
				if (cur == n && s[j] == '0')
				{
					flag = 1;
					break;
				}
				cur--;
				now = now * 10 + s[j] - '0';
			}
		if (flag)
			continue;
		bool ok = false;
		for (int j = 1;j * j <= now;j++)
			if (j * j == now)
			{
				ok = true;
				break;
			}
		if (ok)
			ans = min(ans,cur);
	}
	if (ans == (1 << 30) - 1)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}