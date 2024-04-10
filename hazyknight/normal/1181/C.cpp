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

using namespace std;

const int MAXN = 1005;

struct B
{
	char tp;
	
	int l,r;
	
	int cnt()
	{
		return r - l + 1;
	}
};

int n,m;
int len[MAXN][MAXN];
int pre[MAXN];
int suf[MAXN];

long long ans;

char s[MAXN][MAXN];

vector<B> v;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%s",s[i] + 1);
	for (int i = 1;i <= n;i++)
		for (int j = m;j >= 1;j--)
			len[i][j] = (s[i][j] == s[i][j + 1] ? len[i][j + 1] + 1 : 1);
	for (int i = 1;i <= m;i++)
	{
		v.clear();
		for (int j = 1;j <= n;j++)
			if (!v.empty() && s[j][i] == v.back().tp)
				v.back().r++;
			else
				v.push_back((B){s[j][i],j,j});
		for (int j = 1;j <= n;j++)
			if (s[j][i] != s[j - 1][i])
				pre[j] = len[j][i];
			else
				pre[j] = min(pre[j - 1],len[j][i]);
		for (int j = n;j >= 1;j--)
			if (s[j][i] != s[j + 1][i])
				suf[j] = len[j][i];
			else
				suf[j] = min(suf[j + 1],len[j][i]);
		for (int j = 0;j + 2 < v.size();j++)
			if (v[j + 1].cnt() <= v[j].cnt() && v[j + 1].cnt() <= v[j + 2].cnt())
				ans += min(suf[v[j].r - v[j + 1].cnt() + 1],min(pre[v[j + 1].r],pre[v[j + 2].l + v[j + 1].cnt() - 1]));
	}
	printf("%lld\n",ans);
	return 0;
}