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

int n,m;
int a[505][505];

/*

typedef long long ll;

ll L,R;

ll sum(ll n)
{
	ll 
}
*/

int main()
{
	/*
	cin >> L >> R;
	cout << (sum(R) - sum(L) + MOD) % MOD << endl;
	return 0;
	*/
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	for (int i = 0;i < 10;i++)
	{
		bool tot = 0;
		for (int j = 1;j <= n;j++)
		{
			bool ok[2] = {0};
			for (int k = 1;k <= m;k++)
				ok[a[j][k] >> i & 1] = 1;
			if (ok[0] && ok[1])
			{
				puts("TAK");
				bool c = 0;
				for (int k = 1;k <= n;k++)
					if (j != k)
						c ^= (a[k][1] >> i & 1);
				for (int k = 1;k < j;k++)
					printf("1 ");
				for (int k = 1;k <= m;k++)
					if ((a[j][k] >> i & 1) != c)
					{
						printf("%d ",k);
						break;
					}
				for (int k = j + 1;k <= n;k++)
					printf("1 ");
				puts("");
				return 0;
			}
			if (ok[1])
				tot ^= 1;
		}
		if (tot)
		{
			puts("TAK");
			for (int k = 1;k <= n;k++)
				printf("1 ");
			puts("");
			return 0;
		}
	}
	puts("NIE");
	return 0;
}