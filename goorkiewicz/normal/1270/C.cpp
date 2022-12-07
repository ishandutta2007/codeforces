#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i;
ll a, X, S, A, B, C;

void solve ()
	{
	scanf ("%d", &n);
	X = 0;
	S = 0;
	A = 0;
	B = 0;
	C = 0;
	for (i=1; i<=n; i++)
		{
		scanf ("%lld", &a);
		X ^= a;
		S += a;
		}
	for (i=0; i<60; i++)
		{
		if ((((2*X)>>i)&1ll)==0 && ((S>>i)&1ll)==1)
			{
			A ^= (1ll<<i);
			X ^= (1ll<<i);
			S += (1ll<<i);
			}
		if ((((2*X)>>i)&1ll)==1 && ((S>>i)&1ll)==0)
			{
			B ^= (1ll<<(i-1));
			X ^= (1ll<<(i-1));
			S += (1ll<<(i-1));
			C ^= (1ll<<(i-1));
			X ^= (1ll<<(i-1));
			S += (1ll<<(i-1));
			}
		}
	printf ("3\n");
	printf ("%lld %lld %lld\n", A, B, C);
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}