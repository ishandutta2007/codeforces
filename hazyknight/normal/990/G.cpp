#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int INF = (1 << 30) - 1;
const int lim = 200;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,id,tot;
int SIZE,root;
int w[MAXN];
int first[MAXN];
int MAX[MAXN];
int size[MAXN];
int q[MAXN];
int cnt[MAXN];

ll tmp[MAXN];
ll aans[MAXN];
ll ans[MAXN];

bool mark[MAXN];
bool ok[MAXN];

int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}

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
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getroot(edge[i].to,now);
			size[now] += size[edge[i].to];
			MAX[now] = max(MAX[now],size[edge[i].to]);
		}
	MAX[now] = max(MAX[now],SIZE - size[now]);
	if (MAX[now] < MAX[root])
		root = now;
}

void getsize(int now,int fa)
{
	size[now] = 1;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getsize(edge[i].to,now);
			size[now] += size[edge[i].to];
		}
}

void doroot(int now,int fa,int v)
{
	v = gcd(v,w[now]);
	aans[v]++;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa && !mark[edge[i].to])
			doroot(edge[i].to,now,v);
}

void getgcd(int now,int fa,int v)
{
	v = gcd(v,w[now]);
	q[++tot] = v;
	cnt[v]++;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa && !mark[edge[i].to])
			getgcd(edge[i].to,now,v);
}

void getans(int mul)
{
	if ((ll)tot * tot <= 800000)
	{
		for (int i = 1;i <= tot;i++)
			for (int j = i;j <= tot;j++)
			{
				if (i == j)
					aans[q[i]] += (ll)cnt[q[i]] * (cnt[q[i]] - 1) / 2 * mul;
				else
					aans[gcd(q[i],q[j])] += (ll)cnt[q[i]] * cnt[q[j]] * mul;
			}
	}
	else
	{
		int MAX = 0;
		for (int i = 1;i <= tot;i++)
			MAX = max(MAX,q[i]);
		for (int i = 1;i <= MAX;i++)
		{
			ll sum = 0;
			for (int j = i;j <= MAX;j += i)
				sum += cnt[j];
			tmp[i] = sum * (sum - 1) / 2;
		}
		for (int i = MAX;i >= 1;i--)
			for (int j = i + i;j <= n;j += i)
				tmp[i] -= tmp[j];
		for (int i = 1;i <= MAX;i++)
			ans[i] += tmp[i] * mul;
	}
}

void calc(int now)
{
	doroot(now,0,0);
	tot = 0;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
			getgcd(edge[i].to,now,w[now]);
	sort(q + 1,q + tot + 1);
	tot = unique(q + 1,q + tot + 1) - q - 1;
	getans(1);
	for (int i = 1;i <= tot;i++)
		cnt[q[i]] = 0;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
		{
			tot = 0;
			getgcd(edge[i].to,now,w[now]);
			sort(q + 1,q + tot + 1);
			tot = unique(q + 1,q + tot + 1) - q - 1;
			getans(-1);
			for (int j = 1;j <= tot;j++)
				cnt[q[j]] = 0;
		}
}

void solve(int now)
{
	mark[now] = true;
	calc(now);
	getsize(now,0);
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
		{
			SIZE = size[edge[i].to];
			root = 0;
			getroot(edge[i].to,now);
			solve(root);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> w[i];
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	MAX[root = 0] = INF;
	SIZE = n;
	getroot(1,0);
	solve(root);
	for (int i = 1;i <= 200000;i++)
		if (aans[i] + ans[i])
			cout << i << ' ' << aans[i] + ans[i] << endl;
	return 0;
}