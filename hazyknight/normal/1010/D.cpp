#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;

const int MAXN = 1000005;

struct Node
{
	int ch[2],v,fa;
	string opr;
	int ans[2];
}node[MAXN];

int n;

bool mark[MAXN];

void dfs1(int now)
{
	if (!node[now].ch[0] && !node[now].ch[1])
		return;
	if (node[now].ch[0])
		dfs1(node[now].ch[0]);
	if (node[now].ch[1])
		dfs1(node[now].ch[1]);
	if (node[now].opr == "NOT")
		node[now].v = node[node[now].ch[0]].v ^ 1;
	if (node[now].opr == "AND")
		node[now].v = (node[node[now].ch[0]].v & node[node[now].ch[1]].v);
	if (node[now].opr == "OR")
		node[now].v = (node[node[now].ch[0]].v | node[node[now].ch[1]].v);
	if (node[now].opr == "XOR")
		node[now].v = (node[node[now].ch[0]].v ^ node[node[now].ch[1]].v);
}

void dfs2(int now)
{
	if (now != 1)
	{
		int fa = node[now].fa;
		if (node[fa].opr == "NOT")
		{
			node[now].ans[0] = node[fa].ans[1];
			node[now].ans[1] = node[fa].ans[0];
		}
		else
		{
			int ch = node[fa].ch[node[fa].ch[1] != now];
			if (node[fa].opr == "AND")
			{
				node[now].ans[0] = node[fa].ans[0];
				node[now].ans[1] = node[fa].ans[node[ch].v];
			}
			if (node[fa].opr == "OR")
			{
				node[now].ans[0] = node[fa].ans[node[ch].v];
				node[now].ans[1] = node[fa].ans[1];
			}
			if (node[fa].opr == "XOR")
			{
				node[now].ans[0] = node[fa].ans[node[ch].v];
				node[now].ans[1] = node[fa].ans[node[ch].v ^ 1];
			}
		}
	}
	if (node[now].ch[0])
		dfs2(node[now].ch[0]);
	if (node[now].ch[1])
		dfs2(node[now].ch[1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int v,i = 1;i <= n;i++)
	{
		cin >> node[i].opr;
		if (node[i].opr == "IN")
			cin >> node[i].v;
		else if (node[i].opr == "NOT")
			cin >> node[i].ch[0],node[node[i].ch[0]].fa = i;
		else
			cin >> node[i].ch[0] >> node[i].ch[1],node[node[i].ch[0]].fa = node[node[i].ch[1]].fa = i;
	}
	dfs1(1);
	node[1].ans[0] = 0,node[1].ans[1] = 1;
	dfs2(1);
	for (int i = 1;i <= n;i++)
		if (!node[i].ch[0] && !node[i].ch[1])
			cout << node[i].ans[node[i].v ^ 1];
	cout << endl;
	return 0;
}