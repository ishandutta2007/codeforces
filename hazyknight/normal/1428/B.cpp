#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int T,n;

char s[MAXN];

bool vis[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,s + 1);
		for (int i = 1;i <= n;i++)
			vis[i] = 0;
		for (int i = 1;i <= n;i++)
			if (s[i] == '-')
				vis[i] = vis[i % n + 1] = 1;
		bool ok1 = 1,ok2 = 1;
		for (int i = 1;i <= n;i++)
		{
			if (s[i] == '<')
				ok1 = 0;
			if (s[i] == '>')
				ok2 = 0;
		}
		if (ok1 || ok2)
			printf("%d\n",n);
		else
		{
			int tot = 0;
			for (int i = 1;i <= n;i++)
				if (vis[i])
					tot++;
			printf("%d\n",tot);
		}
	}
	return 0;
}