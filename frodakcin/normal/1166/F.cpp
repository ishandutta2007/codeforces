#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

template<int MS> struct DSU
{
public:
	int p[MS], r[MS], m[MS];
	set<int> v[MS];
	int f(int n) {return p[n]?p[n]=f(p[n]):n;}
	void init(void)
	{
		for(int i = 0;i < MS;i++)
			m[i] = i;
	}
	bool mm(int a, int b)
	{
		a=f(a),b=f(b);
		if(a==b) return 0;
		if(r[a]<r[b]) swap(a,b);
		r[a]+=r[a]==r[b], r[b]=-1, p[b]=a;
		if(v[m[a]].size()<v[m[b]].size()) swap(m[a], m[b]);
		v[m[a]].insert(v[m[b]].begin(), v[m[b]].end()), v[m[b]].clear();
		return 1;
	}
	void add(int a, int b)
	{
		a = f(a);
		v[m[a]].insert(b);
	}
	bool test(int a, int b)
	{
		a=f(a);
		if(a==f(b)) return 1;
		if(v[m[a]].find(b) != v[m[a]].end())
			return 1;
		return 0;
	}
};

const int MN = 1e5 + 100;
const int MM = 1e5 + 100;
int N, M, C, Q;
map<int, int> c[MN];
#define IT iterator
using mapit = map<int, int>::IT;
DSU<MN> dsu;

void add_edge(void)
{
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);

	mapit it;
	it = c[x].find(z);
	if(it != c[x].end()) dsu.mm(it->second, y);
	else c[x].insert({z, y});

	it = c[y].find(z);
	if(it != c[y].end()) dsu.mm(it->second, x);
	else c[y].insert({z, x});

	dsu.add(x, y);
	dsu.add(y, x);
}
int main(void)
{
	dsu.init();
	scanf("%d%d%d%d", &N, &M, &C, &Q);
	for(int i = 0;i < M;i++)
		add_edge();
	for(int i = 0;i < Q;i++)
	{
		char t; scanf(" %c", &t);
		if(t=='+')
			add_edge();
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if(dsu.test(x, y)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}