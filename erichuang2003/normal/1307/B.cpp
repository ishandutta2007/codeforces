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

int T,n,x,ans,MAX;
int a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&x);
		ans = 1e9 + 2;
		MAX = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i] == x)
				ans = 1;
			MAX = max(MAX,a[i]);
		}
		if (MAX > x)
			ans = min(ans,2);
		else
			ans = min(ans,(x - 1) / MAX + 1);
		cout << ans << endl;
	}
	return 0;
}