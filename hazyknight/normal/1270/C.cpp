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

int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		long long s = 0,x = 0;
		for (int i = 1;i <= n;i++)
		{
			long long a;
			scanf("%lld",&a);
			s += a;
			x ^= a;
		}
		printf("2\n%lld %lld\n",x,s + x);
	}
	return 0;
}