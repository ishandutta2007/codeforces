#include <iostream>
#include <cstdio>

#include <vector>
#include <stack>
#include <algorithm>

#include <cassert>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<class T> bool mx(T& a, const T& b) {return a < b ? a = b, 1 : 0;}

const int MN = 1e5 + 100;
const int MM = 1e5 + 100;

bool test(int a, int b)
{
	int r;
	printf("? %d %d\n", a, b);
	fflush(stdout);
	scanf("%d", &r);
	if(!~r) exit(0);
	return !r;		//reverse edge direction
}

using vi = vector<int>;
#define pb push_back
#define ALL(X) X.begin(),X.end()
#define sz size()
#define pob pop_back()
vi f[MN];
vi r[MN];//forward, reverse

int N, M;

template<int MS> struct DAG
{
public:
	int s;
	vi f[MS], r[MS];
	int c[MS];
	vi v;
	void adde(int a, int b)
	{
		f[a].pb(b);
		r[b].pb(a);
	}
	void fix(int s)
	{
		this->s = s;
		for(int i = 0;i < s;i++)
		{
			sort(ALL(f[i]));
			sort(ALL(r[i]));
			f[i].resize(unique(ALL(f[i]))-f[i].begin());
			r[i].resize(unique(ALL(r[i]))-r[i].begin());
			c[i] = f[i].size();
			if(f[i].empty())
				v.pb(i);
		}
	}
	void remove(int n)
	{
		for(int x : r[n])
			if(!--c[x])
				v.pb(x);
	}
};
DAG<MN> dag;

bool e[MN];

using si = stack<int>;
template<int MS> struct SCC
{
public:
	bool v[MS], u[MS];
	int d[MS], l[MS];
	int c[MS], C;
	vi g[MS];
	si s;
	int t;
	void dfs(int n, int p = -1)
	{
		d[n] = l[n] = t++;
		v[n] = u[n] = 1;
		s.push(n);
		for(int x : f[n])
		{
			if(u[x])
				mn(l[n], d[x]);
			if(v[x])
				continue;
			dfs(x, n);
			mn(l[n], l[x]);
		}
		if(l[n] == d[n])
		{
			for(int x;(x = s.top())!=n;s.pop())
				u[x] = 0, c[x] = C, g[C].pb(x);
			s.pop();
			u[n] = 0;
			c[n] = C;
			g[C].pb(n);
			C++;
		}
	}
	void scc(void)
	{
		t = 0;
		for(int i = 0;i <= N;i++)
			v[i] = 0;
		for(int i = 1;i <= N;i++)
			if(e[i]&&!v[i])
				dfs(i);
	}
};
SCC<MN> scc;

int main(void)		//since i misread problem, ill just do some bullshit to correct it
{
	scanf("%d%d", &N, &M);
	
	for(int i = 0, u, v;i < M;i++)
		scanf("%d%d", &u, &v), f[v].pb(u), r[u].pb(v), e[u] = e[v] = 1;		//reverse edges
	for(int i = 1;i <= N;i++)
		scc.c[i] = -1;
	scc.scc();
	for(int i = 1;i <= N;i++)
		if(scc.c[i] != -1)
			for(int x : f[i])
				if(scc.c[x] != -1 && scc.c[x] != scc.c[i])
					dag.adde(scc.c[i], scc.c[x]);
	dag.fix(scc.C);
	int p = -1;
	for(int i = 1;i <= N;i++)
		if(!e[i])
		{
			if(!~p)
				p = i;
			else if(test(p, i))
				p = i;
		}
	for(;!dag.v.empty();)
	{
		int k = dag.v.back();
		dag.v.pob;
		vi& v = scc.g[k];
		int z = v.back();
		v.pob;
		if(!~p||test(p, z))
		{
			if(~p)
			{
				int w = scc.c[p];
				if(!scc.g[w].empty())
					dag.v.pb(w);
				else
					dag.remove(w);
			}
			p = z;
		}
		else
		{
			if(!v.empty())
				dag.v.pb(k);
			else
				dag.remove(k);
		}
	}
	printf("! %d\n", p);
	return 0;
}
/*
7 9
1 3
3 2
2 1
1 4
3 5
2 6
4 5
5 6
6 4
*/

/*
My previous AC submission was incorrect lol

the c array was double counting edges if two nodes from a component point to the same differnt component
*/