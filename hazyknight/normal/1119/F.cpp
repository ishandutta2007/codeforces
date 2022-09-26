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
#include <bitset>

using namespace std;

typedef long long ll;

const int MAXN = 250005;
const ll INF = 1000000000000ll;

struct Edge
{
	int to;
	ll val;
	bool operator < (const Edge &p)const
	{
		if (val == p.val)
			return to < p.to;
		return val < p.val;
	}
};

int n;
int p[MAXN];
int sz[MAXN];

ll ans;
ll f[MAXN][2];
ll sum[MAXN];

bool vis[MAXN];

set<Edge> e[MAXN];
priority_queue<ll> Q[MAXN];

bool cmp(const int &a,const int &b)
{
	return e[a].size() < e[b].size();
}

ll doit(int u,priority_queue<ll> &Q,vector<ll> &ch,int rq)
{
	vector<ll> rollback1,rollback2;
	ll res = sum[u];
	while (rq > 0)
	{
		res += ch.back();
		rollback2.push_back(ch.back());
		ch.pop_back();
		rq--;
	}
	while (rq < 0)
	{
		res -= Q.top();
		rollback1.push_back(Q.top());
		Q.pop();
		rq++;
	}
	while (ch.size())
	{
		ll vQ = (Q.empty() ? 0 : -Q.top()),vC = ch.back();
		if (vQ + vC >= 0)
			break;
		res += vQ + vC;
		if (!Q.empty())
		{
			rollback1.push_back(Q.top());
			Q.pop();
		}
		rollback2.push_back(ch.back());
		ch.pop_back();
	}
	for (int i = 0;i < rollback1.size();i++)
		Q.push(rollback1[i]);
	for (int i = rollback2.size() - 1;i >= 0;i--)
		ch.push_back(rollback2[i]);
	return res;
}

void dfs(int u,int K)
{
//	cout << "in:" << u << endl;
	vis[u] = 1;
	vector<ll> ch;
	ll S = 0;
	for (set<Edge>::iterator i = e[u].begin();i != e[u].end();i++)
		if (!vis[i->to])
		{
			dfs(i->to,K);
			S += f[i->to][0];
			ch.push_back(f[i->to][1] - f[i->to][0] + i->val);
		}
	sort(ch.begin(),ch.end());
	reverse(ch.begin(),ch.end());
	if (sz[u] - K - (int)Q[u].size() - (int)ch.size() > 0)
		f[u][0] = INF;
	else
		f[u][0] = doit(u,Q[u],ch,sz[u] - K - (int)Q[u].size()) + S;
	f[u][1] = doit(u,Q[u],ch,sz[u] - K - (int)Q[u].size() - 1) + S;
//	cout << u << ' ' << f[u][0] << ' ' << f[u][1] << endl;
}

int main()
{
	scanf("%d",&n);
	for (int u,v,w,i = 1;i < n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[u].insert((Edge){v,w});
		e[v].insert((Edge){u,w});
	}
	for (int i = 1;i <= n;i++)
	{
		sz[i] = e[i].size();
		p[i] = i;
	}
	sort(p + 1,p + n + 1,cmp);
	for (int i = 0,j = 1;i < n;i++)
	{
		while (j <= n && sz[p[j]] <= i)
		{
			for (set<Edge>::iterator k = e[p[j]].begin();k != e[p[j]].end();k++)
			{
				sum[k->to] += k->val;
				Q[k->to].push(k->val);
				e[k->to].erase((Edge){p[j],k->val});
			}
			j++;
		}
		for (int k = j;k <= n;k++)
		{
			while (Q[p[k]].size() > sz[p[k]] - i)
			{
				sum[p[k]] -= Q[p[k]].top();
				Q[p[k]].pop();
			}
			vis[p[k]] = 0;
		}
		ans = 0;
		for (int k = j;k <= n;k++)
			if (!vis[p[k]])
			{
			//	cout << "GO:" << p[k] << endl;
				dfs(p[k],i);
			//	cout << p[k] << ' '<< f[p[k]][0] << endl;
				ans += f[p[k]][0];
			}
		printf("%I64d ",ans);
	}
	printf("\n");
	return 0;
}