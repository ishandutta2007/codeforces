#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

ll n,k;

ll f(ll N)
{
	ll r = N;
	for (ll i = 2;i * i <= N;i++)
		if (N % i == 0)
		{
			r = r / i * (i - 1);
			while (N % i == 0)
				N /= i;
		}
	if (N > 1)
		r = r / N * (N - 1);
	return r;
}

ll F(ll N,ll K)
{
	if (K == 1)
		return f(N);
	if (N == 1)
		return 1;
	return (K & 1) ? F(f(N),K - 1) : F(N,K - 1);
}

int main()
{
	scanf("%lld%lld",&n,&k);
	printf("%lld\n",F(n,k) % 1000000007);
	return 0;
}