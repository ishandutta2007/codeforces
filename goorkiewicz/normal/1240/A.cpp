#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int q, n, i;
ll a, b, k, A, B, X, Y;
ll t [N];
vector <ll> vec;

bool check (ll m)
	{
	vec.clear();
	for (i=1; i<=m; i++)
		vec.push_back(t[i]);
	reverse(vec.begin(), vec.end());
	ll ammo1 = m/((A*B)/__gcd(A, B));
	ll ammo2 = m/A;
	ll ammo3 = m/B;
	ammo2 -= ammo1;
	ammo3 -= ammo1;
	ll res = 0;
	while (ammo1--)
		{
		res += ((X+Y)*vec.back())/100;
		vec.pop_back();
		}
	while (ammo2--)
		{
		res += (X*vec.back())/100;
		vec.pop_back();
		}
	while (ammo3--)
		{
		res += (Y*vec.back())/100;
		vec.pop_back();
		}
	return (res>=k);
	}

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&n);
		for (i=1; i<=n; i++)
			scanf ("%lld",&t[i]);

		sort(t+1, t+n+1);
		reverse(t+1, t+n+1);

		scanf ("%lld%lld",&X,&A);
		scanf ("%lld%lld",&Y,&B);
		
		if (Y > X)
			{
			swap(X, Y);
			swap(A, B);
			}
		
		scanf ("%lld",&k);
		
		a = -1;
		b = n+1;
		while (b-a>1)
			(check((a+b)/2) ? b : a) = (a+b)/2;
		if (b==n+1)
			printf ("-1\n");
		else
			printf ("%lld\n",b);
		}
	return 0;
	}