#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull tester [11] = {61, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

ull mult (ull a, ull b, ull mod) 
	{
	ull mask=15, res=0;
	while (b>0)
		{
		res=((res+(mask&b)*a)%mod);
		a=((a<<4)%mod);
		b>>=4;
		}
	return res;
	}

ull pot (ull a, ull b, ull mod)
	{
	if (b==0)
		return 1;
	if (b==1)
		return a;
	if (b%2==1)
		return mult(a, pot(mult(a, a, mod), b/2, mod), mod);
	return pot(mult(a, a, mod), b/2, mod);
	}

bool prime (ull n) 
	{
	ull s=0, d=n-1, a, k;
	if (n<2 || (n%2==0 && n!=2))
		return 0;
	while(d%2==0)
		{
		s++;
		d/=2;
		}
	for(int i=0; i!=11; i++)
		{
		a = tester[i];
		if (a>=n)
			continue;
		k = pot(a, d, n);
		if (k==1)
			continue;
		bool Bool = true;
		for (ull ss=0; ss!=s; ss++)
			{
			if (k==n-1)
				{
				Bool=false;
				break;
				}
			if (k==1)
				return false;
			k = mult(k, k, n);
			}
		if (Bool==true)
			return false;
		}
	return true;
	}

inline ull f (ull n, ull c, ull mod) {
	return (mult(n,n,mod)+c)%mod;
	}

vector <ull> vec;
int sieve [100001];

void fact (ull n)
	{
	if (n<=100000)
		{
		while (n!=1)
			{
			vec.push_back((ull)(sieve[n]));
			n/=(ull)(sieve[n]);
			}
		return;
		}
	if (prime(n))
		{
		vec.push_back(n);
		return;
		}
	ull x=1, y=1, c=0, div=1;
	while (div==1)
		{
		x=f(x,c,n);
		y=f(f(y,c,n),c,n);
		if (x==y)
			c++;
		else
			div=__gcd((max(x,y)-min(x,y)),n);
		}
	fact(div);
	fact(n/div);
	}

const ull inf = 1000000000000000001;
const int N = 1000005;

ull t [N];
int n, i;
ull s;
vector <int> v;

ull a [N];
ull b [N];

ull count (ull k)
	{
	int i, s = v.size();
	ull load;
	load = 0;
	for (i=0; i<s; i++)
		{
		if (i==0)
			a[i] = 0;
		else
			a[i] = a[i-1]+load;
		load += v[i]%k;
		}
	load = 0;
	for (i=s-1; i>=0; i--)
		{
		if (i==s-1)
			b[i] = 0;
		else
			b[i] = b[i+1]+load;
		load += v[i]%k;
		}
	
	ull res = inf;
	for (i=0; i<s; i++)
		res = min(res, a[i]+b[i]);
	
//	for (i=0; i<s; i++)
//		printf ("%llu ",a[i]);
//	printf ("\n");
//	for (i=0; i<s; i++)
//		printf ("%llu ",b[i]);
//	printf ("\n");
//	
//	
//	printf ("count\n");
//	for (ull a : v)
//		printf ("%llu ", a);
//	printf ("\n");
//	printf ("res = %llu\n", res);
	return res;
	}

ull check (ull k)
	{
	ull res = 0;
	ull sum = 0;
	for (i=1; i<=n; i++)
		{
		v.push_back(t[i]%k);
		sum += t[i]%k;
		if (sum>=k)
			{
			v.back() -= sum-k;
			res += count(k);
			v.clear();
			v.push_back(sum-k);
			sum = sum-k;
			}
		}
	return res;
	}

int main ()
	{
	for (int i=2; i<=100000; i++)
		if (sieve[i]==0)
			for (int j=i; j<=100000; j+=i)
				sieve[j]=i;
	
	ull sum=0;

	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		{
		scanf ("%llu", &t[i]);
		sum += t[i];
		}
	
	if (sum==1)
		return printf ("-1\n"), 0;

	fact(sum);
	
	ull out = inf;
	for (ull d : vec)
		out = min(out, check(d));
	
	printf ("%llu\n", out);
	return 0;
	}