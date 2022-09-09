#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 3e5 + 5;
const int MAXQ = 5e5 + 5;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

int p[MAXN];
pii es[MAXM];
int type[MAXQ], id[MAXQ]; 

int fa[MAXN];
set<int> t[MAXN];
int find(int u){ return fa[u] == u? u: find(fa[u]);}
inline int connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u == v) return -1;
	if(t[u].size() > t[v].size()) swap(u, v);
	t[v].insert(t[u].begin(), t[u].end());
	fa[u] = v;
	return u;
}

int main(void)
{
	int n = read(), m = read(), Q = read();
	for(int i=1; i<=n; ++i) p[i] = read();
	for(int i=1; i<=m; ++i) es[i].first = read(), es[i].second = read();
	for(int i=1; i<=Q; ++i) type[i] = read(), id[i] = read();
	
	static bool del[MAXM];
	for(int i=1; i<=Q; ++i)
		if(type[i] == 2) del[id[i]] = 1;
	
	for(int i=1; i<=n; ++i)
		fa[i] = i, t[i].insert(p[i]);
	
	for(int i=1; i<=m; ++i) if(!del[i])
		connect(es[i].first, es[i].second);
	
	static int f[MAXQ];
	for(int i=Q; i>=1; --i) if(type[i] == 2)
		f[i] = connect(es[id[i]].first, es[id[i]].second);
	
	for(int i=1; i<=Q; ++i)
	{
		if(type[i] == 1)
		{
			int u = find(id[i]);
			printf("%d\n",t[u].size()? *t[u].rbegin(): 0);
			if(t[u].size()) t[u].erase(*t[u].rbegin());
		}
		else
		{
			int u = f[i];
			if(u != -1)
			{
				int v = fa[u]; fa[u] = u;
				set<int> nxt;
				for(int x: t[u])
					if(t[v].erase(x))
						nxt.insert(x);
				t[u] = nxt;
			}
		}
	}
	return 0;
}