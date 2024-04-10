#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int tim;
	int next;
}edge[MAXN << 1];

int n,m,k,id;
int first[MAXN];
int x[MAXN],y[MAXN];
int ans[MAXN];
int degree[MAXN];

bool mark[MAXN];

void addE(int u,int v,int t)
{
	degree[v]++;
	edge[++id] = (Edge){v,t,first[u]};
	first[u] = id;
}

priority_queue<pair<int,int> > Q,rQ;

void push(int d,int p)
{
	Q.push(make_pair(-d,p));
}

void erase(int d,int p)
{
	rQ.push(make_pair(-d,p));
}

void flush()
{
	while (!rQ.empty() && Q.top().first == rQ.top().first && Q.top().second == rQ.top().second)
		Q.pop(),rQ.pop();
}

pair<int,int> top()
{
	flush();
	return make_pair(-Q.top().first,Q.top().second);
}

void pop()
{
	flush();
	Q.pop();
}

int size()
{
	return Q.size() - rQ.size();
}

void work(int T)
{
	while (size())
	{
		pair<int,int> cur = top();
		if (cur.first >= k)
			break;
		pop();
		mark[cur.second] = true;
		for (int i = first[cur.second];i;i = edge[i].next)
		{
			if (edge[i].tim >= T)
				continue;
			if (!mark[edge[i].to])
			{
				erase(degree[edge[i].to],edge[i].to);
				degree[edge[i].to]--;
				push(degree[edge[i].to],edge[i].to);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> x[i] >> y[i];
		addE(x[i],y[i],i);
		addE(y[i],x[i],i);
	}
	for (int i = 1;i <= n;i++)
		push(degree[i],i);
	work(m + 1);
	ans[m] = size();
	for (int i = m;i > 1;i--)
	{
		if (!mark[x[i]] && !mark[y[i]])
		{
			erase(degree[x[i]],x[i]);
			degree[x[i]]--;
			push(degree[x[i]],x[i]);
			erase(degree[y[i]],y[i]);
			degree[y[i]]--;
			push(degree[y[i]],y[i]);
		}
		work(i);
		ans[i - 1] = size();
	}
	for (int i = 1;i <= m;i++)
		cout << ans[i] << endl;
	return 0;
}