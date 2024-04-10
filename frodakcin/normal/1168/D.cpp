#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

template<class T> bool chkmax(T& a, const T& b) {return a<b?a=b,1:0;}

const int MN = 1.5e5 + 100;
const int MQ = 1.5e5 + 100;
int N, Q;
vector<int> a[MN];
int b[MN];
int v[MN];
int fail;
struct GR
{
	int a[2];
	int c[26], s, p;
	int v[26];
	int sz, len;
};
GR g[MN];int G;
void upd(GR& x, int y)
{
	if(!~x.a[0]) return;
	if(x.s > x.len) fail--;
	x.s -= x.c[y];
	x.c[y] = max(g[x.a[0]].c[y]+g[x.a[0]].v[y], g[x.a[1]].c[y]+g[x.a[1]].v[y]);
	x.s += x.c[y];
	if(x.s > x.len) fail++;
}
char t;
vector<int> a2[MN];
void dfs(int n = 1)
{
	for(int x : a[n]) dfs(x);
	if(a[n].empty()||a[n].size() == 2)
	{
		b[n] = G;
		g[G].sz = 1;
		if(a[n].size() == 2)
		{
			int z = 0;
			for(int x : a[n])
			{
				g[G].a[z++] = b[x];
				g[b[x]].p = G;
				g[G].len = g[b[x]].len + g[b[x]].sz;
				for(int i = 0;i < 26;i++)
					chkmax(g[G].c[i], g[b[x]].c[i] + g[b[x]].v[i]);
			}
			for(int i = 0;i < 26;i++)
				g[G].s += g[G].c[i];
			fail += g[G].s > g[G].len;
		}
		else
		{
			g[G].a[0] = g[G].a[1] = -1;
			g[G].len = 0;
		}
		G++;
	}
	else
	{
		int x = a[n][0];
		b[n] = b[x];
		g[b[n]].sz++;
	}
	if(~v[n])
		g[b[n]].v[v[n]]++;
	//printf("%d %d %d %d\n", n, b[n], g[b[n]].len, g[b[n]].sz);
}
int f[26], val;
void answer(void)
{
	if(fail) printf("Fou\n");
	else
	{
		printf("Shi ");
		int x = b[1], extra = 0;
		for(int i = 0;i < 26;i++)
			extra += f[i] = g[x].c[i] + g[x].v[i];
		extra = g[x].len + g[x].sz - 1 - extra;
		val = 0;
		for(int i = 0;i < 26;i++)
			val += (i+1) * (f[i] + extra);
		printf("%d\n", val);
	}
}
void upd(void)
{
	int n, k;
	scanf("%d %c", &n, &t);
	k = t=='?'?-1:t-'a';
	if(k == v[n]) return;
	if(~v[n]) g[b[n]].v[v[n]]--;
	if(~k) g[b[n]].v[k]++;
	for(int i = g[b[n]].p;i;i = g[i].p)
	{
		if(~v[n]) upd(g[i], v[n]);
		if(~k) upd(g[i], k);
	}
	v[n] = k;
}
int main(void)
{
	G = 1;
	scanf("%d%d", &N, &Q);
	v[1] = -1;
	for(int i = 2, k;i <= N;i++)
		scanf("%d %c", &k, &t), a[k].push_back(i), v[i] = t=='?'?-1:t-'a';
	dfs();
	for(int i = 0;i < Q;i++)
		upd(), answer();
	return 0;
}