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
#include <complex>

using namespace std;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
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

const int MAXN = 250005;
const int MAXM = 500005;

int n,m,k;
int od[MAXN];
int deg[MAXN];
int mark[MAXN];

vector<int> path,pos;
vector<int> e[MAXN];
vector<int> cnt[MAXN];

bool cmp(const int &a,const int &b)
{
	return deg[a] > deg[b];
}

bool spj(const int &a,const int &b)
{
	return mark[a] < mark[b];
}

void dfs(int u)
{
	path.push_back(u);
	mark[u] = true;
	for (int i = 0;i < deg[u];i++)
		if (!mark[e[u][i]])
		{
			dfs(e[u][i]);
			break;
		}
	mark[u] = false;
}

int main()
{
	read(n),read(m),read(k);
	for (int u,v,i = 1;i <= m;i++)
	{
		read(u),read(v);
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	dfs(1);
	if ((long long)path.size() * k >= n)
	{
		puts("PATH");
		printf("%d\n",(int)path.size());
		for (int i = 0;i < path.size();i++)
			printf("%d ",path[i]);
		putchar('\n');
		return 0;
	}
	puts("CYCLES");
	for (int i = 1;i <= n;i++)
		od[i] = i;
	sort(od + 1,od + n + 1,cmp);
	for (int c = 1;c <= n && k;c++)
	{
		int u = od[c];
		if (mark[u] == 2)
			continue;
		for (int i = 0;i < deg[u];i++)
		{
			int v = e[u][i];
			if (mark[v] == 2)
				continue;
			for (int j = 0;j < deg[v];j++)
			{
				if (mark[e[v][j]] == 2 || u == e[v][j])
					continue;
				cnt[e[v][j]].push_back(v);
				pos.push_back(e[v][j]);
			}
		}
		for (int i = 0;i < pos.size() && k;i++)
		{
			int v = pos[i];
			if (cnt[v].size() <= 1)
			{
				cnt[v].clear();
				continue;
			}
			sort(cnt[v].begin(),cnt[v].end(),spj);
			for (int j = 0,l = cnt[v].size() - 1;j < l && k;j++,l--)
			{
				if (mark[cnt[v][j]])
					break;
				if (mark[u] == 2 || mark[v] == 2 || mark[cnt[v][l]] == 2 || mark[cnt[v][j]] == 1)
					continue;
				mark[u] = mark[v] = 1;
				mark[cnt[v][j]] = 2;
				mark[cnt[v][l]] = 1;
				puts("4");
				printf("%d %d %d %d\n",cnt[v][j],u,cnt[v][l],v);
				k--;
			}
			cnt[v].clear();
		}
		pos.clear();
	}
	return 0;
}