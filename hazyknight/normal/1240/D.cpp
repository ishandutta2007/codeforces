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
#include <unordered_map>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

struct StackTree
{
	int N,cur;
	int fa[MAXN];
	int cnt[MAXN];
	
	map<int,int> ch[MAXN];
	
	void init()
	{
		while (N > 1)
		{
			fa[N] = cnt[N] = 0;
			ch[N].clear();
			N--;
		}
		cnt[1] = 0;
		ch[1].clear();
		N = cur = 1;
	}
	
	void push(int v)
	{
		if (!ch[cur][v])
			fa[ch[cur][v] = ++N] = cur;
		cnt[cur = ch[cur][v]]++;
	}
	
	void pop()
	{
		cnt[cur = fa[cur]]++;
	}
}L,R;

int T,n;
int a[MAXN];

ll ans;

stack<int> Sl,Sr;

void dfs(int u,int v)
{
	ans += (ll)L.cnt[u] * R.cnt[v];
	for (map<int,int>::iterator i = L.ch[u].begin();i != L.ch[u].end();i++)
		if (R.ch[v].find(i->first) != R.ch[v].end())
			dfs(i->second,R.ch[v][i->first]);
}

void solve(int l,int r)
{
	if (l >= r)
		return;
	int mid = l + r >> 1;
	solve(l,mid);
	solve(mid + 1,r);
	int tmp = ans;
	L.init();
	R.init();
	while (!Sl.empty())
		Sl.pop();
	while (!Sr.empty())
		Sr.pop();
	for (int i = mid;i >= l;i--)
	{
		if (Sl.empty() || Sl.top() != a[i])
		{
			Sl.push(a[i]);
			L.push(a[i]);
		}
		else
		{
			Sl.pop();
			L.pop();
		}
	}
	for (int i = mid + 1;i <= r;i++)
	{
		if (Sr.empty() || Sr.top() != a[i])
		{
			Sr.push(a[i]);
			R.push(a[i]);
		}
		else
		{
			Sr.pop();
			R.pop();
		}
	}
	dfs(1,1);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		ans = 0;
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		solve(1,n);
		printf("%lld\n",ans);
	}
	return 0;
}