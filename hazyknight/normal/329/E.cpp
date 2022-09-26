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

int n;

pair<int,int> x[MAXN];
pair<int,int> y[MAXN];

bool sidex[MAXN][2];
bool sidey[MAXN][2];

void extend()
{
	for (int i = n + 1;i <= 2 * n;i++)
	{
		x[i] = x[i - n];
		y[i] = y[i - n];
	}
	sort(x + 1,x + 2 * n + 1);
	sort(y + 1,y + 2 * n + 1);
}

ll getans()
{
	ll res = 0;
	for (int i = 1;i <= n;i++)
		res -= x[i].first + y[i].first;
	for (int i = n + 1;i <= 2 * n;i++)
		res += x[i].first + y[i].first;
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&x[i].first,&y[i].first);
		x[i].second = y[i].second = i;
	}
	sort(x + 1,x + n + 1);
	sort(y + 1,y + n + 1);
	for (int i = 1;i <= n / 2;i++)
	{
		sidex[x[i].second][0] = 1;
		sidey[y[i].second][0] = 1;
	}
	for (int i = n / 2 + 1 + (n & 1);i <= n;i++)
	{
		sidex[x[i].second][1] = 1;
		sidey[y[i].second][1] = 1;
	}
	bool oneside = 0,bothside = 0;
	for (int i = 1;i <= n;i++)
	{
		if ((n & 1) && i == x[n / 2 + 1].second)
			continue;
		if ((sidex[i][0] && sidey[i][0]) || (sidex[i][1] && sidey[i][1]))
			oneside = 1;
		else
			bothside = 1;
	}
	if (oneside ^ bothside)
	{
		extend();
		printf("%lld\n",getans());
		return 0;
	}
	if (n & 1)
	{
		if (x[n / 2 + 1].second != y[n / 2 + 1].second)
		{
			extend();
			printf("%lld\n",getans());
			return 0;
		}
		extend();
		swap(x[n],x[n + 2]);
		ll ansA = getans();
		swap(x[n],x[n + 2]);
		swap(x[n - 1],x[n + 1]);
		ll ansB = getans();
		swap(x[n - 1],x[n + 1]);
		swap(y[n],y[n + 2]);
		ll ansC = getans();
		swap(y[n],y[n + 2]);
		swap(y[n - 1],y[n + 1]);
		ll ansD = getans();
		printf("%lld\n",max(max(ansA,ansB),max(ansC,ansD)));
	}
	else
	{
		extend();
		swap(x[n],x[n + 1]);
		ll ansA = getans();
		swap(x[n],x[n + 1]);
		swap(y[n],y[n + 1]);
		ll ansB = getans();
		printf("%lld\n",max(ansA,ansB));
	}
	return 0;
}