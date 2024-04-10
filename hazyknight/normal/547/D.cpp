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

typedef set<pair<int,int> >::iterator itr;

const int MAXN = 200005;

int n,N,id;
int x[MAXN];
int y[MAXN];
int ans[MAXN << 1];
int ch[MAXN << 1][3];

set<pair<int,int> > L[MAXN];
set<pair<int,int> > R[MAXN];

void dfs(int u)
{
	if (u <= n)
		return;
	ans[ch[u][1]] = !(ans[ch[u][0]] = ans[ch[u][2]] = ans[u]);
	dfs(ch[u][0]);
	dfs(ch[u][1]);
	dfs(ch[u][2]);
}

void erase(int u,int v,int ID)
{
	L[u].erase(make_pair(ID,v));
	R[v].erase(make_pair(ID,u));
}

int main()
{
	scanf("%d",&n);
	N = 200000;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		L[x[i]].insert(make_pair(i,y[i]));
		R[y[i]].insert(make_pair(i,x[i]));
	}
	id = n;
	memset(ans,-1,sizeof(ans));
	for (int i = 1;i <= N;i++)
		for (itr j = L[i].begin();L[i].size() > 1 && j != L[i].end();)
		{
			if (R[j->second].size() == 1)
			{
				j++;
				continue;
			}
			itr k = R[j->second].begin();
			if (k->first == j->first)
				k++;
			if (k->second == i)
			{
				ans[j->first] = 0;
				ans[k->first] = 1;
				dfs(j->first);
				dfs(k->first);
				itr nxt = j;
				nxt++;
				if (nxt != L[i].end() && nxt->first == k->first)
					nxt++;
				erase(i,j->second,k->first);
				erase(i,j->second,j->first);
				j = nxt;
				continue;
			}
			itr l = L[i].begin();
			if (l == j)
				l++;
			id++;
			ch[id][0] = l->first;
			ch[id][1] = j->first;
			ch[id][2] = k->first;
			int u = k->second,v = l->second;
			erase(i,l->second,l->first);
			erase(k->second,j->second,k->first);
			itr nxt = j;
			nxt++;
			erase(i,j->second,j->first);
			j = nxt;
			L[u].insert(make_pair(id,v));
			R[v].insert(make_pair(id,u));
		}
	for (int i = 1;i <= N;i++)
	{
		if (L[i].size() > 1)
		{
			int op = 0;
			for (itr j = L[i].begin();j != L[i].end();j++,op ^= 1)
			{
				ans[j->first] = op;
				dfs(j->first);
			}
		}
		if (R[i].size() > 1)
		{
			int op = 0;
			for (itr j = R[i].begin();j != R[i].end();j++,op ^= 1)
			{
				ans[j->first] = op;
				dfs(j->first);
			}
		}
	}
	for (int i = 1;i <= N;i++)
		if (L[i].size() == 1 && ans[L[i].begin()->first] == -1)
		{
			ans[L[i].begin()->first] = 0;
			dfs(L[i].begin()->first);
		}
	for (int i = 1;i <= n;i++)
		putchar(ans[i] ? 'b' : 'r');
	putchar('\n');
	return 0;
}