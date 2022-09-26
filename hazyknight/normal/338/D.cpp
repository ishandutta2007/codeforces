#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 10005;

int k;

ll n,m;
ll a[MAXN];

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}

ll inv(ll a,ll p)
{
	ll x,y;
	exgcd(a,p,x,y);
	return x;
}

void merge(ll &m1,ll &c1,ll m2,ll c2)
{
	ll g = __gcd(m1,m2);
	if (m1 / g > n / m2 || (c2 - c1) % g)
	{
		puts("NO");
		exit(0);
	}
	c1 = ((c2 - c1) / g) * inv(m1 / g,m2 / g) % (m2 / g) * m1 + c1;
	m1 = m1 / g * m2;
}

int main()
{
	scanf("%lld%lld%d",&n,&m,&k);
	ll M = 1,C = 0;
	for (int i = 1;i <= k;i++)
	{
		scanf("%lld",&a[i]);
		merge(M,C,a[i],1 - i);
	}
	C = (M + C) % M;
	if (!C)
		C = M;
	if (C + k - 1 > m)
	{
		puts("NO");
		return 0;
	}
	for (ll i = C;i <= C + k - 1;i++)
		if (__gcd(M,i) != a[i - C + 1])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}