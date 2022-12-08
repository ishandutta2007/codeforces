#include <iostream>
#include <cstdio>

#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <bitset>

using namespace std;

const int MN = 1e5 + 100;
const int MM = 1e5 + 100;
const int MQ = 1e5 + 100;
const int MC = MM<<1;

const int K = 410;
const int L = 510;

template<int MS> struct DSU
{
	int p[MS];
	int s[MS], r[MS];
	DSU(void)
	{
		for(int i = 0;i < MS;i++)
		{
			p[i] = i;
			s[i] = 1, r[i] = 0;
		}
	}
	int f(int n)
	{
		if(p[n]==n)return n;
		return p[n] = f(p[n]);
	}
	bool m(int a, int b)
	{
		a = f(a), b = f(b);
		if(a==b) return 0;
		if(r[a] < r[b]) swap(a, b);
		r[a] += (r[a]==r[b]), s[a]+=s[b];
		r[b] = -1, s[b] = 0;
		p[b] = a;
		return 1;
	}
};
DSU<MC> d;
using mii = map<int, int>;
#define IT iterator
using pii = pair<int, int>;
using mit = mii::IT;
#define ss second
using vi = vector<int>;
#define pb push_back
#define sz size()
template<int T> using bs = bitset<T>;
mii m[MN];
int C;
int get(mii& x, int v)
{
	mit it;
	if((it=x.find(v))==x.end())
		return x.insert({v, C}), C++;
	else
		return it->ss;
}

int N, M, Q;
vi a, b;
int f[L][MN];
int l[MN];
vi s[MN];
bs<MC> u;
int common(const vi& a, const vi& b)
{
	int i = 0, r = 0;
	for(int x : a)
	{
		for(;i<b.sz&&b[i]<x;)
			i++;
		if(i==b.sz) break;
		r += x==b[i];
	}
	return r;
}
int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 0, a, b, c;i < M;i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		a = get(m[a], c);
		b = get(m[b], c);
		d.m(a, b);
	}
	for(int i = 1;i <= N;i++)
	{
		for(pii x : m[i])
			s[i].pb(d.f(x.ss));
		sort(s[i].begin(), s[i].end());
		if(s[i].sz < K)
		{
			l[i] = b.sz;
			b.pb(i);
		}
		else
		{
			l[i] = a.sz;
			a.pb(i);
		}
	}
	for(int i = 0, x;i < a.sz;i++)
	{
		x = a[i];
		for(int y : s[x])
			u[y] = 1;
		f[i][x] = s[x].sz;
		for(int y = 1;y <= N;y++)
		{
			if(y==x) continue;
			for(int z : s[y])
				f[i][y] += u[z];
		}
		for(int y : s[x])
			u[y] = 0;
	}
	scanf("%d", &Q);
	for(int i = 0, u, v;i < Q;i++)
	{
		scanf("%d%d", &u, &v);
		if(s[u].sz<K&&s[v].sz<K)
			printf("%d\n", common(s[u], s[v]));
		else
		{
			if(s[u].sz < K) swap(u, v);
			printf("%d\n", f[l[u]][v]);
		}
	}
	return 0;
}