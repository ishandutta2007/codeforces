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

const int MAXN = 1000005;

int n,k,tot;
int pr[MAXN];
int phi[MAXN];

long long ans;

bool mark[MAXN];

void init()
{
	phi[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		if (!mark[i])
		{
			pr[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1;j <= tot && i * pr[j] <= n;j++)
		{
			mark[i * pr[j]] = 1;
			if (i % pr[j] == 0)
			{
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			}
			phi[i * pr[j]] = phi[i] * (pr[j] - 1);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	if (k == 1)
	{
		puts("3");
		return 0;
	}
	k += 2;
	init();
	nth_element(phi + 1,phi + k + 1,phi + n + 1);
	for (int i = 1;i <= k;i++)
		ans += phi[i];
	printf("%lld\n",ans);
	return 0;
}