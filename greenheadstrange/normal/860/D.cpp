#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <ctime>
#include <algorithm>
#include <set>
#include <queue>
#define maxn 200005
#define cks 50
#define iter set<int> :: iterator
using namespace std;
set <int> eg[maxn];
int fa[maxn], cnt[maxn];
int q[maxn], fr, ed;
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int dep[maxn], pre[maxn];
int nq[maxn], ned = 0;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].insert(v), eg[v].insert(u);
		int ufa = gfa(u), vfa = gfa(v);
		if(ufa == vfa) cnt[ufa] ^= 1;
		else fa[ufa] = vfa, cnt[vfa] ^= cnt[ufa] ^ 1;
	}
	int ans = m;
	for(int i = 1; i <= n; i++)
		if(fa[i] == i && cnt[i])
			 ans--;
	ans /= 2;
	printf("%d\n", ans);
	memset(dep, -1, sizeof(dep));
	for(int i = 1; i <= n; i++)
	{
		if(fa[i] != i) continue;
	//	cout<<"Ns"<<i<<endl;
		fr = ed = 0;
		q[ed++] = i;
		dep[i] = 0;
		while(fr < ed)
		{
			int frs = q[fr];
			for(iter it = eg[frs].begin(); it != eg[frs].end(); it++)
				if(dep[*it] == -1)
					dep[*it] = ed, q[ed++] = (*it), 
					pre[*it] = frs;
			fr++;
		}
		for(int j = ed - 1; j >= 0; j--)
		{
			ned = 0;
			int ns = q[j];
			for(iter it = eg[ns].begin(); it != eg[ns].end(); it++)
				if(dep[*it] >= dep[ns]) nq[ned++] = *it;
			for(int k = 0; k < ned; k++)
				eg[nq[k]].erase(ns);
			if(ned & 1)
			{
				for(int k = 0; k + 1 < ned; k += 2)
					printf("%d %d %d\n", nq[k], ns, nq[k + 1]);
				if(pre[ns])
				{ 
					printf("%d %d %d\n", nq[ned - 1], ns, pre[ns]);
					eg[pre[ns]].erase(ns);
				}
			}
			else
				for(int k = 0; k < ned; k += 2)
					printf("%d %d %d\n", nq[k], ns, nq[k + 1]);
		}
	}
	return 0;
}