#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n,MAX;
int ans[MAXN];
int depth[MAXN];

bool mark[MAXN];

vector<int> opr;
vector<int> ch[MAXN];

void getdep(int u)
{
	mark[u] = (u == MAX);
	for (int i = 0;i < ch[u].size();i++)
	{
		getdep(ch[u][i]);
		mark[u] |= mark[ch[u][i]];
	}
}

int main()
{
	scanf("%d",&n);
	for (int fa,i = 2;i <= n;i++)
	{
		scanf("%d",&fa);
		fa++;
		depth[i] = depth[fa] + 1;
		ch[fa].push_back(i);
	}
	MAX = 1;
	for (int i = 2;i <= n;i++)
		if (depth[i] > depth[MAX])
			MAX = i;
	getdep(1);
	int cur = 1;
	for (int i = 1;i < n;i++)
	{
		ans[i] = cur;
		for (int j = 0;j < ch[cur].size();j++)
			if (mark[ch[cur][j]])
			{
				swap(ch[cur][0],ch[cur][j]);
				break;
			}
		for (int j = 0;j + 1 < ch[cur].size();j++)
		{
			opr.push_back(ch[cur][j]);
			ch[ch[cur][j + 1]].push_back(ch[cur][j]);
			mark[ch[cur][j + 1]] |= mark[ch[cur][j]];
		}
		cur = ch[cur].back();
	}
	ans[n] = cur;
	reverse(opr.begin(),opr.end());
	for (int i = 1;i <= n;i++)
		printf("%d ",ans[i] - 1);
	printf("\n%d\n",(int)opr.size());
	for (int i = 0;i < opr.size();i++)
		printf("%d ",opr[i] - 1);
	printf("\n");
	return 0;
}