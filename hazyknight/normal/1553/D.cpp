#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n,m;

char s[MAXN];
char t[MAXN];

bool work(int pos)
{
	if (!pos)
		return 0;
	if (m == 1)
		return (n - pos) % 2 == 0;
	int lst = pos,p = 2;
	for (int i = pos + 1;i <= n;i++)
	{
		if (s[i] == t[p] && ((i - lst) & 1))
		{
			lst = i;
			p++;
		}
		if (p > m)
			return (n - i) % 2 == 0;
	}
	return 0;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",s + 1,t + 1);
		n = strlen(s + 1);
		m = strlen(t + 1);
		int odd = 0,even = 0;
		for (int i = 1;i <= n;i++)
			if (s[i] == t[1])
			{
				if (!odd && (i & 1))
					odd = i;
				if (!even && (~i & 1))
					even = i;
			}
		puts(work(odd) || work(even) ? "YES" : "NO");
	}
	return 0;
}