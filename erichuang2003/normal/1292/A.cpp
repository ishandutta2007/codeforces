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

const int MAXN = 100005;

int n,q,cnt;

bool vis[2][MAXN];

void calc(int r,int c,int v)
{
	cnt += v * (vis[r][c] && vis[r ^ 1][c - 1]);
	cnt += v * (vis[r][c] && vis[r ^ 1][c]);
	cnt += v * (vis[r][c] && vis[r ^ 1][c + 1]);
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int r,c,i = 1;i <= q;i++)
	{
		scanf("%d%d",&r,&c);
		r--;
		calc(r,c,-1);
		vis[r][c] ^= 1;
		calc(r,c,1);
		puts(cnt ? "No" : "Yes");
	}
	return 0;
}