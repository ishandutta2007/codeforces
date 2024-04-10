#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

inline char gc()
{
	static char buf[524288],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,524288,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 100005;
const int SIZE = 320;

struct Query
{
	int l,r,id;
	bool operator < (const Query &p)const
	{
		return l / SIZE == p.l / SIZE ? r < p.r : l < p.l;
	}
}a[MAXN];

int n,q,L,R;
int ans1,ans2;
int b[MAXN];
int to[MAXN];
int fa[MAXN];
int cnt[MAXN];
int ans[MAXN];
int len[MAXN];

bool mark[MAXN];

deque<int> loc[MAXN];
vector<int> pos[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void ADD(int p)
{
	if (!cnt[b[p]])
		ans1++;
	cnt[b[p]]++;
}

void RMV(int p)
{
	cnt[b[p]]--;
	if (!cnt[b[p]])
		ans1--;
}

bool ok(int v)
{
	if (loc[v].size() == 0)
		return false;
	if (loc[v].size() <= 2)
		return true;
	int bk = loc[v].back();
	loc[v].pop_back();
	bool res = (fa[loc[v].front()] == fa[loc[v].back()] && bk - loc[v].back() == len[loc[v].back()]);
	loc[v].push_back(bk);
	return res;
}

void addL(int p)
{
	ans2 -= mark[b[p]];
	ADD(p);
	loc[b[p]].push_front(p);
	mark[b[p]] = ok(b[p]);
	ans2 += mark[b[p]];
}

void addR(int p)
{
	ans2 -= mark[b[p]];
	ADD(p);
	loc[b[p]].push_back(p);
	mark[b[p]] = ok(b[p]);
	ans2 += mark[b[p]];
}

void rmvL(int p)
{
	ans2 -= mark[b[p]];
	RMV(p);
	loc[b[p]].pop_front();
	mark[b[p]] = ok(b[p]);
	ans2 += mark[b[p]];
}

void rmvR(int p)
{
	ans2 -= mark[b[p]];
	RMV(p);
	loc[b[p]].pop_back();
	mark[b[p]] = ok(b[p]);
	ans2 += mark[b[p]];
}

int main()
{
	read(n);
	for (int i = 0;i < n;i++)
	{
		read(b[i]);
		pos[b[i]].push_back(i);
	}
	for (int i = 0;i < n;i++)
		fa[i] = i;
	for (int i = 1;i <= 100000;i++)
	{
		vector<int> &P = pos[i];
		bool flag = false;
		for (int j = 1;j < (int)P.size() - 1;j++)
		{
			if (P[j + 1] - P[j] == P[j] - P[j - 1])
			{
				fa[getroot(P[j])] = getroot(P[j - 1]);
				len[P[j]] = P[j] - P[j - 1];
			}
		}
	}
	read(q);
	for (int i = 1;i <= q;i++)
	{
		read(a[i].l),read(a[i].r);
		a[i].l--,a[i].r--;
		a[i].id = i;
	}
	sort(a + 1,a + q + 1);
	L = 0,R = -1;
	for (int i = 1;i <= q;i++)
	{
		while (L > a[i].l)
			addL(--L);
		while (R < a[i].r)
			addR(++R);
		while (L < a[i].l)
			rmvL(L++);
		while (R > a[i].r)
			rmvR(R--);
		ans[a[i].id] = ans1 + !ans2;
	}
	for (int i = 1;i <= q;i++)
		printf("%d\n",ans[i]);
	return 0;
}