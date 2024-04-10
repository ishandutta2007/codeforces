// Codeforces Beta Round #17
// Problem D -- Notepad
#include <cstdio>
#include <cstring>

#define N 2000000

using namespace std;

char bs[N], ns[N];
int c, ans;

int mod(char *a, int m)
{
	int l = strlen(a);
	long long r = 0;	
	for(int i = 0; i != l; ++ i)
		r = (r * 10 + a[i] - 48) % m;
	return r;
}

int pow(int a, long long n, int m)
{
	if(n == 0)
		return 1 % m;
	long long x = pow(a, n >> 1, m);
	x = (x * x) % m;
	if(n & 1)
		x = (x * a) % m;
	return x;
}

int main()
{
	scanf("%s%s%d", bs, ns, &c);
	int b = mod(bs, c);
	if(strlen(ns) <= 10)
	{
		long long n;
		sscanf(ns, "%I64d", &n);
		ans = ((long long)(b - 1) * pow(b, n - 1, c)) % c;
	}
	else
	{
		int phi = c, tmp = c;
		for(int i = 2; i * i <= tmp; ++ i)
			if(tmp % i == 0)
			{
				while(tmp % i == 0)
					tmp /= i;
				phi = phi / i * (i - 1);
			}
		if(tmp > 1)
			phi = phi / tmp * (tmp - 1);
		ans = ((long long)(b - 1) * pow(b, (mod(ns, phi) + phi - 1) % phi + phi, c)) % c;
	}
	printf("%d\n", (ans + c - 1) % c + 1);
	return 0;
}