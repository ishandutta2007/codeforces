#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

int T,n,m;
int a[MAXN];
int b[MAXN];
char s[MAXN];
int cnt[26];

bool vis[MAXN];

void solve()
{
	for (int i = 0;i < 26;i++)
		cnt[i] = 0;
	for (int i = 1;i <= n;i++)
		cnt[s[i] - 'a']++;
	for (int i = 0;i < 26;i++)
	{
		if (cnt[i] == n)
		{
			puts(s + 1);
			return;
		}
		if (cnt[i] == 1)
		{
			cnt[i] = 0;
			s[1] = i + 'a';
			int p = 2;
			for (int j = 0;j < 26;j++)
				while (cnt[j]--)
					s[p++] = j + 'a';
			puts(s + 1);
			return;
		}
	}
	for (int i = 0;i < 26;i++)
	{
		if (!cnt[i])
			continue;
		cnt[i]--;
		for (int j = 0;j < 26;j++)
		{
			if (!cnt[j])
				continue;
			cnt[j]--;
			if (i != j)
			{
				s[1] = i + 'a';
				s[2] = j + 'a';
				int p = 3;
				for (int k = 0;k < 26;k++)
				{
					int C = cnt[k];
					while (C--)
						s[p++] = k + 'a';
				}
				for (int k = 3;k < n;k++)
					if (s[k] == i + 'a' && s[k + 1] == j + 'a')
					{
						if (s[n] == s[k + 1])
						{
							p = n;
							int C = cnt[i];
							while (C--)
								s[p--] = i + 'a';
							C = cnt[j];
							while (C--)
								s[p--] = j + 'a';
						}
						else
						{
							for (int l = k + 2;l <= n;l++)
								if (s[k + 1] != s[l])
								{
									swap(s[k + 1],s[l]);
									break;
								}
						}
					}
				puts(s + 1);
				return;
			}
			if (i == j && cnt[i] <= n - 2 - cnt[i])
			{
				s[1] = s[2] = i + 'a';
				for (int k = 3;k <= n;k++)
				{
					for (int l = 0;l < 26;l++)
						if (cnt[l])
						{
							cnt[l]--;
							bool ok1 = (l != i || s[k - 1] != i + 'a');
							bool ok2 = (l == i ? cnt[i] <= n - k - cnt[i] : cnt[i] <= n - k - cnt[i] + 1);
							if (!ok1 || !ok2)
							{
								cnt[l]++;
								continue;
							}
							s[k] = l + 'a';
							break;
						}
				}
				puts(s + 1);
				return;
			}
			cnt[j]++;
		}
		cnt[i]++;
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		solve();
	}
	return 0;
}