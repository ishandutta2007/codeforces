#include <bits/stdc++.h>
using namespace std;

int n, m, i, j;
int r [200001];
int out [200001];
pair <int,int> t [200001];

int main ()
	{
	scanf ("%d%d",&n,&m);
	for (i=0; i!=n; i++)
		{
		scanf ("%d",&r[i+1]);
		t[i].first=r[i+1];
		t[i].second=(i+1);
		}
	sort (t,t+n);
	for (i=1; i!=n; i++)
		{
		if (t[i].first==t[i-1].first)
			out[t[i].second]=out[t[i-1].second];
		else
			out[t[i].second]=i;
		}
	while (m--)
		{
		scanf ("%d%d",&i,&j);
		if (r[i]>r[j])
			out[i]--;
		if (r[j]>r[i])
			out[j]--;
		}
	for (i=1; i<=n; i++)
		printf ("%d ",out[i]);
	printf ("\n");
	return 0;
	}