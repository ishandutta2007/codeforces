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

using namespace std;

typedef double db;

const int MAXN = 200005;

struct Set
{
	priority_queue<pair<db,int> > Q,rQ;
	
	void insert(pair<db,int> a)
	{
		Q.push(a);
	}
	
	void erase(pair<db,int> a)
	{
		rQ.push(a);
	}
	
	pair<db,int> MX()
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		return Q.top();
	}
	
	bool empty()
	{
		return Q.size() == rQ.size();
	}
}in,out;

int n,t,q;
int p[MAXN];
int l[MAXN];
int cnt[MAXN];

db ans;

db getval(int u,int t)
{
	return (db)p[u] * l[u] / (l[u] + t - 1) / (l[u] + t);
}

db getsum(int u,int t)
{
	return (db)p[u] * t / (l[u] + t);
}

void add()
{
	db val = out.MX().first;
	int id = out.MX().second;
	out.erase(out.MX());
	if (cnt[id])
		in.erase(make_pair(-getval(id,cnt[id]),id));
	t--;
	ans += val;
	cnt[id]++;
	in.insert(make_pair(-getval(id,cnt[id]),id));
	if (cnt[id] < l[id])
		out.insert(make_pair(getval(id,cnt[id] + 1),id));
}

void ers()
{
	db val = -in.MX().first;
	int id = in.MX().second;
	in.erase(in.MX());
	if (cnt[id] < l[id])
		out.erase(make_pair(getval(id,cnt[id] + 1),id));
	t++;
	ans -= val;
	cnt[id]--;
	out.insert(make_pair(getval(id,cnt[id] + 1),id));
	if (cnt[id])
		in.insert(make_pair(-getval(id,cnt[id]),id));
}

int main()
{
	scanf("%d%d%d",&n,&t,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&p[i]);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&l[i]);
		out.insert(make_pair(getval(i,1),i));
	}
	while (t && !out.empty())
		add();
	for (int tp,u,i = 1;i <= q;i++)
	{
		scanf("%d%d",&tp,&u);
		ans -= getsum(u,cnt[u]);
		if (cnt[u] < l[u])
			out.erase(make_pair(getval(u,cnt[u] + 1),u));
		if (cnt[u])
			in.erase(make_pair(-getval(u,cnt[u]),u));
		if (tp == 1)
		{
			l[u]++;
			if (cnt[u])
			{
				t++;
				cnt[u]--;
			}
		}
		else
		{
			l[u]--;
			if (cnt[u] > l[u])
			{
				t++;
				cnt[u]--;
			}
		}
		ans += getsum(u,cnt[u]);
		if (cnt[u] < l[u])
			out.insert(make_pair(getval(u,cnt[u] + 1),u));
		if (cnt[u])
			in.insert(make_pair(-getval(u,cnt[u]),u));
		while (t && !out.empty())
			add();
		while (!in.empty() && -in.MX().first < out.MX().first)
		{
			ers();
			add();
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}