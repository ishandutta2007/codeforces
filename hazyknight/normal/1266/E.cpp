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

const int MAXN = 200005;

int n,q;
int a[MAXN];
int t[MAXN];

ll ans;

map<int,int> match[MAXN];

void add(int p,int v)
{
	ans -= max(a[p] - t[p],0);
	t[p] += v;
	ans += max(a[p] - t[p],0);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		ans += a[i];
	}
	scanf("%d",&q);
	while (q--)
	{
		int s,t,u;
		scanf("%d%d%d",&s,&t,&u);
		if (match[s][t])
		{
			add(match[s][t],-1);
			match[s][t] = 0;
		}
		if (u)
			add(match[s][t] = u,1);
		printf("%lld\n",ans);
	}
	return 0;
}