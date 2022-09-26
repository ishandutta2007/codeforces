#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>

using namespace std;

const int MAXN = 1000005;

int t,n,l;
int match[26];
int ok[MAXN];

bool mark[26];

char s[MAXN];
char a[MAXN];
char b[MAXN];

bool dfs(int i)
{
	if (ok[i] != -1)
		return ok[i];
	match[s[i] - 'a'] = a[i] - 'a';
	mark[a[i] - 'a'] = true;
	int j = i;
	while (j + 1 < l && match[s[j + 1] - 'a'] == a[j + 1] - 'a')
		j++;
	if (j != l - 1 && match[s[j + 1] - 'a'] != -1 && match[s[j + 1] - 'a'] < a[j + 1] - 'a')
	{
		match[s[i] - 'a'] = -1;
		mark[a[i] - 'a'] = 0;
		return ok[i] = 0;
	}
	if (j != l - 1 && match[s[j + 1] - 'a'] == -1)
	{
		for (int k = a[j + 1] - 'a';k < n;k++)
			if (!mark[k] && (k > a[j + 1] - 'a' || dfs(j + 1)))
			{
				match[s[i] - 'a'] = -1;
				mark[a[i] - 'a'] = 0;
				return ok[i] = 1;
			}
		match[s[i] - 'a'] = -1;
		mark[a[i] - 'a'] = 0;
		return ok[i] = 0;
	}
	match[s[i] - 'a'] = -1;
	mark[a[i] - 'a'] = 0;
	return ok[i] = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	scanf("%d",&t);
	while (t--)
	{
		memset(match,-1,sizeof(match));
		memset(mark,0,sizeof(mark));
		char space;
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",a);
		scanf("%s",b);
		l = strlen(s);
		for (int i = 0;i < l;i++)
			ok[i] = -1;
		bool flag = false;
		for (int i = 0;i < l;i++)
		{
			if (!flag)
			{
				if (match[s[i] - 'a'] == -1)
				{
					if (!mark[a[i] - 'a'])
					{
						if (dfs(i))
						{
							mark[a[i] - 'a'] = true;
							match[s[i] - 'a'] = a[i] - 'a';
						}
						else
						{
							for (int k = a[i] - 'a' + 1;k < n;k++)
								if (!mark[k])
								{
									mark[k] = true;
									match[s[i] - 'a'] = k;
									break;
								}
						}
					}
					else
					{
						for (int k = a[i] - 'a' + 1;k < n;k++)
							if (!mark[k])
							{
								mark[k] = true;
								match[s[i] - 'a'] = k;
								break;
							}
					}
				}
			}
			else if (match[s[i] - 'a'] == -1)
			{
				for (int k = 0;k < n;k++)
					if (!mark[k])
					{
						mark[k] = true;
						match[s[i] - 'a'] = k;
						break;
					}
			}
			if (match[s[i] - 'a'] == -1)
			{
				s[0] = '{';
				break;
			}
			s[i] = char(match[s[i] - 'a'] + 'a');
			if (s[i] > a[i])
				flag = true;
		}
		bool quit = false;
		for (int i = 0;i < l;i++)
			if (s[i] != b[i])
			{
				if (s[i] > b[i])
					quit = true;
				break;
			}
		if (quit)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 0;i < n;i++)
		{
			if (match[i] == -1)
			{
				for (int j = 0;j < n;j++)
					if (!mark[j])
					{
						mark[j] = true;
						putchar(char('a' + j));
						break;
					}
			}
			else
				putchar(char('a' + match[i]));
		}
		putchar('\n');
	}
	return 0;
}