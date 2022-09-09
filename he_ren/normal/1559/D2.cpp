#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int fa[MAXN], siz[MAXN];
vector<int> pt[MAXN];
inline void init(int _n)
{
	for(int i=1; i<=_n; ++i)
	{
		fa[i] = i; siz[i] = 1;
		pt[i].push_back(i);
	}
}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline int connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u == v) return -1;
	if(siz[u] > siz[v]) swap(u,v);
	fa[u] = v; siz[v] += siz[u];
	pt[v].insert(pt[v].end(), pt[u].begin(), pt[u].end());
	pt[u] = vector<int>();
	return v;
}

set<pii> f;
set<int> g;
inline void erase_f(int u)
{
	u = find(u);
	f.erase(make_pair(siz[u], u));
}
inline void erase_g(int u)
{
	g.erase(find(u + n));
}

vector<pii> ans;
inline void push_ans(int u,int v)
{
	ans.emplace_back(u,v);
	erase_f(u); erase_f(v);
	erase_g(u); erase_g(v);
	int t1 = connect(u, v);
	int t2 = connect(u + n, v + n);
	f.emplace(siz[t1], t1);
	g.emplace(t2);
}

int main(void)
{
	int m1, m2;
	scanf("%d%d%d",&n,&m1,&m2);
	init(n * 2);
	for(int i=1; i<=m1; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		connect(u,v);
	}
	for(int i=1; i<=m2; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		connect(u+n,v+n);
	}
	
	for(int i=1; i<=n; ++i) if(find(i) == i)
		f.emplace(siz[i], i);
	for(int i=n+1; i<=2*n; ++i) if(find(i) == i)
		g.emplace(i);
	
	while((int)f.size() > 1)
	{
		int u = f.begin() -> second;
		for(int x: pt[u])
		{
			int y = x + n;
			if(--siz[find(y)] == 0) g.erase(find(y));
		}
		if(!g.size()) break;
		
		int uu = -1, vv = -1;
		for(int x: pt[u])
		{
			int y = x + n;
			bool flag = g.erase(find(y));
			if((int)g.size())
			{
				uu = x;
				int tmp = *g.begin();
				for(int v: pt[tmp]) if(find(v - n) != u)
				{
					vv = v - n;
					break;
				}
				assert(vv != -1);
			}
			if(flag) g.insert(find(y));
			if(uu != -1) break;
		}
		if(uu == -1) break;
		
		for(int x: pt[u])
		{
			int y = x + n;
			if(++siz[find(y)] == 1) g.insert(find(y));
		}
		
		push_ans(uu, vv);
	}
	
	printf("%d\n",(int)ans.size());
	for(pii x: ans) printf("%d %d\n",x.first,x.second);
	return 0;
}