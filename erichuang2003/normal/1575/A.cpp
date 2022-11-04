#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;

int n,m,id = 1;
int ch[MAXN][26];

char s[MAXN];

vector<int> tag[MAXN];

void dfs(int u)
{
	if (tag[u].size())
	{
		for (int j = 0;j < tag[u].size();j++)
			printf("%d ",tag[u][j]);
		return;
	}
	for (int i = 0;i < 26;i++)
		if (ch[u][i])
			dfs(ch[u][i]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s + 1);
		int cur = 1;
		for (int j = 1;j <= m;j++)
			if (j & 1)
			{
				int &c = ch[cur][s[j] - 'A'];
				if (!c)
					c = ++id;
				cur = c;
			}
			else
			{
				int &c = ch[cur]['Z' - s[j]];
				if (!c)
					c = ++id;
				cur = c;
			}
		tag[cur].push_back(i);
	}
	dfs(1);
	printf("\n");
	return 0;
}