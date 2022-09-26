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

const int MAXN = 100005;

int n,m,q;

ll ans;
ll s[MAXN];
ll b[MAXN];

vector<int> e[MAXN];

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		s[max(u,v)]++;
		b[min(u,v)]++;
		e[min(u,v)].push_back(max(u,v));
	}
	for (int i = 1;i <= n;i++)
		ans += s[i] * b[i];
	printf("%lld\n",ans);
	scanf("%d",&q);
	while (q--)
	{
		int u;
		scanf("%d",&u);
		ans -= s[u] * b[u];
		s[u] += b[u];
		b[u] = 0;
		for (int i = 0;i < e[u].size();i++)
		{
			int to = e[u][i];
			e[to].push_back(u);
			ans -= s[to] * b[to];
			s[to]--;
			b[to]++;
			ans += s[to] * b[to];
		}
		e[u].clear();
		printf("%lld\n",ans);
	}
	return 0;
}