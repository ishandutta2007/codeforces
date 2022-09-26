#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;

pair<ll,int> a[MAXN];

set<pair<ll,int> > S;

void go()
{
	for (int i = 3;i < n;i++)
		if (a[i].first - a[i - 1].first != a[i + 1].first - a[i].first)
			return;
	printf("%d\n",a[1].second);
	exit(0);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i].first);
		a[i].second = i;
	}
	sort(a + 1,a + n + 1);
	go();
	swap(a[1],a[2]);
	go();
	swap(a[1],a[2]);
	for (int i = 3;i <= n;i++)
		S.insert(a[i]);
	ll d = a[2].first - a[1].first,cur = a[2].first;
	for (int i = 3;i < n;i++)
	{
		cur += d;
		set<pair<ll,int> >::iterator it = S.lower_bound(make_pair(cur,0));
		if (it == S.end() || it->first != cur)
		{
			puts("-1");
			return 0;
		}
		S.erase(it);
	}
	printf("%d\n",S.begin()->second);
	return 0;
}