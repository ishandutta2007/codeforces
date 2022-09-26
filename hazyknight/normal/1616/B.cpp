#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n;

char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,s + 1);
		if (n == 1 || s[1] == s[2])
		{
			printf("%c%c\n",s[1],s[1]);
			continue;
		}
		bool ok = 0;
		for (int i = 1;i < n;i++)
			if (s[i] < s[i + 1])
			{
				for (int j = 1;j <= i;j++)
					printf("%c",s[j]);
				for (int j = i;j >= 1;j--)
					printf("%c",s[j]);
				printf("\n");
				ok = 1;
				break;
			}
		if (!ok)
		{
			for (int j = 1;j <= n;j++)
				printf("%c",s[j]);
			for (int j = n;j >= 1;j--)
				printf("%c",s[j]);
			printf("\n");
		}
	}
	return 0;
}