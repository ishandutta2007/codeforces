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
 
typedef long long ll;
 
const int MAXN = 65;
const ll INF = 2e16 + 1;
 
int n,ax,ay,ans;
 
ll sx,sy,bx,by,t;
ll x[MAXN];
ll y[MAXN];
 
int main()
{
	scanf("%lld%lld%d%d%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&sx,&sy,&t);
	n = 1;
	while (1)
	{
		x[n] = x[n - 1] * ax + bx;
		y[n] = y[n - 1] * ay + by;
		if (x[n] <= INF && y[n] <= INF)
			n++;
		else
			break;
	}
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (t >= abs(sx - x[i]) + abs(sy - y[i]) + abs(x[i] - x[j]) + abs(y[i] - y[j]))
				ans = max(ans,abs(i - j) + 1);
	printf("%d\n",ans);
	return 0;
}