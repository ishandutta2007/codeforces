#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 2005;

int n,id;
int a[MAXN][MAXN];

int main()
{
	cin >> n;
	for (int i = 0;i < n / 4;i++)
		for (int j = 0;j < n / 4;j++)
		{
			for (int k = 0;k < 4;k++)
				for (int l = 0;l < 4;l++)
					a[i * 4 + k][j * 4 + l] = id++;
		}
	for (int i = 0;i < n;i++,printf("\n"))
		for (int j = 0;j < n;j++)
			printf("%d ",a[i][j]);
	return 0;
}