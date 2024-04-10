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

int T;

long long n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);
		if (n <= 14)
		{
			puts("NO");
			continue;
		}
		bool ok = 0;
		for (int i = 1;i <= 6;i++)
			if ((n - i) % 14 == 0)
				ok = 1;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}