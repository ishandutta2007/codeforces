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

int T;

ll n;

ll solve2(ll st,ll len,ll ar)
{
	if (len == 1)
		return st;
	ll d = len >> 2;
	if (ar <= d)
		return solve2(st,d,ar);
	ar -= d;
	if (ar <= d)
		return solve2(st + 2 * d,d,ar);
	ar -= d;
	if (ar <= d)
		return solve2(st + 3 * d,d,ar);
	ar -= d;
	if (ar <= d)
		return solve2(st + d,d,ar);
}

ll solve3(ll st,ll len,ll ar)
{
	if (len == 1)
		return st;
	ll d = len >> 2;
	if (ar <= d)
		return solve3(st,d,ar);
	ar -= d;
	if (ar <= d)
		return solve3(st + 3 * d,d,ar);
	ar -= d;
	if (ar <= d)
		return solve3(st + d,d,ar);
	ar -= d;
	if (ar <= d)
		return solve3(st + 2 * d,d,ar);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);
		ll ar = (n - 1) / 3 + 1,po = n % 3,st = 0;
		for (ll i = 1;;i <<= 2)
		{
			if (ar <= i)
			{
				st = i;
				break;
			}
			ar -= i;
		}
		if (po == 1)
			printf("%lld\n",st + ar - 1);
		if (po == 2)
			printf("%lld\n",solve2(st * 2,st,ar));
		if (po == 0)
			printf("%lld\n",solve3(st * 3,st,ar));
	}
	return 0;
}