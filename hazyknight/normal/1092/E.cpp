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

using namespace std;

typedef long long ll;

const int MAXN = 1005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,m,id,LEN;
int first[MAXN];

bool mark[MAXN];

vector<int> MID;
vector<pair<int,int> > ans;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

pair<int,int> dfs(int now,int fa)
{
	mark[now] = true;
	pair<int,int> res = make_pair(0,now);
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
		{
			pair<int,int> ret = dfs(edge[i].to,now);
			ret.first++;
			if (ret.first > res.first)
				res = ret;
		}
	return res;
}

int findMID(int now,int fa,int T)
{
	if (now == T)
	{
		LEN--;
		if (LEN == 0)
			return now;
		return -1;
	}
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
		{
			int res = findMID(edge[i].to,now,T);
			if (res == 0)
				continue;
			if (res != -1)
				return res;
			LEN--;
			if (LEN == 0)
				return now;
			return -1;
		}
	return 0;
}

pair<int,int> getMID(int root)
{
	pair<int,int> st = dfs(root,0);
	pair<int,int> ed = dfs(st.second,0);
	LEN = ed.first / 2 + 1;
	return make_pair(ed.first,findMID(st.second,0,ed.second));
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
	int MAX = -1,root = 0;
	for (int i = 1;i <= n;i++)
		if (!mark[i])
		{
			pair<int,int> res = getMID(i);
			if (res.first > MAX)
			{
				root = res.second;
				MAX = res.first;
			}
			MID.push_back(res.second);
		}
	for (int i = 0;i < MID.size();i++)
		if (MID[i] != root)
		{
			ans.push_back(make_pair(root,MID[i]));
			addE(root,MID[i]);
			addE(MID[i],root);
		}
	cout << dfs(dfs(1,0).second,0).first << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}