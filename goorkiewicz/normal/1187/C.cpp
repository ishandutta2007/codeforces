#include <bits/stdc++.h>
using namespace std;

const int inf = 1005;
int q, n, i, t, a, b;
int pref [1005];
int tab [1005];
vector < pair <int,int> > req;

int main ()
	{
	scanf ("%d%d",&n,&q);
	while (q--)
		{
		scanf ("%d%d%d",&t,&a,&b);
		if (t==1)
			{
			pref[a+1]++;
			pref[b+1]--;
			}
		if (t==0)
			req.push_back({a,b});
		}
	for (i=1; i<=n; i++)
		pref[i]+=pref[i-1];
	tab[1] = inf;
	for (i=2; i<=n; i++)
		{
		tab[i] = tab[i-1];
		if (pref[i]==0)
			tab[i]--;
		}
	for (pair <int,int> p : req)
		if (tab[p.first] == tab[p.second])
			return printf ("NO\n"), 0;
	printf ("YES\n");
	for (i=1; i<=n; i++)
		printf ("%d ",tab[i]);
	printf ("\n");
	return 0;
	}