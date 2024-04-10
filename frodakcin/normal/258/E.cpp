#include <iostream>
#include <cstdio>

#include <vector>
#include <set>
#include <functional>
#include <utility>
#include <algorithm>

#include <cassert>

using namespace std;

const int MN = 1e5 + 100;

int N, M;
using vi = vector<int>;
#define pb push_back
#define ALL(X) X.begin(),X.end()

vi a[MN];

int o[MN][2];
int p[MN], s[MN];
int dfs(int n = 1, int * c = new int(0))
{
	o[n][0] = (*c)++;
	s[n] = 1;
	for(int x : a[n])
		if(x != p[n])
			p[x] = n, s[n] += dfs(x, c);
	o[n][1] = *c;
	return s[n];
}
bool anc(int x, int y)
{
	return o[x][0] <= o[y][0] && o[x][1] >= o[y][1];
}
bool self[MN];
vi other[MN];
int f[MN];
using comp = function<bool(int, int)>;
const comp cmpo = [](int a, int b){return o[a][0] < o[b][0];};
template<int MS = MN*3> struct C
{
public:
	int s;
	int v[MS], c[MS];
	int z[MS];
	void init(int n, int l, int r)
	{
		if(r-l>1)
		{
			int m = l + (r-l>>1);
			init(n<<1, l, m), init(n<<1|1, m, r);
		}
		v[n] = 0, c[n] = r-l;
		z[n] = 0;
	}
	void init(int s)
	{
		this->s = s;
		init(1, 0, s);
	}
	void addv(int n, int l, int r, int q)
	{
		v[n] += q;
		z[n] += q;
	}
	void down(int n, int l, int r)
	{
		if(!z[n])
			return;
		if(r-l>1)
		{
			int m = l + (r-l>>1);
			addv(n<<1, l, m, z[n]), addv(n<<1|1, m, r, z[n]);
		}
		z[n] = 0;
	}
	void up(int n)
	{
		if(v[n<<1] < v[n<<1|1])
			v[n] = v[n<<1], c[n] = c[n<<1];
		else if(v[n<<1|1] < v[n<<1])
			v[n] = v[n<<1|1], c[n] = c[n<<1|1];
		else
			v[n] = v[n<<1], c[n] = c[n<<1|1] + c[n<<1];
	}
	void add(int n, int l, int r, int ql, int qr)
	{
		if(ql <= l&&r <= qr)
			return addv(n, l, r, 1);
		int m = l + (r-l>>1);
		down(n, l, r);
		if(ql < m) add(n<<1, l, m, ql, qr);
		if(m < qr) add(n<<1|1, m, r, ql, qr);
		up(n);
	}
	void sub(int n, int l, int r, int ql, int qr)
	{
		if(ql <= l&&r <= qr)
			return addv(n, l, r, -1);
		int m = l + (r-l>>1);
		down(n, l, r);
		if(ql < m) sub(n<<1, l, m, ql, qr);
		if(m < qr) sub(n<<1|1, m, r, ql, qr);
		up(n);
	}
	int qry(void)
	{
		if(v[1])
			return s;
		return s - c[1];
	}
	void add(int x)
	{
		add(1, 0, s, o[x][0], o[x][1]);
	}
	void rem(int x)
	{
		sub(1, 0, s, o[x][0], o[x][1]);
	}
};
C<> c;
vi temp;
void dfsf(int n = 1)
{
	for(int x : other[n])
		c.add(x);
	f[n] = c.qry();
	for(int x : a[n])
		if(x != p[n])
			dfsf(x);
	for(int x : other[n])
		c.rem(x);
}
int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 0, u, v;i < N-1;i++)
		scanf("%d%d", &u, &v), a[u].pb(v), a[v].pb(u);
	dfs();
	c.init(N);
	for(int i = 0, a, b;i < M;i++)
	{
		scanf("%d%d", &a, &b);
		if(anc(a, b))
			self[a] = 1;
		else if(anc(b, a))
			self[b] = 1;
		else
			self[a] = self[b] = 1, other[a].pb(b), other[b].pb(a);
	}
	for(int i = 1;i <= N;i++)
	{
		if(self[i])
			other[i].pb(i);
		sort(ALL(other[i]), cmpo);
		for(int j = 0, k;j < other[i].size();j=k)
		{
			temp.pb(other[i][j]);
			for(k=j+1;k < other[i].size()&&o[other[i][j]][1] >= o[other[i][k]][1];k++);
		}
		other[i].assign(temp.begin(), temp.end());
		temp.clear();
	}
	dfsf();
	for(int i = 1;i <= N;i++)
		printf("%d%c", f[i]-!!f[i], " \n"[i==N]);
	return 0;
}