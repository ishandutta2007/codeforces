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

const int MAXN = 200005;

int n,m,ANS;
int u[MAXN];
int v[MAXN];
int MIN[MAXN];
int ans[MAXN];
int deg[MAXN];

queue<int> Q;
vector<int> e[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		e[u[i]].push_back(v[i]);
		deg[v[i]]++;
	}
	for (int i = 1;i <= n;i++)
		MIN[i] = i;
	for (int i = 1;i <= n;i++)
		if (!deg[i])
			Q.push(i);
	int cnt = 0;
	while (!Q.empty())
	{
		cnt++;
		int u = Q.front();
		Q.pop();
		for (int i = 0;i < e[u].size();i++)
		{
			int v = e[u][i];
			MIN[v] = min(MIN[u],MIN[v]);
			if (!--deg[v])
				Q.push(v);
		}
	}
	if (cnt != n)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		e[i].clear();
		ans[i] = MIN[i];
		MIN[i] = i;
	}
	for (int i = 1;i <= m;i++)
	{
		swap(u[i],v[i]);
		e[u[i]].push_back(v[i]);
		deg[v[i]]++;
	}
	for (int i = 1;i <= n;i++)
		if (!deg[i])
			Q.push(i);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0;i < e[u].size();i++)
		{
			int v = e[u][i];
			MIN[v] = min(MIN[u],MIN[v]);
			if (!--deg[v])
				Q.push(v);
		}
	}
	for (int i = 1;i <= n;i++)
		ans[i] = min(ans[i],MIN[i]);
	for (int i = 1;i <= n;i++)
		if (ans[i] == i)
			ANS++;
	printf("%d\n",ANS);
	for (int i = 1;i <= n;i++)
		putchar(ans[i] == i ? 'A' : 'E');
	putchar('\n');
	return 0;
}