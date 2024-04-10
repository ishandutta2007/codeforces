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
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAXN = 55;

int n,m;
int sum[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];

char s[MAXN][MAXN];

int solve(int xa,int ya,int xb,int yb)
{
	if (sum[xb][yb] - sum[xa - 1][yb] - sum[xb][ya - 1] + sum[xa - 1][ya - 1] == 0)
		return 0;
	if (f[xa][ya][xb][yb])
		return f[xa][ya][xb][yb];
	f[xa][ya][xb][yb] = max(xb - xa + 1,yb - ya + 1);
	for (int i = xa;i < xb;i++)
		f[xa][ya][xb][yb] = min(f[xa][ya][xb][yb],solve(xa,ya,i,yb) + solve(i + 1,ya,xb,yb));
	for (int i = ya;i < yb;i++)
		f[xa][ya][xb][yb] = min(f[xa][ya][xb][yb],solve(xa,ya,xb,i) + solve(xa,i + 1,xb,yb));
	return f[xa][ya][xb][yb];
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s[i] + 1);
		for (int j = 1;j <= n;j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == '#');
	}
	printf("%d\n",solve(1,1,n,n));
	return 0;
}