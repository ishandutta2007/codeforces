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

const int MAXN = 100005;

int n,m;

vector<int> ans;
vector<pair<int,int> > E;
multiset<int> e[MAXN];

void dfs(int u)
{
	while (e[u].size())
	{
		int to = (*e[u].begin());
		e[to].erase(e[to].find(u));
		e[u].erase(e[u].find(to));
		dfs(to);
	}
	ans.push_back(u);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].insert(v);
		e[v].insert(u);
	}
	int lst = 0;
	for (int i = 1;i <= n;i++)
		if (e[i].size() & 1)
		{
			if (lst)
			{
				e[lst].insert(i);
				e[i].insert(lst);
				lst = 0;
			}
			else
				lst = i;
		}
	dfs(1);
	ans.pop_back();
	for (int i = 0;i < ans.size();i++)
	{
		int u = ans[i],v = ans[(i + 1) % ans.size()];
		if (i & 1)
			swap(u,v);
		E.push_back(make_pair(u,v));
	}
	if (ans.size() & 1)
		E.push_back(make_pair(1,1));
	printf("%d\n",(int)E.size());
	for (int i = 0;i < E.size();i++)
		printf("%d %d\n",E[i].first,E[i].second);
	return 0;
}