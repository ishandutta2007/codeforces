#include <cstdio>
#include <map>
#include <vector>
#include <cassert>

const int MN = 2e5 + 100;
const int MM = 2e5 + 100;
int N, M;

struct E
{
public:
	int u, v;
	E(int a = -1, int b = -1)
	{
		if(b < a) std::swap(a, b);
		u = a, v = b;
	}
	E nex(void) {return {u%N+1, v%N+1};}
	bool operator < (E o) const {return u < o.u || (!(o.u < u) && v < o.v);}
	bool operator == (E o) const {return u == o.u && v == o.v;}
};
struct DSU
{
private:
	int p[MN], r[MN];
	int * t[MN*40], v[MN*40], X;
public:
	int getX(void) {return X;}
	int set(int * a, int b)
	{
		if(*a != b) t[X] = a, v[X] = *a, *a = b, ++X;
		return b;
	}
	void rollback(int x) {for(;X>x;) --X, *t[X] = v[X];}
	int f(int n) {return p[n] ? set(p+n, f(p[n])) : n;}
	bool m(int a, int b)
	{
		a = f(a), b = f(b);
		if(a==b) return 0;
		if(r[b]>r[a]) std::swap(a,b);
		if(r[a]==r[b]) set(r+a, r[a]+1);
		return set(p+b, a), 1;
	}
	bool m(E x) {return m(x.u, x.v);}
	bool check(E x) {return f(x.u) == f(x.v);}
};
DSU dsu;
struct U
{
public:
	int t;
	bool b;
};
std::vector<U> u[MM*2];
struct C
{
public:
	int e, i;
};

bool f[MM];
int g[MM][3];
E e[MM*2];
bool a[MM*2];//active
std::map<E, int> m;
C c[MM*16]; int cc;

void dfs(int l, int r, C * c, int L)
{
	int X = dsu.getX();
	int m = l+(r-l)/2;
	int k = 0;
	for(int i = 0, e, j;i < L;++i)
	{
		e = c[i].e;
		j = c[i].i;
		for(;j+1<u[e].size() && u[e][j+1].t < l;++j);
		c[i].i = j;
		if(u[e][j].t >= r) continue;
		if(u[e][j].t < l && (j+1==u[e].size() || u[e][j+1].t >= r))
		{
			if(a[e])
				dsu.m(::e[e]);//printf("l: %d, r: %d, insert %d [%d,%d]\n", l, r, e, ::e[e].u, ::e[e].v);
			continue;
		}
		c[L+k++] = {e, j};
	}
	if(r-l==1)
		if(g[l][0] == 2)
			f[l] = f[l-1] ? dsu.check(E{g[l][1], g[l][2]}.nex()) : dsu.check(E{g[l][1], g[l][2]});
		else 
			f[l] = f[l-1], a[g[l][1+f[l]]]^=1;
	else
	{
		dfs(l, m, c+L, k);
		dfs(m, r, c+L, k);
	}
	//printf("under [%d, %d]: ", l, r); for(int i = 1;i <= 5;++i) printf("%d%c", dsu.f(i), " \n"[i==5]);
	dsu.rollback(X);
}

int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 1, t, x, y;i <= M;i++)
	{
		scanf("%d%d%d", &t, &x, &y);
		g[i][0] = t;
		if(t==1)
		{
			std::map<E, int>::iterator it;
			E a = {x,y};
			int z;
			if((it=m.find(a))==m.end()) z = m.size(), m.insert({a, z}), e[z]=a, c[cc++] = {z, 0};
			else z = it->second;
			u[z].push_back({i, 0});
			g[i][1] = z;

			a = a.nex();
			if((it=m.find(a))==m.end()) z = m.size(), m.insert({a, z}), e[z]=a, c[cc++] = {z, 0};
			else z = it->second;
			u[z].push_back({i, 1});
			g[i][2] = z;
		}
		else
			g[i][1] = x, g[i][2] = y;
	}
	//for(std::pair<E, int> x : m) printf("edge %d = [%d, %d]\n", x.second, x.first.u, x.first.v);
	dfs(1, M+1, c, cc);
	for(int i = 1;i <= M;i++)
		if(g[i][0] == 2)
		printf("%d", f[i]);
	printf("\n");
	return 0;
}