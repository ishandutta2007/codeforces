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

int n,tot;
int a[MAXN];
int t[MAXN];
int val[MAXN];

ll ans;

map<int,int> match;
vector<int> tag[MAXN];
priority_queue<pair<int,int> > Q;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		val[++tot] = a[i];
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= tot;i++)
		match[val[i]] = i;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&t[i]);
		tag[match[a[i]]].push_back(t[i]);
	}
	val[tot + 1] = 2e9;
	for (int i = 1,j = 1;;i++)
	{
		while (j <= tot && val[j] < i)
			j++;
		if (j > tot && Q.empty())
			break;
		if (val[j] == i)
		{
			for (int k = 0;k < tag[j].size();k++)
				Q.push(make_pair(tag[j][k],val[j]));
		}
		if (Q.empty())
		{
			i = val[j] - 1;
			continue;
		}
		ans += (ll)Q.top().first * (i - Q.top().second);
		Q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}