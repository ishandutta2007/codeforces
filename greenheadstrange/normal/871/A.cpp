#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 100005
using namespace std;
int ans[100];
bool bpr[100];
int main()
{
	for(int i = 0; i < 100; i++)
		bpr[i] = 1;
	for(int i = 2; i < 100; i++)
	{
		if(!bpr[i]) continue;
		for(int j = 2; j * i < 100; j++)
			bpr[i * j] = 0;
	}
	ans[0] = 0;
	for(int i = 1; i < 100; i++)
	{
		ans[i] = -maxn;
		for(int j = 2; j <= i; j++)
		{
			if(bpr[j]) continue;
			ans[i] = max(ans[i], ans[i - j] + 1);
		}
	}
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int a;
		scanf("%d", &a);
		if(a < 100) 
		{
			if(ans[a] >= 0) 
				printf("%d\n", ans[a]);
			else printf("-1\n");
		}
		else
		{
			int nst = (a - 100) / 4;
			nst++;
			a -= nst * 4;
			printf("%d\n", ans[a] + nst);
		}
	}
	return 0;
}