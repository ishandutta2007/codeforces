#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 105
using namespace std;
int eg[maxn][maxn];
int ans[maxn][maxn][27]; // 0  1  
int work(int a, int b, int c)
{
	if(ans[a][b][c] != -1) return ans[a][b][c];
	for(int i = 0; i < maxn; i++)
	{
		if(eg[a][i] < c) continue;
		if(work(b, i, eg[a][i]) == 1) 
			return ans[a][b][c] = 0;
	}
	return ans[a][b][c] = 1;
}
int main()
{
	memset(eg, -1, sizeof(eg));
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		char inp[20];
		scanf("%d%d", &u, &v);
		scanf("%s", inp);
		eg[u][v] = inp[0] - 'a';
	}
	memset(ans, -1, sizeof(ans));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			if(!work(i, j, 0))
				printf("A");
			else printf("B");
		printf("\n");
	}
	return 0;
}