#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn = 400000, maxt = 200000, mod = 998244353;
int test, n, m, x[222222], y[222222];
int ls[222222], rs[222222], sz[222222], rd[222222], rt, l, r, rt1, rt2, rt3, cnt, jc[444444], injc[444444], key[222222], tag[222222];
bool flg;
int binpow(int a, int t)
{
	int res = 1, p = a;
	for (int i = t; i; i >>= 1)
	{
		if (i & 1) res = 1ll * res * p % mod;
		p = 1ll * p * p % mod;
	}
	return res;
}
void Init()
{
	jc[0] = 1;
	for (int i = 1; i <= maxn; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
	injc[maxn] = binpow(jc[maxn], mod - 2);
	for (int i = maxn - 1; i >= 0; i--) injc[i] = 1ll * injc[i + 1] * (i + 1) % mod; 
}
int C(int n, int k)
{
	return 1ll * jc[n] * injc[k] % mod * injc[n - k] % mod;
}
void pushup(int x)
{
	sz[x] = sz[ls[x]] + sz[rs[x]] + 1;
}
void push(int node, int x)
{
	key[node] += x;
	tag[node] += x;
}
void pushdown(int node)
{
	if (tag[node])
	{
		if (ls[node]) push(ls[node], tag[node]);
		if (rs[node]) push(rs[node], tag[node]);
		tag[node] = 0;
	}
}
int merge(int x, int y)
{
	if (!x || !y) return x ^ y;
	pushdown(x); pushdown(y);
	if (rd[x] <= rd[y])
	{
		rs[x] = merge(rs[x], y);
		pushup(x);
		return x;
	}
	else
	{
		ls[y] = merge(x, ls[y]);
		pushup(y);
		return y;
	}
}
void split(int x, int &rt1, int &rt2, int y)
{
	if (!x) 
	{
		rt1 = rt2 = 0;
		return;
	}
	pushdown(x);
	if (key[x] == y) flg = 1;
	if (key[x] >= y)
	{
		rt2 = x;
		split(ls[x], rt1, ls[rt2], y);
		pushup(x);
	}
	else
	{
		rt1 = x;
		split(rs[x], rs[rt1], rt2, y);
		pushup(x);
	}
}
void Out(int x)
{
	if (!x) return;
	pushdown(x);
	Out(ls[x]);
	printf("%d ", key[x]);
	Out(rs[x]);
}
int main()
{
	scanf("%d", &test);
	Init();
	srand(time(0));
	for (int i = 1; i <= maxt; i++) rd[i] = i;
	random_shuffle(rd + 1, rd + maxt + 1);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		rt = 0; cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			if (y[i] == 1)
			{
				++ cnt;
				sz[cnt] = 1;
				key[cnt] = 1;
				tag[cnt] = 0;
				ls[cnt] = rs[cnt] = 0;
				push(rt, 1);
				rt = merge(cnt, rt);
			}
			else
			{
				flg = 0;
				split(rt, rt1, rt2, y[i] - 1);
			//	cout << flg << endl;
				if (!flg)
				{
					++ cnt;
					sz[cnt] = 1;
					key[cnt] = y[i] - 1;
					tag[cnt] = 0;
					ls[cnt] = rs[cnt] = 0;
					rt3 = merge(cnt, rt2);
					push(rt3, 1);
					rt = merge(rt1, rt3);
				}
				else
				{
					push(rt2, 1);
					rt = merge(rt1, rt2);
				}
			}
		//	Out(rt);
		//	printf("\n");
		}
	//	cout << cnt << endl;
		printf("%d\n", C(n + n - 1 - cnt, n));
	}
	return Accepted;
}