#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
ll out;
int x, y;

int main ()
	{
	scanf ("%d%d",&x,&y);
	x+=y;
	out=1;
	while (x--)
		{
		out*=2;
		if (out>=mod)
			out-=mod;
		}
	printf ("%lld\n",out);
	return 0;
	}