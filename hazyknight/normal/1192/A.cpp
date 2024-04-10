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
#include <unordered_set>
#include <unordered_map>
 
using namespace std;

typedef long long ll;
 
const int MAXN = 1200005;
 
int n,tp,MAXx,Y,id;
int fa[MAXN];
int r[MAXN];
int c[MAXN];
int ans[MAXN];
int tot[MAXN];
 
bool outside[MAXN];
bool valid[MAXN];
bool inheap[MAXN];
 
priority_queue<int> Q,rQ;
unordered_map<ll,int> g,vis;
 
int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

ll hashkey(ll x,ll y)
{
	return x * (2e9 + 1) + y;
}
 
void init()
{
	for (int i = 1;i < (1 << 9);i++)
	{
		if (i >> 4 & 1)
			continue;
		for (int j = 0;j < 9;j++)
			fa[j] = j;
		for (int dx1 = -1;dx1 <= 1;dx1++)
		for (int dy1 = -1;dy1 <= 1;dy1++)
		if (dx1 || dy1)
		for (int dx2 = -1;dx2 <= 1;dx2++)
		for (int dy2 = -1;dy2 <= 1;dy2++)
		if (dx2 || dy2)
		{
			if (abs(dx1 - dx2) <= 1 && abs(dy1 - dy2) <= 1)
			{
				int u = dx1 * 3 + dy1 + 4,v = dx2 * 3 + dy2 + 4;
				if ((i >> u & 1) || (i >> v & 1))
					continue;
				if (getroot(u) != getroot(v))
					fa[getroot(u)] = getroot(v);
			}
		}
		int lst = -1,ok = 1;
		for (int j = 0;j < 9;j++)
			if (j != 4 && (~i >> j & 1))
			{
				if (lst == -1)
					lst = getroot(j);
				if (~lst && lst != getroot(j))
				{
					ok = 0;
					break;
				}
			}
		valid[i] = ok;
	}
}
 
void insert(int v)
{
	inheap[v] = 1;
	Q.push(v);
}
 
void erase(int v)
{
	inheap[v] = 0;
	rQ.push(v);
}
 
void add(int x,int y)
{
	if (vis[hashkey(x,y)] || g[hashkey(x,y)])
		return;
	if (x > MAXx)
	{
		MAXx = x;
		Y = y;
	}
	vis[hashkey(x,y)] = ++id;
	fa[id] = id;
	for (int dx = -1;dx <= 1;dx++)
		for (int dy = -1;dy <= 1;dy++)
			if ((!dx && dy) || (dx && !dy))
			{
				int mask = vis[hashkey(x + dx,y + dy)];
				if (mask)
					fa[getroot(id)] = getroot(mask);
			}
}
 
int pre[MAXN];
 
int get(int u)
{
	return u == pre[u] ? u : pre[u] = get(pre[u]);
}
 
bool check(int x,int y)
{
	for (int i = 0;i < 9;i++)
		pre[i] = i;
	for (int dx1 = -1;dx1 <= 1;dx1++)
	for (int dy1 = -1;dy1 <= 1;dy1++)
	if ((dx1 || dy1) && vis[hashkey(x + dx1,y + dy1)])
	for (int dx2 = -1;dx2 <= 1;dx2++)
	for (int dy2 = -1;dy2 <= 1;dy2++)
	if ((dx2 || dy2) && getroot(vis[hashkey(x + dx1,y + dy1)]) == getroot(vis[hashkey(x + dx2,y + dy2)]))
	{
		if ((abs(dx1 - dx2) <= 1 && dy1 == dy2) || (abs(dy1 - dy2) <= 1 && dx1 == dx2))
		{
			int u = dx1 * 3 + dy1 + 4,v = dx2 * 3 + dy2 + 4;
			if (get(u) != get(v))
				pre[get(u)] = get(v);
		}
	}
	for (int dx1 = -1;dx1 <= 1;dx1++)
	for (int dy1 = -1;dy1 <= 1;dy1++)
	if (((!dx1 && dy1) || (dx1 && !dy1)) && vis[hashkey(x + dx1,y + dy1)])
	for (int dx2 = -1;dx2 <= 1;dx2++)
	for (int dy2 = -1;dy2 <= 1;dy2++)
	if (((!dx2 && dy2) || (dx2 && !dy2)) && (dx2 != dx1 || dy2 != dy1) && getroot(vis[hashkey(x + dx1,y + dy1)]) == getroot(vis[hashkey(x + dx2,y + dy2)]))
	{
		int u = dx1 * 3 + dy1 + 4,v = dx2 * 3 + dy2 + 4;
		if (get(u) != get(v))
			return 0;
	}
	return 1;
}
 
void dfs(int x,int y)
{
	if (!vis[hashkey(x,y)])
		return;
	vis[hashkey(x,y)] = 0;
	for (int dx = -1;dx <= 1;dx++)
		for (int dy = -1;dy <= 1;dy++)
			if ((!dx && dy) || (dx && !dy))
			{
				int mask = g[hashkey(x + dx,y + dy)];
				if (mask)
				{
					outside[mask] = 1;
					if (check(x + dx,y + dy) && valid[tot[mask]] && !inheap[mask])
						insert(mask);
				}
			}
	for (int dx = -1;dx <= 1;dx++)
		for (int dy = -1;dy <= 1;dy++)
			if (dx || dy)
			{
				int mask = g[hashkey(x + dx,y + dy)];
				if (mask)
				{
					tot[mask] |= (1 << (-dx * 3 - dy + 4));
					if (!valid[tot[mask]] && inheap[mask])
						erase(mask);
					if (check(x + dx,y + dy) && outside[mask] && valid[tot[mask]] && !inheap[mask])
						insert(mask);
				}
			}
	dfs(x - 1,y);
	dfs(x,y - 1);
	dfs(x + 1,y);
	dfs(x,y + 1);
}
 
int main()
{
	init();
	MAXx = -1e9 - 1;
	scanf("%d%d",&n,&tp);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&r[i],&c[i]);
		g[hashkey(r[i],c[i])] = i;
	}
	for (int i = 1;i <= n;i++)
		for (int dx = -1;dx <= 1;dx++)
			for (int dy = -1;dy <= 1;dy++)
				if (dx || dy)
					add(r[i] + dx,c[i] + dy);
	dfs(MAXx,Y);
	for (int i = n;i >= 1;i--)
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		int cur = Q.top();
		if (i != 1 && tot[cur] == 495)
		{
			puts("NO");
			return 0;
		}
		ans[i] = cur;
		inheap[cur] = 0;
		Q.pop();
		g[hashkey(r[cur],c[cur])] = 0;
		add(r[cur],c[cur]);
		dfs(r[cur],c[cur]);
	}
	puts("YES");
	for (int i = 1;i <= n;i++)
		printf("%d\n",ans[i]);
	return 0;
}