#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, j;
ll x;
vector <ll> v [1001];

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		{
		scanf ("%lld",&x);
		v[__builtin_ctzll(x)].push_back(x);
		}
	j = 0;
	for (i=0; i<=65; i++)
		if (v[i].size()>v[j].size())
			j = i;
	printf ("%d\n", n-(int)(v[j].size()));
	for (i=0; i<=65; i++)
		if (i!=j)
			for (ll a : v[i])
				printf ("%lld ",a);
	printf ("\n");
	return 0;
	}