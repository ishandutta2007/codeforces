#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 23
#define ll long long
using namespace std;
int sz[1 << maxn];
int lk[maxn];
int lb[1 << maxn];
int hv;
int q[maxn * 2], fr, ed;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = (1 << i); j < (1 << n); j += (1 << (i + 1)))
			lb[j] = i;
		for(int j = 0; j < (1 << n); j++)
			if(j & (1 << i))
				sz[j]++;
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		lk[u - 1] |= (1 << (v - 1)), 
		lk[v - 1] |= (1 << (u - 1)); 
	}
	bool fl = 1;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(lk[i] & (1 << j)) continue;
			else fl = 0;
	if(fl)
	{
		printf("0\n");
		return 0;
	}
	int ans = maxn, ns = 0;
	for(int i = 1; i < (1 << n); i++)
	{
		bool flag = 1;
		int nlk = 0;
		int nnlk = 0;
		for(int j = 0; j < n; j++)
		{
			if((1 << j) & i) continue;
			if(lk[j] & i) continue;
			flag = 0;
		}
		hv = 0;
		fr = ed = 0;
		q[ed++] = lb[i];
		hv ^= (1 << lb[i]);
		while(fr < ed)
		{
			int ns = lk[q[fr]] & (i ^ hv);
			while(ns)
			{
				int nxt = lb[ns];
				q[ed++] = nxt;
				hv ^= (1 << nxt);
				ns ^= (1 << nxt);
			}
			
			fr++;
		}
		if(ed != sz[i]) flag = 0;
		if(flag)
		{
			if(sz[i] < ans)
				ans = sz[i], ns = i;
		}
	}
	printf("%d\n", ans);
	while(ns)
	{
		int nxt = lb[ns];
		printf("%d ", nxt + 1);
		ns ^= (1 << nxt);
	}
	return 0;
}