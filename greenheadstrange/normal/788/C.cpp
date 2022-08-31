#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
using namespace std;
int n, k;
int num[maxn];
bool hv[2005]; // true + 1000
int ms[maxn];
int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++)
		scanf("%d", &num[i]), num[i] -= n;
	int pls = 1000;
	for(int i = 1; i <= k; i++)
		hv[num[i] + pls] = 1;
	if(hv[pls])
	{
		printf("1\n");
		return 0;
	}
	bool flag = false;
	int inf = 10000000;
	for(int i = 2004; i >= 0; i--)
		if(hv[i])
		{
			int ns = i - pls;
			if(!flag)
			{
				for(int i = 0; i < maxn; i++) ms[i] = inf;
				if(ns > 0)
					for(int j = 1; j * ns < maxn; j++)
						ms[j * ns] = j;
				else
				{
					printf("-1\n");
					return 0;
				}
				flag = 1;
			}
			else
			{
				if(ns > 0)
				{
					ms[ns] = min(ms[ns], 1);
					for(int i = 0; i < maxn - ns; i++)
						 ms[i + ns] = min(ms[i + ns], ms[i] + 1);
				}
				else for(int i = maxn - 1; i >= -ns; i--)
					ms[i + ns] = min(ms[i + ns], ms[i] + 1);
			}	
		}
	if(ms[0] != inf) printf("%d\n", ms[0]);
	else printf("-1\n");
	return 0;
}