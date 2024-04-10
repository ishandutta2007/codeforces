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

const int MAXN = 1000005;

int n;
int v[MAXN];

ll a,b,ans;

set<int> S;

void work(int v)
{
	for (int i = 2;i * i <= v;i++)
	{
		if (v % i == 0)
			S.insert(i);
		while (v % i == 0)
			v /= i;
	}
	if (v > 1)
		S.insert(v);
}

void go(int g)
{
	int l = n + 1,r = 0;
	for (int i = 1;i <= n;i++)
		if (v[i] % g != 0 && v[i] % g != 1 && v[i] % g != g - 1)
		{
			l = min(l,i);
			r = max(r,i);
		}
	ll MN = 1e18,tot = 0,rtot = 0;
	for (int i = 1;i <= n;i++)
		rtot += (v[i] % g != 0);
	for (int i = 1;i <= n;i++)
	{
		tot += (v[i] % g != 0);
		if (i > r)
		{
			ans = min(ans,MN + (i - 1) * a + rtot * b);
			ans = min(ans,(i - 1) * a + rtot * b);
		}
		if (i < l)
		{
			MN = min(MN,-i * a + tot * b);
			ans = min(ans,(n - i) * a + tot * b);
		}
		rtot -= (v[i] % g != 0);
	}
}

int main()
{
	scanf("%d%lld%lld",&n,&a,&b);
	for (int i = 1;i <= n;i++)
		scanf("%d",&v[i]);
	ans = 1e18;
	work(v[1] - 1);
	work(v[1]);
	work(v[1] + 1);
	work(v[n] - 1);
	work(v[n]);
	work(v[n] + 1);
	for (set<int>::iterator i = S.begin();i != S.end();i++)
		go(*i);
	printf("%lld\n",ans);
	return 0;
}