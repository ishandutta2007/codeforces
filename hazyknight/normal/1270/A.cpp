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

int T,n,t1,t2,a;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&t1,&t2);
		bool ok = 0;
		for (int i = 1;i <= t1;i++)
		{
			scanf("%d",&a);
			if (a == n)
				ok = 1;
		}
		for (int i = 1;i <= t2;i++)
			scanf("%d",&a);
		puts(ok ? "YES" : "NO");
	}
	return 0;
}