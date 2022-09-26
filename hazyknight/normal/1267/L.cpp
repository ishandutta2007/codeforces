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

const int MAXN = 1005;

int n,l,k;

char ans[MAXN][MAXN];
char s[MAXN * MAXN];

int main()
{
	scanf("%d%d%d%s",&n,&l,&k,s + 1);
	sort(s + 1,s + n * l + 1);
	int p = 0;
	for (int i = 1;i <= l;i++)
		for (int j = 1;j <= k;j++)
			if (ans[j][i - 1] == ans[k][i - 1])
				ans[j][i] = s[++p];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= l;j++)
			if (!ans[i][j])
				ans[i][j] = s[++p];
	for (int i = 1;i <= n;i++,putchar('\n'))
		for (int j = 1;j <= l;j++)
			putchar(ans[i][j]);
	return 0;
}