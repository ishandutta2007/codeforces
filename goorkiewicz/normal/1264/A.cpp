#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int N = 1000005;
int n, i, j, q, a, b, c;
ll best, val;
ll t [N];
ll fac [N];
ll rev [N];
multiset <ll> S;

ll pw (ll a, ll b)
	{
	ll res = 1;
	while (b!=0)
		{
		if (b%2==1)
			res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	   	b /= 2;
		}
	return res;
	}

void solve ()
	{
	scanf("%d", &n);
	
	for (i=1; i<=n; i++)
		scanf ("%lld", &t[i]);

	int j = n/2;
	
	while (j>0 && t[j] == t[(n/2)+1])
		j--;

	a = b = c = best = 0;

	S.clear();
	for(i=1; i<j; i++)
		if(t[i] != t[i+1])
			S.insert(i);
	
	for (i=1; i<j; i++)
		if (t[i] != t[i+1])
			{
			auto it = S.lower_bound(i+i+1);

			if (it == S.end())
				continue;

			val = *it;

			if (val == j-1)
				continue;
			if (j-val <= i)
				continue;

			a = i;
			b = val-i;
			c = j-val;
			}

	printf("%d %d %d\n", a, b, c);
	}

int main() 
	{
	fac[0] = 1;
	for (i=1; i<N; i++)
		fac[i] = fac[i-1] * i % mod;
	
	for (i=0; i<N; i++)
		rev[i] = pw(fac[i], mod-2);
	
	scanf("%d", &q);
	while (q--)
		solve();
	
	return 0;
	}