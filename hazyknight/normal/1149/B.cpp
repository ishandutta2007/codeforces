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

const int MAXN = 100005;
const int MAXM = 355;
const int MAXQ = 1005;

struct Tree
{
	struct Edge
	{
		int to;
		int c;
		int nxt;
	}edge[MAXQ];
	
	int id,cur,e;
	int fa[MAXQ];
	int first[MAXQ];
	
	Tree()
	{
		id = cur = 1;
	}
	
	void addE(int u,int v,int c)
	{
		edge[++e] = (Edge){v,c,first[u]};
		fa[v] = u;
		first[u] = e;
	}
	
	void add(int c)
	{
		addE(cur,++id,c);
		cur = id;
	}
	
	void rollback()
	{
		cur = fa[cur];
	}
}T[3];

int n,q,x;
int nxt[MAXN][26];
int ans[MAXQ][3];
int f[MAXM * MAXM * MAXM];

char tp,c;

string s;

inline int ID(int a,int b,int c)
{
	return a * (T[1].id + 1) * (T[2].id + 1) + b * (T[2].id + 1) + c;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> q >> s;
	for (int i = 0;i < 26;i++)
		nxt[n + 1][i] = n + 1;
	for (int i = n;i >= 1;i--)
	{
		memcpy(nxt[i],nxt[i + 1],sizeof(nxt[i]));
		nxt[i][s[i - 1] - 'a'] = i;
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> tp;
		if (tp == '+')
		{
			cin >> x >> c;
			T[x - 1].add(c - 'a');
		}
		else
		{
			cin >> x;
			T[x - 1].rollback();
		}
		ans[i][0] = T[0].cur;
		ans[i][1] = T[1].cur;
		ans[i][2] = T[2].cur;
	}
	for (int i = 1;i <= T[0].id;i++)
		for (int j = 1;j <= T[1].id;j++)
			for (int k = 1;k <= T[2].id;k++)
				f[ID(i,j,k)] = n + 1;
	f[ID(1,1,1)] = 0;
	for (int i = 1;i <= T[0].id;i++)
		for (int j = 1;j <= T[1].id;j++)
			for (int k = 1;k <= T[2].id;k++)
				if (f[ID(i,j,k)] != n + 1)
				{
					for (int l = T[0].first[i];l;l = T[0].edge[l].nxt)
						f[ID(T[0].edge[l].to,j,k)] = min(f[ID(T[0].edge[l].to,j,k)],nxt[f[ID(i,j,k)] + 1][T[0].edge[l].c]);
					for (int l = T[1].first[j];l;l = T[1].edge[l].nxt)
						f[ID(i,T[1].edge[l].to,k)] = min(f[ID(i,T[1].edge[l].to,k)],nxt[f[ID(i,j,k)] + 1][T[1].edge[l].c]);
					for (int l = T[2].first[k];l;l = T[2].edge[l].nxt)
						f[ID(i,j,T[2].edge[l].to)] = min(f[ID(i,j,T[2].edge[l].to)],nxt[f[ID(i,j,k)] + 1][T[2].edge[l].c]);
				}
	for (int i = 1;i <= q;i++)
		puts(f[ID(ans[i][0],ans[i][1],ans[i][2])] <= n ? "YES" : "NO");
	return 0;
}