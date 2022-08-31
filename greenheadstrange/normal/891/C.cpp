#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 500005
using namespace std;
struct th
{
	int w, id;
	bool operator < (const th &a)const
	{
		return w < a.w;	
	}
}p[maxn];
int fa[maxn], sz[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return gfa(fa[a]);
}
int u[maxn], v[maxn], w[maxn];
int bl[maxn], num[maxn];
vector <th> qs[maxn];
bool flag[maxn];
int q[maxn], ed = 0;
void del(int a)
{
	if(fa[a] == a) return;
	int pl = fa[a];
	while(1)
	{
		sz[pl] -= sz[a];
		if(fa[pl] == pl) break;
		pl = fa[pl];
	}
	fa[a] = a;
}
int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &u[i], &v[i], &w[i]), 
		p[i].w = w[i],
		p[i].id = i;
	sort(p + 1, p + 1 + m);
	for(int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1; 
	int cnt = 1;
	for(int i = 1; i <= m; i++)
	{
		if(i == 1 || p[i].w != p[i - 1].w)
			cnt++;
		bl[p[i].id] = cnt - 1;
	}
	int Q;
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++)
	{
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			int id;
			scanf("%d", &id);
			th n1;
			n1.w = i, n1.id = id;
			qs[bl[id]].push_back(n1);
		}
		flag[i] = 1;
	}
	ed = 0;
	for(int i = 1; i < cnt; i++)
		sort(qs[i].begin(), qs[i].end());
	for(int i = 1; i <= m; i++)
	{
		if(i == 1 || p[i].w != p[i - 1].w)
		{
			// cal bl[i]
		
			int ns = bl[p[i].id];
			for(int j = 0; j < qs[ns].size(); j++)
			{
				if(!j || qs[ns][j - 1].w != qs[ns][j].w)
				{
					while(ed) 
						del(q[ed - 1]), ed--;
				}
				th n1 = qs[ns][j];
				int ufa = gfa(u[n1.id]), vfa = gfa(v[n1.id]);	
				if(sz[ufa] < sz[vfa]) swap(ufa, vfa);
				if(ufa == vfa) 
					flag[n1.w] = 0;
				else 
					fa[vfa] = ufa, sz[ufa] += sz[vfa], q[ed++] = vfa;
			}
			while(ed) del(q[ed - 1]), ed--;
		}	
		int ufa = gfa(u[p[i].id]), vfa = gfa(v[p[i].id]);
		if(ufa == vfa) continue;
		if(sz[ufa] < sz[vfa]) swap(ufa, vfa);
		fa[vfa] = ufa, sz[ufa] += sz[vfa];
	}
	cnt = 0;
	for(int i = 1; i <= n; i++)
		if(fa[i] == i) cnt++;
	
	for(int i = 1; i <= Q; i++)
		if(flag[i]) printf("YES\n");
		else printf("NO\n");
	return 0;
}
/*
14 16
2 1 3
3 1 5
4 3 4
5 3 5
6 3 5
7 2 1
8 6 5
9 2 5
10 2 2
11 1 4
12 5 2
13 12 4
14 12 4
8 11 2
13 14 2
12 14 5
2
12 3 12 6 1 13 8 4 9 5 10 11 14
6 3 7 10 12 11 2
*/