#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const ll MOD = 998244353;

struct Node
{
	int ch[2],tp,S,sz;
}node[MAXN << 1];

int rt,T,n,m,id;

ll fac[MAXN << 1];
ll inv[MAXN << 1];

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

void update(int u)
{
	node[u].sz = node[node[u].ch[0]].sz + node[u].S + node[node[u].ch[1]].sz;
}

void link(int u,int v,bool dir)
{
	node[u].ch[dir] = v;
	update(u);
}

pair<int,int> split(int u,int k)
{
	if (!u)
		return make_pair(0,0);
	if (!k)
		return make_pair(0,u);
	if (k <= node[node[u].ch[0]].sz)
	{
		pair<int,int> res = split(node[u].ch[0],k);
		link(u,res.second,0);
		return make_pair(res.first,u);
	}
	k -= node[node[u].ch[0]].sz;
	if (k < node[u].S)
	{
		id++;
		node[id].ch[0] = node[id].ch[1] = 0;
		node[id].tp = node[u].tp;
		node[id].S = node[u].S - k;
		node[u].S = k;
		link(u,node[u].ch[0],0);
		link(id,node[u].ch[1],1);
		link(u,0,1);
		return make_pair(u,id);
	}
	k -= node[u].S;
	pair<int,int> res = split(node[u].ch[1],k);
	link(u,res.first,1);
	return make_pair(u,res.second);
}

int Rand()
{
	return rand() << 15 | rand();
}

int merge(int u,int v)
{
	if (!u || !v)
		return u | v;
	if (Rand() % (node[u].sz + node[v].sz) + 1 <= node[u].sz)
	{
		link(u,merge(node[u].ch[1],v),1);
		return u;
	}
	link(v,merge(u,node[v].ch[0]),0);
	return v;
}

void addSeg(int l,int r)
{
	if (l > r)
		return;
	node[++id].S = r - l + 1;
	node[id].sz = node[id].S;
	node[id].ch[0] = node[id].ch[1] = node[id].tp = 0;
	rt = merge(rt,id);
}

void print(int u)
{
	if (!u)
		return;
	print(node[u].ch[0]);
	cerr << node[u].S << ',' << node[u].tp << ' ';
	print(node[u].ch[1]);
}

int main()
{
	int N = 400000;
	fac[0] = 1;
	for (int i = 1;i <= N;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[N] = power(fac[N],MOD - 2);
	for (int i = N;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		int lst = 0;
		rt = id = 1;
		node[1].S = node[1].sz = 1;
		node[1].ch[0] = node[1].ch[1] = node[1].tp = 0;
		for (int x,y,i = 1;i <= m;i++)
		{
			scanf("%d%d",&x,&y);
			if (x == y)
				continue;
			y++;
			addSeg(lst + 1,x - 1);
			pair<int,int> r = split(rt,y - 1);
			pair<int,int> r2 = split(r.first,y - 2);
			node[r2.second].tp = 0;
			node[++id].S = 1;
			node[id].sz = node[id].S;
			node[id].tp = 1;
			node[id].ch[0] = node[id].ch[1] = 0;
			rt = merge(merge(r2.first,r2.second),merge(id,r.second));
			lst = x;
		}
		addSeg(lst + 1,n);
		int cnt = 0;
		for (int i = 2;i <= id;i++)
			cnt += node[i].tp * node[i].S;
		printf("%lld\n",C(n + n - cnt - 1,n));
	}
	return 0;
}