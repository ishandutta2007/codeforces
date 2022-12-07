#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1000000005;
int n, i, j, p, out; 
ll val;

int main () 
	{
	scanf ("%d%d",&n,&p);
	out = inf;
	for (i=1; i<=1000; i++)
		{
		val = n;
		val -= 1ll*i*p;
		if (val>0 && val>=i && __builtin_popcount(val)<=i)
			out = min(out, i);
		}
	printf ("%d\n", out==inf ? -1 : out);
	return 0;
	}