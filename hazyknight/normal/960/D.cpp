#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

long long q,t,x,k;
long long sh1[70];
long long sh2[70];

void write(unsigned long long x)
{
    unsigned long long y = 10,len = 1;
    while (y <= x)
	{
		y *= 10;
		len++;
	}
    while (len--)
	{
		y /= 10;
		putchar(x / y + 48);
		x %= y;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> q;
	for (int i = 1;i <= q;i++)
	{
		cin >> t >> x;
		long long level = 0,xx = x;
		while (xx)
		{
			level++;
			xx >>= 1;
		}
		level--;
		if (t == 1)
		{
			cin >> k;
			sh1[level] = (sh1[level] + k % (1ll << level) + (1ll << level)) % (1ll << level);
		}
		else if (t == 2)
		{
			cin >> k;
			sh2[level] = (sh2[level] + k % (1ll << level) + (1ll << level)) % (1ll << level);
		}
		else
		{
			long long now = x;
			while (level)
			{
				write(now);
				putchar(' ');
				long long len = (1ll << (level - 1)),fa = (now >> 1),sum = (sh1[level] + sh2[level]) % (1ll << level);
				if (now & 1)
					now--,sum++;
				sum >>= 1;
				sum = (sum - sh1[level - 1] + len) % len;
				now = (fa - len + sum) % len + len;
				level--;
			}
			write(1);
			putchar('\n');
		}
	}
	return 0;
}