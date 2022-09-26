#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n,first,tot;
int ans[MAXN];
int nxt[MAXN];
int a[MAXN];

bool vis[MAXN];

set<int> S;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		S.clear();
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			nxt[i] = i + 1;
			vis[i] = 1;
		}
		nxt[n] = 1;
		first = 1;
		for (int i = 1;i <= n;i++)
			if (__gcd(a[i],a[i % n + 1]) == 1)
				S.insert(i);
		tot = 0;
		int pos = 1;
		while (1)
		{
			if (tot == n - 1)
			{
				if (a[first] == 1)
					ans[++tot] = first;
				break;
			}
			set<int>::iterator it = S.lower_bound(pos);
			if (it == S.end())
			{
				if (pos == first)
					break;
				pos = first;
				continue;
			}
			int u = *it,v = nxt[u],w = nxt[v];
			S.erase(it);
			ans[++tot] = v;
			nxt[u] = w;
			vis[v] = 0;
			S.erase(v);
			while (first && !vis[first])
				first++;
			if (__gcd(a[u],a[w]) == 1)
				S.insert(u);
			pos = w;
			/*
			for (int i = first;i <= n;i = (nxt[i] > i ? nxt[i] : n + 1))
				cerr << i << ' ';
			cerr << endl;
			getchar();
			*/
		}
		printf("%d ",tot);
		for (int i = 1;i <= tot;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}