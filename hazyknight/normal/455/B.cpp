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
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n,m,id;
int SG[MAXN];
int ch[MAXN][26];

char s[MAXN];

void dfs1(int u)
{
	for (int i = 0;i < 26;i++)
		if (ch[u][i])
		{
			dfs1(ch[u][i]);
			if (!SG[ch[u][i]])
			{
				SG[u] = 1;
				return;
			}
		}
}

void dfs2(int u)
{
	int tot = 0;
	for (int i = 0;i < 26;i++)
		if (ch[u][i])
		{	
			tot = 1;
			dfs2(ch[u][i]);
			if (!SG[ch[u][i]])
			{
				SG[u] = 1;
				return;
			}
		}
	if (!tot)
		SG[u] = 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	id = 1;
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s);
		int l = strlen(s),cur = 1;
		for (int j = 0;j < l;j++)
		{
			if (!ch[cur][s[j] - 'a'])
				ch[cur][s[j] - 'a'] = ++id;
			cur = ch[cur][s[j] - 'a'];
		}
	}
	memset(SG,0,sizeof(SG));
	dfs1(1);
	bool canwin = SG[1];
	memset(SG,0,sizeof(SG));
	dfs2(1);
	bool canlose = SG[1];
	if (canwin)
	{
		if (canlose)
			puts("First");
		else
		{
			if (m & 1)
				puts("First");
			else
				puts("Second");
		}
	}
	else
		puts("Second");
	return 0;
}