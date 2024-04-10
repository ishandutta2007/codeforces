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

const int MAXN = 3005;
const int MOD = 1000000007;

struct Node
{
	int ch[2];
	int fail,len;
	int cnt,deg;
}node[MAXN << 1];

int m,id = 1,last = 1,ans;

queue<int> Q;
vector<int> tr[26];

void init()
{
	int ID = 0;
	for (int l = 1;l <= 4;l++)
		for (int i = 0;i < (1 << l);i++)
		{
			if (l == 4 && (i == 3 || i == 5 || i == 14 || i == 15))
				continue;
			for (int j = l - 1;j >= 0;j--)
				tr[ID].push_back(i >> j & 1);
			ID++;
		}
}

void extend(int c)
{
	int p = last,np = ++id;
	node[np].len = node[p].len + 1;
	while (p && !node[p].ch[c])
	{
		node[p].ch[c] = np;
		p = node[p].fail;
	}
	if (!p)
		node[np].fail = 1;
	else
	{
		int q = node[p].ch[c];
		if (node[q].len == node[p].len + 1)
			node[np].fail = q;
		else
		{
			int nq = ++id;
			node[nq].len = node[p].len + 1;
			memcpy(node[nq].ch,node[q].ch,sizeof(node[q].ch));
			node[nq].fail = node[q].fail;
			node[q].fail = node[np].fail = nq;
			while (p && node[p].ch[c] == q)
			{
				node[p].ch[c] = nq;
				p = node[p].fail;
			}
		}
	}
	last = np;
}

void solve()
{
	for (int i = 1;i <= id;i++)
	{
		node[i].cnt = 0;
		if (node[i].ch[0])
			node[node[i].ch[0]].deg++;
		if (node[i].ch[1])
			node[node[i].ch[1]].deg++;
	}
	ans = 0;
	node[1].cnt = 1;
	Q.push(1);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0;i < 26;i++)
		{
			int to = u;
			for (int j = 0;j < tr[i].size();j++)
				to = node[to].ch[tr[i][j]];
			if (!to)
				continue;
			(node[to].cnt += node[u].cnt) %= MOD;
		}
		if (node[u].ch[0] && !--node[node[u].ch[0]].deg)
			Q.push(node[u].ch[0]);
		if (node[u].ch[1] && !--node[node[u].ch[1]].deg)
			Q.push(node[u].ch[1]);
	}
	for (int i = 2;i <= id;i++)
		(ans += node[i].cnt) %= MOD;
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	init();
	cin >> m;
	for (int a,i = 1;i <= m;i++)
	{
		cin >> a;
		extend(a);
		solve();
	}
	return 0;
}