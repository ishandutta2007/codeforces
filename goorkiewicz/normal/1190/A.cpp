#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k, a, b, era, buf, i, j, x, out;
set <ll> S;

int main ()
	{
	scanf ("%lld%lld%lld",&n,&m,&k);
	while (m--)
		{
		scanf ("%lld",&a);
		S.insert(a);
		}
	era = 1;
	while (!S.empty())
		{
		x = (*S.begin());
		x -= era;
		b = (x/k);
		buf = 0;
		while (!S.empty() && ((*S.begin())-era)/k==b)
			{
			S.erase(S.begin());
			buf++;
			}
		era+=buf;
		out++;
		}
	printf ("%lld",out);
	return 0;
	}