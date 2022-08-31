#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 155
using namespace std;
int num[maxn][maxn];

int main()
{
	num[0][0] = 1, num[1][1] = 1;
	for(int i = 2; i <= 150; i++)
	{
		for(int j = 0; j <= i - 1; j++)
			num[i][j + 1] = num[i - 1][j];
		for(int j = 0; j < 2; j++)
		{
			int ns = 1;
			if(j & 1) ns = -1;
			bool flag = 1;
			for(int j = 0; j <= i - 2; j++)
				if(abs(ns * num[i - 2][j] + num[i][j]) >= 2) flag = 0;
			if(flag)
			{
				for(int j = 0; j <= i - 2; j++)
					num[i][j] += ns * num[i - 2][j];
				break;
			}
		}
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for(int i = 0; i <= n; i++)
		printf("%d ", num[n][i]);
	printf("\n");
	printf("%d\n", n - 1);
	for(int i = 0; i < n; i++)
		printf("%d ", num[n - 1][i]);
	return 0;
} 
/*
3
0
2
1
0
1
2
*/