#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
#define maxn 200005
using namespace std;
int c[maxn], d[maxn];
int mxs = 50000000, ms = -40000000;
int n;
int main()
{
	int pls = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &c[i], &d[i]);
		if(d[i] == 2)
		{
			int nmxs = 1899 - pls;
			mxs = min(mxs, nmxs);
		}
		else
		{
			int nmins = 1900 - pls;
			ms = max(nmins, ms);
		}
		pls += c[i];
	}
	if(ms > mxs)
	{
		printf("Impossible\n");
		return 0;
	}
	if(mxs >= 25000000)
	{
		printf("Infinity\n");
		return 0;
	}
	printf("%d\n", mxs + pls);
	return 0;
}