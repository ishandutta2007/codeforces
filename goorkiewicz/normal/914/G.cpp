#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> polynomial;

const ll mod = 1000000007;
const int B = 17;
const int N = (1<<B);

ll pw (ll a, ll b)
	{
	ll res = 1;
	while (b!=0)
		{
		if (b%2==1)
			(res*=a)%=mod;
		(a*=a)%=mod;
		b/=2;
		}
	return res;
	}

inline void normalize (ll& x)
	{
	if (x<0) x+=mod;
	if (x>=mod) x-=mod;
	}

void transform (polynomial& A, ll a1, ll a2, ll a3, ll a4)
	{
	ll a, b;
	int i, j, k;
	for (k=1; k<N; k*=2)
		for (j=0; j<N; j+=2*k)
			for (i=j; i<j+k; i++)
				{
				a = A[i];
				b = A[i+k];
				A[i] = (a1*a + a2*b)%mod;
				A[i+k] = (a3*a + a4*b)%mod;
				normalize(A[i]);
				normalize(A[i+k]);
				}
	}

polynomial xor_convolution (polynomial a, polynomial b)
	{
	transform(a, 1, 1, 1, -1);
	transform(b, 1, 1, 1, -1);
	
	polynomial c (N);
	int i;
	for (i=0; i<N; i++)
		c[i] = (a[i]*b[i])%mod;
	
	transform(c, 1, 1, 1, -1);
	
	for (i=0; i<N; i++)
		(c[i] *= pw(N, mod-2)) %= mod;
	
	return c;
	}

polynomial and_convolution (polynomial a, polynomial b)
	{
	transform(a, 0, 1, 1, 1);
	transform(b, 0, 1, 1, 1);
	
	polynomial c (N);
	
	for (int i=0; i<N; i++)
		c[i] = (a[i]*b[i])%mod;
	
	transform(c, -1, 1, 1, 0);
	
	return c;
	}

void mobius (ll* A, bool reverse)
	{
	int i, j;
	for (j=0; j<=B; j++)
		for (i=0; i<N; i++)
			if ((i>>j)&1)
				{
				A[i] += (reverse ? -1 : 1) * A[i^(1<<j)];
				normalize(A[i]);
				}
	}

ll da [B+1][N];
ll db [B+1][N];
ll dc [B+1][N];

polynomial subset_convolution (polynomial a, polynomial b)
	{
	int i, j, k;
	for (i=0; i<N; i++)
		{
		da[__builtin_popcount(i)][i] = a[i];
		db[__builtin_popcount(i)][i] = b[i];
		}
	
	for (j=0; j<=B; j++)
		{
		mobius(da[j], false);
		mobius(db[j], false);
		}

	for (i=0; i<N; i++)
		for (j=0; j<=B; j++)
			for (k=0; k<=j; k++)
				(dc[j][i] += da[k][i] * db[j-k][i]) %= mod;
	
	for (j=0; j<=B; j++)
		mobius(dc[j], true);
	
	polynomial c (N);
	
	for (i=0; i<N; i++)
		c[i] = dc[__builtin_popcount(i)][i];
	
	return c;
	}

ll fib [N];
polynomial P1, P2, P3;

int main ()
	{
	P1 = polynomial(N, 0);
	
	int i, n, x;
	scanf ("%d",&n);
	while (n--)
		{
		scanf ("%d", &x);
		P1[x]++;
		}
	
	P2 = subset_convolution(P1, P1);
	P3 = xor_convolution(P1, P1);
	
	fib[0] = 0;
	fib[1] = 1;
	for (i=2; i<N; i++)
		fib[i] = (fib[i-1]+fib[i-2])%mod;

	for (i=0; i<N; i++)
		{
		(P1[i] *= fib[i]) %= mod;
		(P2[i] *= fib[i]) %= mod;
		(P3[i] *= fib[i]) %= mod;
		}

	P1 = and_convolution(P1, P2);
	P1 = and_convolution(P1, P3);
	
	ll out = 0;
	for (i=1; i<N; i*=2)
		(out += P1[i]) %= mod;

	printf ("%lld\n", out);
	return 0;
	}