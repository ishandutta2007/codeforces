#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,bool> pib;
const int MAXN = 1e5 + 5;
const int MAXQ = 1e5 + 5;

struct DSU
{
	int fa[MAXN], siz[MAXN];
	bool tag[MAXN];
	inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i, siz[i] = 1, tag[i] = 0;}
	inline pib find(int u)
	{
		bool res = 0;
		while(fa[u] != u) res ^= tag[u], u = fa[u];
		return make_pair(u, res);
	}
	inline int connect(int u,int v)
	{
		pib fu = find(u), fv = find(v);
		u = fu.first; v = fv.first;
		if(u == v) return fu.second == fv.second? -1: 0;
		if(siz[u] > siz[v]) swap(u,v);
		if(fu.second == fv.second) tag[u] ^= 1;
		fa[u] = v; siz[v] += siz[u];
		return u;
	}
	inline void cut(int u){ siz[fa[u]] -= siz[u]; fa[u] = u; tag[u] = 0;}
}dsu;

struct Node
{
	int l,r,u,v;
}e[MAXQ];
int ecnt = 0;

stack<int> sta;
void roll_back(int siz)
{
	while((int)sta.size() > siz)
		dsu.cut(sta.top()), sta.pop();
}

pii p[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	
	set<pii> in;
	
	//int bsiz = sqrt(Q);
	int bsiz = 330;
	for(int l=1; l<=Q; l += bsiz)
	{
		int r = min(Q, l + bsiz - 1);
		for(int i=l; i<=r; ++i) scanf("%d%d",&p[i].first,&p[i].second);
		
		set<pii> cur;
		for(int i=l; i<=r; ++i)
			cur.insert(p[i]);
		
		dsu.init(n);
		bool preok = 1;
		for(set<pii>::iterator it = in.begin(); it != in.end(); ++it)
			if(cur.find(*it) == cur.end())
			{
				int u = it -> first, v = it -> second;
				if(dsu.connect(u,v) == -1){ preok = 0; break;}
			}
		if(!preok){ for(int i=l; i<=r; ++i) printf("NO\n"); continue;}
		
		for(int i=l; i<=r; ++i)
		{
			if(in.find(p[i]) == in.end()) in.insert(p[i]);
			else in.erase(p[i]);
			
			bool ok = 1;
			for(set<pii>::iterator it = cur.begin(); it != cur.end(); ++it)
				if(in.find(*it) != in.end())
				{
					int u = it -> first, v = it -> second;
					int res = dsu.connect(u,v);
					if(res == -1){ ok = 0; break;}
					if(res) sta.push(res);
				}
			
			printf(ok? "YES\n": "NO\n");
			roll_back(0);
		}
	}
	return 0;
}