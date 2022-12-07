#include <bits/stdc++.h>
using namespace std;

int n, i, x, Max;
unordered_map <int,int> Map;

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		{
		scanf ("%d",&x);
		Map[x]++;
		Max=max(Max,Map[x]);
		}
	printf ("%d\n",(n-Max));
	return 0;
	}