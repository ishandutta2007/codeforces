#include <bits/stdc++.h>

using namespace std;

long long k;
int c[15];
char s[11] = {' ','c','o','d','e','f','o','r','c','e','s'};

int main()
{
	cin >> k;
	long long t = 1;
	for (int i = 1;i <= 10;i++)
		c[i] = 1;
	while (t < k)
	{
		for (int i = 1;i <= 10 && t < k;i++)
		{
			t = t / c[i] * (c[i] + 1);
			c[i]++;
		}
	}
	for (int i = 1;i <= 10;i++)
		while (c[i]--)
			putchar(s[i]);
	putchar('\n');
	return 0;
}