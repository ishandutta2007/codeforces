#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 105
using namespace std;
int n, m;
int a, b;
int num[maxn][maxn];
int pls[2][maxn]; // 0 :  1 :  
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &num[i][j]);
	for(int i = 1; i <= n; i++)
		pls[0][i] = num[i][1] - num[1][1];
	for(int i = 1; i <= m; i++)
		pls[1][i] = num[1][i] - num[1][1];
	bool flag = true;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(num[i][j] - num[i][1] != pls[1][j]) flag = false;
	for(int i = 2; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if(num[j][i] - num[1][i] != pls[0][j]) flag = false;
	if(!flag)
	{
		printf("-1\n");
		return 0;
	}
	int ma = 0, mb = 0;
	for(int i = 1; i <= n; i++)
		ma = max(ma, -pls[0][i]);
	for(int i = 1; i <= m; i++)
		mb = max(mb, -pls[1][i]);
	int suma = 0, sumb = 0;
	for(int i = 1; i <= n; i++) suma += pls[0][i];
	for(int i = 1; i <= m; i++) sumb += pls[1][i];
	int ans = 2147483647, apl = 0;
	for(int i = ma; i <= num[1][1] - mb; i++)
	{
		int nans = (i * n + suma) + ((num[1][1] - i) * m + sumb);
		if(nans < ans) ans = nans, apl = i;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= apl + pls[0][i]; j++)
			printf("row %d\n", i);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= pls[1][i] + num[1][1] - apl; j++)
			printf("col %d\n", i);
	return 0;
}