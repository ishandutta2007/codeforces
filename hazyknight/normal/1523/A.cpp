#include <bits/stdc++.h>

using namespace std;

int T,n,m;

char s[1005];
char t[1005];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%s",&n,&m,s + 1);
		s[0] = '0';
		s[n + 1] = '0';
		for (int i = 1;i <= min(n,m);i++)
		{
			for (int j = 1;j <= n;j++)
				t[j] = '0';
			for (int j = 1;j <= n;j++)
				if (s[j - 1] + s[j + 1] == '0' + '1')
					t[j] = '1';
			for (int j = 1;j <= n;j++)
				if (t[j] == '1')
					s[j] = '1';
		}
		s[n + 1] = '\0';
		puts(s + 1);
	}
	return 0;
}