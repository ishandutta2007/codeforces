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

const int MAXN = 1005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id;
int first[MAXN];

bool vis[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int ask(int u,int v)
{
	cout << "? " << u << ' ' << v << endl;
	cout.flush();
	int r = 0;
	cin >> r;
	return r;
}

void solve(int u)
{
	vector<int> son;
	for (int i = first[u];i;i = edge[i].nxt)
		if (!vis[edge[i].to])
			son.push_back(edge[i].to);
	if (!son.size())
	{
		cout << "! " << u << endl;
		cout.flush();
		exit(0);
	}
	if (son.size() == 1)
	{
		int v = son[0],cnt = 0;
		for (int i = first[v];i;i = edge[i].nxt)
			if (!vis[edge[i].to])
				cnt++;
		if (cnt == 1)
		{
			int r = ask(u,v);
			cout << "! " << r << endl;
			cout.flush();
			exit(0);
		}
		solve(son[0]);
	}
	for (int i = 0;i + 1 < son.size();i += 2)
	{
		int a = son[i],b = son[i + 1],r = ask(a,b);
		if (r == u)
		{
			vis[a] = vis[b] = 1;
			continue;
		}
		if (r == a)
		{
			vis[u] = 1;
			solve(a);
		}
		if (r == b)
		{
			vis[u] = 1;
			solve(b);
		}
	}
	if (son.size() & 1)
		solve(son.back());
	else
	{
		cout << "! " << u << endl;
		cout.flush();
		exit(0);
	}
}

int main()
{
	cin >> n;
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	solve(1);
	return 0;
}