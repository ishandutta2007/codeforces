#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <queue>

using namespace std;

const int MAXN = 100005;
const int INF = (1 << 30) - 1;

struct Edge
{
	int to;
	int len;
	int next;
}edge[MAXN << 1];

struct Query
{
	int l,r;
	int lim;
	bool operator < (const Query &p)const
	{
		return lim < p.lim;
	}
}query[MAXN];

struct Node
{
	int l,w;
	int id;
}deep[MAXN];

int n,L,W,id;
int tot,q;
int first[MAXN];
int root,SIZE;
int size[MAXN];
int MAX[MAXN];
int sum[MAXN];

long long ans;

bool mark[MAXN];

bool cmp1(const Node &a,const Node &b)
{
	return a.w < b.w;
}

bool cmp2(const Node &a,const Node &b)
{
	return a.l < b.l;
}

inline void add(int x,int v)
{
	while (x <= tot)
	{
		sum[x] += v;
		x += (x & -x);
	}
}

inline int ask(int x)
{
	int ret = 0;
	while (x >= 1)
	{
		ret += sum[x];
		x -= (x & -x);
	}
	return ret;
}

inline void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,first[u]};
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
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getsize(edge[i].to,now);
			size[now] += size[edge[i].to];
		}
}

void getdeep(int now,int fa,int w,int l)
{
	++tot;
	deep[tot].w = w;
	deep[tot].l = l;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa && !mark[edge[i].to])
			getdeep(edge[i].to,now,w + edge[i].len,l + 1);
}

inline void pushquery(int l,int r,int lim)
{
	query[++q] = (Query){l,r,lim};
}

inline long long answer()
{
	sort(query + 1,query + q + 1);
	sort(deep + 1,deep + tot + 1,cmp2);
	int j = 1;
	long long ret = 0;
	for (int i = 1;i <= q;i++)
	{
	//	cout << i << ' ' << query[i].l << ' ' << query[i].r << endl;
		while (j <= tot && deep[j].l <= query[i].lim)
		{
			add(deep[j].id,1);
			j++;
		}
	//	cout << query[i].r << ' ' << query[i].l - 1 << endl;
	//	cout << "minus" << ask(query[i].r) << ' ' << ask(query[i].l - 1) << endl;
		ret += ask(query[i].r) - ask(query[i].l - 1);
	}
	for (int i = 1;i < j;i++)
		add(deep[i].id,-1);
	return ret;
}

inline long long cnt()
{
	int l = 1,r = tot;
	q = 0;
	while (l < r)
	{
		while (l < r && deep[l].w + deep[r].w > W)
			r--;
	//	cout << "addQ:" << l + 1 << ' ' << r << ' ' << L - deep[l].l << endl;
		pushquery(l + 1,r,L - deep[l].l);
		l++;
	}
//	cout << answer() << endl;
	return answer();
}

inline void calc(int now)
{
//	long long tmp = ans;
	tot = 0;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
			getdeep(edge[i].to,now,edge[i].len,1);
	sort(deep + 1,deep + tot + 1,cmp1);
	for (int i = 1;i <= tot;i++)
		deep[i].id = i;
//	for (int i = 1;i <= tot;i++)
//		cout << deep[i].w << ' ' << deep[i].l << endl;
	for (int i = 1;i <= tot;i++)
		if (deep[i].w <= W && deep[i].l <= L)
			ans++;
	ans += cnt();
//	cout << "here" << endl;
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
		{
			tot = 0;
			getdeep(edge[i].to,now,edge[i].len,1);
			sort(deep + 1,deep + tot + 1,cmp1);
			for (int j = 1;j <= tot;j++)
				deep[j].id = j;
			ans -= cnt();
		}
//	cout << "calc:" << now << endl;
//	cout << ans - tmp << endl;
//	cout << "----------------------" << endl;
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
		//	cout << "fa[" << root << "]=" << now << endl;
			solve(root);
		}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin >> n >> L >> W;
	for (int u,v,c,i = 1;i < n;i++)
	{
		cin >> u >> c;
		v = i + 1;
		addE(u,v,c);
		addE(v,u,c);
	}
	MAX[root = 0] = INF;
	SIZE = n;
	getroot(1,0);
	solve(root);
	cout << ans << endl;
	return 0;
}