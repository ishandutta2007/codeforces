#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000001;
int n, m, k, l, i, j, ok, now;
int t [100001];
long long out;

int main ()
	{
	scanf ("%d%d%d",&n,&k,&l);
	m=(n*k);
	for (i=0; i!=m; i++)
		scanf ("%d",&t[i]);
	sort (t,t+m);
	ok = (t[0]+l);
	for (i=(m-1); i>=0; i--)
		{
		now++;
		if (now>=k && t[i]<=ok)
			{
			out+=((long long)(t[i]));
			now-=k;
			}
		}
	if (now==0)
		printf ("%lld\n",out);
	else
		printf ("0\n");
	return 0;
	}