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

struct Edge
{
	int to;
	int nxt;
	bool vis;
}edge[MAXN << 1];

int n,id,tot,m;
int a[MAXN];
int b[MAXN];
int ans[MAXN];
int first[MAXN];
int val[MAXN << 1];
int deg[MAXN];

int bs(int v)
{
	int low = 1,high = tot;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (val[mid] >= v)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
	deg[v]++;
}

void dfs(int u)
{
	for (int &i = first[u];i;i = edge[i].nxt)
	{
		if (edge[i].vis)
			continue;
		edge[i].vis = edge[i ^ 1].vis = 1;
		dfs(edge[i].to);
	}
	ans[++m] = u;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i < n;i++)
	{
		cin >> a[i];
		val[++tot] = a[i];
	}
	for (int i = 1;i < n;i++)
	{
		cin >> b[i];
		val[++tot] = b[i];
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i < n;i++)
		a[i] = bs(a[i]);
	for (int i = 1;i < n;i++)
		b[i] = bs(b[i]);
	id = 1;
	for (int i = 1;i < n;i++)
	{
		if (a[i] > b[i])
		{
			puts("-1");
			return 0;
		}
		addE(a[i],b[i]);
		addE(b[i],a[i]);
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		if (deg[i] & 1)
			cnt++;
	if (cnt != 0 && cnt != 2)
	{
		puts("-1");
		return 0;
	}
	bool ok = 0;
	for (int i = 1;i < n;i++)
		if (deg[i] & 1)
		{
			dfs(i);
			ok = 1;
			break;
		}
	if (!ok)
		dfs(1);
	if (m != n)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		cout << val[ans[i]] << ' ';
	cout << endl;
	return 0;
}