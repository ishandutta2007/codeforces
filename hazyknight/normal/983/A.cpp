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

int n;

ll p,q,b;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%lld%lld%lld",&p,&q,&b);
		q /= __gcd(p,q);
		while (q > 1)
		{
			ll g = __gcd(q,b);
			if (g == 1)
			{
				puts("Infinite");
				break;
			}
			while (q % g == 0)
				q /= g;
		}
		if (q == 1)
			puts("Finite");
	}
	return 0;
}