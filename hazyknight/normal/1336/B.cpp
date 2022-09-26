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

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int T,R,G,B;
int r[MAXN];
int g[MAXN];
int b[MAXN];

ll ans;

void solve(int *x,int *y,int *z,int X,int Y,int Z)
{
	for (int i = 1,j = 1,k = 1;i <= X;i++)
	{
		while (j + 1 <= Y && y[j + 1] <= x[i])
			j++;
		while (k + 1 <= Z && z[k] < x[i])
			k++;
		if (y[j] <= x[i] && x[i] <= z[k])
			ans = min(ans,(ll)(x[i] - y[j]) * (x[i] - y[j]) + (ll)(z[k] - y[j]) * (z[k] - y[j]) + (ll)(z[k] - x[i]) * (z[k] - x[i]));
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&R,&G,&B);
		for (int i = 1;i <= R;i++)
			scanf("%d",&r[i]);
		for (int i = 1;i <= G;i++)
			scanf("%d",&g[i]);
		for (int i = 1;i <= B;i++)
			scanf("%d",&b[i]);
		sort(r + 1,r + R + 1);
		sort(g + 1,g + G + 1);
		sort(b + 1,b + B + 1);
		ans = 4e18;
		solve(r,g,b,R,G,B);
		solve(r,b,g,R,B,G);
		solve(g,r,b,G,R,B);
		solve(g,b,r,G,B,R);
		solve(b,r,g,B,R,G);
		solve(b,g,r,B,G,R);
		printf("%lld\n",ans);
	}
	return 0;
}