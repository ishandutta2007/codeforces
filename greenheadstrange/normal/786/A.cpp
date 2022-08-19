#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 7005
using namespace std;
int s[2][maxn];
int k[2];
int ans[2][maxn]; // 0 : A 1 : B 
int n;
int bk(int a, int b)
{
	int ans = a - b;
	if(ans <= 0) ans += n;
	return ans;
}
int sum[2][maxn];
int q[2][maxn << 2], fr = 0, ed = 0;
int main()
{
	scanf("%d", &n);
	scanf("%d", &k[0]);
	for(int i = 0; i < k[0]; i++) scanf("%d", &s[0][i]);
	scanf("%d", &k[1]);
	for(int i = 0; i < k[1]; i++) scanf("%d", &s[1][i]);
	memset(ans, -1, sizeof(ans));
	
	ans[0][n] = 1, ans[1][n] = 0;
	q[0][ed] = 0, q[1][ed] = n, ed++;
	q[0][ed] = 1, q[1][ed] = n, ed++;
	while(fr < ed)
	{
		int nx = q[0][fr], ny = q[1][fr];
		fr++;
		for(int i = 0; i < k[!nx]; i++)
		{
			int bf = bk(ny, s[!nx][i]);
			if(ans[!nx][bf] != -1) continue;
			if(ans[nx][ny] != nx) ans[!nx][bf] = !nx, q[0][ed] = !nx, q[1][ed] = bf, ed++;
			else 
			{
				sum[!nx][bf]++;
				if(sum[!nx][bf] == k[!nx])
					ans[!nx][bf] = nx, q[0][ed] = !nx, q[1][ed] = bf, ed++;
			}
		}
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 1; j < n; j++)
			if(ans[i][j] == i) printf("Win ");
			else if(ans[i][j] == !i) printf("Lose ");
			else printf("Loop ");
		printf("\n");
	}
	return 0;
}