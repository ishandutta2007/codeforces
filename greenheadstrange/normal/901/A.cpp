#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 200005
using namespace std;
int a[maxn];
int pr[2][maxn];
int main()
{
	bool flag = 0;
	int n;
	scanf("%d", &n);
	n++;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int nsum = 0, fr = 0;
	for(int i = 1; i <= n; i++)
	{
		
		for(int j = 1 + nsum; j <= a[i] + nsum; j++)
			pr[0][j] = pr[1][j] = fr;
		if(!flag)
			if(a[i] >= 2 && a[i - 1] >= 2)
			{
				pr[1][1 + nsum] = fr + 1;
				flag = 1;
			}
		fr = nsum + 1;		
		nsum += a[i];
	}
	if(flag)
	{
		printf("ambiguous\n");
		for(int i = 0; i < 2; i++)
		{
			for(int j = 1; j <= nsum; j++)
				printf("%d ", pr[i][j]);
			printf("\n");
		}
	}
	else
	{
		printf("perfect\n");
	}
	return 0;
}