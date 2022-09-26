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

int T,d,m;

ll ans;
ll f[35];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&d,&m);
		ans = 0;
		for (int i = 0;i < 30;i++)
			if (d >= (1 << i))
			{
				(f[i] += min(d,(1 << (i + 1)) - 1) - (1 << i) + 1) %= m;
				(ans += f[i]) %= m;
				for (int j = i + 1;j < 30;j++)
					if (d >= (1 << j))
						(f[j] += f[i] * (min(d,(1 << (j + 1)) - 1) - (1 << j) + 1)) %= m;
			}
		printf("%lld\n",ans);
	}
	return 0;
}