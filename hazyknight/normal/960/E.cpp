#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 200005;
const long long MOD = 1000000007;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int T,n,m,L,R,id;
int SIZE,root;
int MAXdepth;
int MAX[MAXN];
int size[MAXN];
int first[MAXN];

long long ans;
long long tot[2];
long long v[MAXN];
long long val[2][MAXN];

bool mark[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void getroot(int now,int fa)
{
	size[now] = 1;
	MAX[now] = 0;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to] && edge[i].to != fa)
		{
			getroot(edge[i].to,now);
			MAX[now] = max(MAX[now],size[edge[i].to]);
			size[now] += size[edge[i].to];
		}
	MAX[now] = max(MAX[now],SIZE - size[now]);
	if (MAX[now] < MAX[root])
		root = now;
}

void getsize(int now,int fa)
{
	size[now] = 1;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to] && edge[i].to != fa)
		{
			getsize(edge[i].to,now);
			size[now] += size[edge[i].to];
		}
}

void getval(int now,int fa,int depth,long long VAL)
{
	VAL = (v[now] - VAL) % MOD;
	val[depth & 1][++tot[depth & 1]] = VAL;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to] && edge[i].to != fa)
			getval(edge[i].to,now,depth + 1,VAL);
}

long long Count(int now)
{
	long long ret = 0,sum = 0;
	for (int i = 1;i <= tot[0];i++)
		(sum += val[0][i]) %= MOD;
	(ret += sum * tot[0] * 2) %= MOD;
	(ret += v[now] * tot[0] % MOD * tot[0] % MOD) %= MOD;
	sum = 0;
	for (int i = 1;i <= tot[1];i++)
		(sum += val[1][i]) %= MOD;
	(ret += sum * tot[1] * 2) %= MOD;
	(ret -= v[now] * tot[1] % MOD * tot[1] % MOD) %= MOD;
	return ret;
}

void calc(int now)
{
	tot[0] = tot[1] = 0;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
			getval(edge[i].to,now,1,0);
	for (int i = 1;i <= tot[0];i++)
		(ans += (val[0][i] + v[now]) * 2) %= MOD;
	(ans += Count(now)) %= MOD;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
		{
			tot[0] = tot[1] = 0;
			getval(edge[i].to,now,1,0);
			(ans -= Count(now)) %= MOD;
		}
	(ans += v[now]) %= MOD;
}

void solve(int now)
{
	mark[now] = true;
	getsize(now,0);
	calc(now);
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
		{
			root = 0;
			SIZE = size[edge[i].to];
			getroot(edge[i].to,now);
			solve(root);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> v[i];
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	MAX[root = 0] = (1 << 30) - 1;
	SIZE = n;
	getroot(1,0);
	solve(root);
	ans %= MOD;
	if (ans < 0)
		ans += MOD;
	cout << ans << endl;
	return 0;
}