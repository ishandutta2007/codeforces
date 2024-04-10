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

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,id;
int first[MAXN];

bool mark[MAXN];

priority_queue<int,vector<int>,greater<int> > Q;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u,v,i = 1;i <= m;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	cout << 1 << ' ';
	mark[1] = true;
	for (int i = first[1];i;i = edge[i].nxt)
		if (!mark[edge[i].to])
		{
			mark[edge[i].to] = true;
			Q.push(edge[i].to);
		}
	while (!Q.empty())
	{
		int u = Q.top();
		Q.pop();
		cout << u << ' ';
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to])
			{
				mark[edge[i].to] = true;
				Q.push(edge[i].to);
			}
	}
	cout << endl;
	return 0;
}