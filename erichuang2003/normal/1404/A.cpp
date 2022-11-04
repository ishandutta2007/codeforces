#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int T,n,k;

char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%s",&n,&k,s + 1);
		bool ok = 1;
		for (int i = k + 1;i <= n;i++)
		{
			if (s[i - k] == '?')
				continue;
			if (s[i] == '?')
				s[i] = s[i - k];
			else if (s[i] != s[i - k])
				ok = 0;
		}
		for (int i = n - k;i >= 1;i--)
		{
			if (s[i + k] == '?')
				continue;
			if (s[i] == '?')
				s[i] = s[i + k];
			else if (s[i] != s[i + k])
				ok = 0;
		}
		if (!ok)
		{
			puts("NO");
			continue;
		}
		int cnt[2] = {0};
		for (int i = 1;i <= k;i++)
			if (s[i] != '?')
				cnt[s[i] - '0']++;
		puts(cnt[0] <= k / 2 && cnt[1] <= k / 2 ? "YES" : "NO");
	}
	return 0;
}