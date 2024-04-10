#pragma G++ optimize(3)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std;

const int MAXN = 500005;
const int SIZE = 700;

struct Query
{
	int id,l,r;
	bool operator < (const Query & p)const
	{
		return r < p.r;
	}
};

int n,m,tot;
int a[MAXN];
int ans[MAXN];
int cnt[MAXN];
int cdt[MAXN];

bool inc[MAXN];

int get()
{
	while (tot && cnt[cdt[tot]] != 1)
	{
		inc[cdt[tot]] = false;
		tot--;
	}
	if (!tot)
		return 0;
	return cdt[tot];
}

struct Block
{
	vector<Query> v;
	void add(int id,int l,int r)
	{
		v.push_back((Query){id,l,r});
	}
	void doit()
	{
		if (v.empty())
			return;
		sort(v.begin(),v.end());
		tot = 0;
		memset(cnt,0,sizeof(cnt));
		memset(inc,0,sizeof(inc));
		for (int i = v[0].l;i <= v[0].r;i++)
		{
			cnt[a[i]]++;
			if (cnt[a[i]] == 1 && !inc[a[i]])
			{
				inc[a[i]] = true;
				cdt[++tot] = a[i];
			}
		}
		ans[v[0].id] = get();
		for (int i = 1;i < v.size();i++)
		{
			for (int j = v[i - 1].r + 1;j <= v[i].r;j++)
			{
				cnt[a[j]]++;
				if (cnt[a[j]] == 1 && !inc[a[j]])
				{
					inc[a[j]] = true;
					cdt[++tot] = a[j];
				}
			}
			if (v[i - 1].l < v[i].l)
			{
				for (int j = v[i - 1].l;j < v[i].l;j++)
				{
					cnt[a[j]]--;
					if (cnt[a[j]] == 1 && !inc[a[j]])
					{
						inc[a[j]] = true;
						cdt[++tot] = a[j];
					}
				}
			}
			else
			{
				for (int j = v[i].l;j < v[i - 1].l;j++)
				{
					cnt[a[j]]++;
					if (cnt[a[j]] == 1 && !inc[a[j]])
					{
						inc[a[j]] = true;
						cdt[++tot] = a[j];
					}
				}
			}
			ans[v[i].id] = get();
		}
	}
}block[MAXN / SIZE + 5];

inline char gc()
{
	static char buf[131072],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,131072,stdin),p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	char ch = gc();
	int sum = 0;
	while (!(ch >= '0' && ch <= '9'))
		ch = gc();
	while (ch >= '0' && ch <= '9')
		sum = sum * 10 + ch - '0',ch = gc();
	return sum;
}

int main()
{
	n = read();
	for (int i = 1;i <= n;i++)
		a[i] = read();
	m = read();
	for (int l,r,i = 1;i <= m;i++)
	{
		l = read(),r = read();
		block[(l - 1) / SIZE + 1].add(i,l,r);
	}
	for (int i = 1;(i - 1) * SIZE < m;i++)
		block[i].doit();
	for (int i = 1;i <= m;i++)
		printf("%d\n",ans[i]);
	return 0;
}