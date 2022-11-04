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

typedef long long ll;

const int MAXN = 1005;

struct Node
{
	int ch[26];
	int len,par;
}node[MAXN << 1];

int n,m,tot,cnt,lst = 1,id = 1;
int r[MAXN];

char s[MAXN];
char c[MAXN];

ll K;
ll f[MAXN][MAXN];
ll sum[MAXN][MAXN];

void extend(int c)
{
	int p = lst;
	if (node[p].ch[c] && node[node[p].ch[c]].len == node[p].len + 1)
	{
		lst = node[p].ch[c];
		return;
	}
	int np = ++id;
	node[np].len = node[p].len + 1;
	while (p && !node[p].ch[c])
	{
		node[p].ch[c] = np;
		p = node[p].par;
	}
	if (!p)
		node[np].par = 1;
	else
	{
		int q = node[p].ch[c];
		if (node[q].len == node[p].len + 1)
			node[np].par = q;
		else
		{
			int nq = ++id;
			node[nq].len = node[p].len + 1;
			memcpy(node[nq].ch,node[q].ch,sizeof(node[q].ch));
			node[nq].par = node[q].par;
			node[q].par = node[np].par = nq;
			while (p && node[p].ch[c] == q)
			{
				node[p].ch[c] = nq;
				p = node[p].par;
			}
		}
	}
	lst = np;
}

void dfs(int u,int num)
{
	if (u > 1)
	{
		cnt++;
		if (cnt == num)
			return;
	}
	for (int i = 0;i < 26;i++)
		if (node[u].ch[i])
		{
			c[++tot] = char(i + 'a');
			dfs(node[u].ch[i],num);
			if (cnt == num)
				return;
			tot--;
		}
}

ll add(ll x,ll y)
{
	return x + y > 1e18 ? 1e18 + 1 : x + y;
}

ll DP()
{
	c[tot + 1] = 'a' - 1;
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	f[0][n + 1] = 1;
	for (int i = n + 1;i >= 1;i--)
		sum[0][i] = 1;
	for (int i = 1;i <= n;i++)
	{
		r[i] = -1;
		for (int j = i;j <= n;j++)
			if (s[j] != c[j - i + 1])
			{
				if (s[j] > c[j - i + 1])
					r[i] = j;
				break;
			}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = n;j >= 1;j--)
			if (r[j] != -1)
				f[i][j] = sum[i - 1][r[j] + 1];
		for (int j = n;j >= 1;j--)
			sum[i][j] = add(sum[i][j + 1],f[i][j]);
	}
	return f[m][1];
}

int main()
{
	scanf("%d%d%lld%s",&n,&m,&K,s + 1);
	for (int i = 1;i <= n;i++)
		extend(s[i] - 'a');
	int low = 1,high = n * (n + 1) / 2;
	while (low < high)
	{
		int mid = low + high >> 1;
		cnt = tot = 0;
		dfs(1,mid);
		if (cnt < mid)
		{
			high = cnt;
			continue;
		}
		if (DP() < K)
			high = mid;
		else
			low = mid + 1;
	}
	cnt = tot = 0;
	dfs(1,low);
	for (int i = 1;i <= tot;i++)
		putchar(c[i]);
	putchar('\n');
	return 0;
}