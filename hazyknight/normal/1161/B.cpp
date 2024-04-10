#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 400005;

int n,m,ans;
int nxt[MAXN];
int cnt[MAXN];
int sum[MAXN];

vector<int> seg[MAXN];

int dis(int u,int v)
{
	return (v - u + n) % n;
}

void getnxt(vector<int> &cur)
{
	nxt[0] = nxt[1] = 0;
	for (int i = 1,j = 0;i < cur.size();i++)
	{
		while (j && cur[i] != cur[j])
			j = nxt[j];
		if (cur[i] == cur[j])
			j++;
		nxt[i + 1] = j;
	}
}

void KMP(vector<int> &cur)
{
	for (int i = 0,j = 0,k = 0;i < cur.size() * 2;i++,(k += 1) %= cur.size())
	{
		while (j && cur[k] != cur[j])
			j = nxt[j];
		if (cur[j] == cur[k])
			j++;
		if (j == cur.size())
		{
			if (i != j - 1)
				cnt[sum[i - j]]++;
			j = nxt[j];
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		u--,v--;
		if (dis(u,v) > dis(v,u))
			swap(u,v);
		seg[dis(u,v)].push_back(u);
		seg[dis(u,v)].push_back(v);
	}
	for (int i = 1;i <= n;i++)
	{
		if (!seg[i].size())
			continue;
		ans++;
		sort(seg[i].begin(),seg[i].end());
		int tmp = dis(seg[i].back(),seg[i][0]);
		for (int j = seg[i].size() - 1;j > 0;j--)
			seg[i][j] = dis(seg[i][j - 1],seg[i][j]);
		seg[i][0] = tmp;
		sum[0] = seg[i][0];
		for (int j = 1;j < seg[i].size();j++)
			sum[j] = sum[j - 1] + seg[i][j];
		getnxt(seg[i]);
		KMP(seg[i]);
	}
	for (int i = 1;i < n;i++)
		if (cnt[i] == ans)
		{
			puts("Yes");
			return 0;
		}
	puts("No");
	return 0;
}