#include <bits/stdc++.h>

using namespace std;

int n,k;
char s[200005];

int main()
{
	scanf("%d%d%s",&n,&k,s);
	int ok = 1;
	for (int i = 0;i < n;i++)
		if (s[i] != s[i % k])
		{
			if (s[i] > s[i % k])
				ok = 0;
			break;
		}
	if (ok)
	{
		printf("%d\n",n);
		for (int i = 0;i < n;i++)
			putchar(s[i % k]);
		putchar('\n');
		return 0;
	}
	int pos = k - 1;
	s[pos]++;
	while (s[pos] == '9' + 1)
	{
		s[pos - 1]++;
		s[pos] = '0';
		pos--;
	}
	printf("%d\n",n);
	for (int i = 0;i < n;i++)
		putchar(s[i % k]);
	putchar('\n');
	return 0;
}