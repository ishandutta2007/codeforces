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

const int MAXN = 3005;

int R,C,n,m;
int p[25];

ll tot,ans;

multiset<int> S;
vector<int> g[MAXN];

int main()
{
	scanf("%d%d%d%d",&R,&C,&n,&m);
	for (int r,c,i = 1;i <= n;i++)
	{
		scanf("%d%d",&r,&c);
		g[r].push_back(c);
	}
	for (int i = 1;i <= R;i++)
	{
		S.clear();
		tot = 0;
		for (int j = i;j <= R;j++)
		{
			for (int k = 0;k < g[j].size();k++)
			{
				int v = g[j][k];
				multiset<int>::iterator it = S.insert(v),tmp = it;
				for (int l = m - 1;l >= 0;l--)
				{
					if (it == S.begin())
						p[l] = 0;
					else
						p[l] = *(--it);
				}
				p[m] = v;
				it = tmp;
				it++;
				for (int l = m + 1;l <= 2 * m;l++)
				{
					if (it == S.end())
						p[l] = C + 1;
					else
						p[l] = *(it++);
				}
				for (int l = 1;l <= m;l++)
					tot += (p[l] - p[l - 1]) * (p[l + m] - p[l + m - 1]);
			}
			ans += tot;
		}
	}
	printf("%lld\n",ans);
	return 0;
}