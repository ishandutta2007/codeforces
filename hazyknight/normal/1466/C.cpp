#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n,ans;

char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		ans = 0;
		for (int i = 1;i <= n;i++)
			if ((i > 1 && s[i] == s[i - 1]) || (i > 2 && s[i] == s[i - 2]))
			{
				s[i] = '*';
				ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}