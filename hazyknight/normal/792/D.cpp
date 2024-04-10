#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

long long n,q;
long long now;

string s;

long long cnt2(long long a)
{
	int ret = 0;
	while (a % 2 == 0)
		ret++,a /= 2;
	return ret;
}

int main()
{
	cin >> n >> q;
	for (int i = 1;i <= q;i++)
	{
		cin >> now >> s;
		for (int j = 0;j < s.size();j++)
		{
			if (s[j] == 'U')
			{
				if (now == (n + 1) >> 1)
					continue;
				else
				{
					long long cnt = cnt2(now),l = now - (1ll << cnt),r = now + (1ll << cnt);
					if (l > 0 && l <= n && cnt2(l) == cnt + 1)
						now = l;
					else
						now = r;
				}
			}
			if (s[j] == 'L')
			{
				if (now % 2 != 0)
					continue;
				long long cnt = cnt2(now),len = (1ll << (cnt - 1));
				now = now - len;
			}
			if (s[j] == 'R')
			{
				if (now % 2 != 0)
					continue;
				long long cnt = cnt2(now),len = (1ll << (cnt - 1));
				now = now + len;
			}
		}
		cout << now << endl;
	}
	return 0;
}