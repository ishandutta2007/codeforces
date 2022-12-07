#include <bits/stdc++.h>
using namespace std;

int n, i, u, v, mini;
long long out;
int c [200001];
int a [200001];
int vis [200001];

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		scanf ("%d",&c[i]);
	for (i=1; i<=n; i++)
		scanf ("%d",&a[i]);
	for (i=1; i<=n; i++)
		if (vis[i]==0)
			{
			vis[i]=i;
			u=i;
			while (vis[a[u]]==0)
				{
				u=a[u];
				vis[u]=i;
				}
			if (vis[a[u]]==i)
				{
				v=u;
				mini=c[u];
				u=a[u];
				while (u!=v)
					{
					mini=min(mini,c[u]);
					u=a[u];
					}
				out+=mini;
				}
			}
	printf ("%lld\n",out);
	return 0;
	}