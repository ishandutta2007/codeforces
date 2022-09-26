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
 
const int MAXN = 1100005;
 
int T,n,m;
int a[MAXN << 1];
int d[MAXN];
 
ll ans;
 
vector<int> ANS;
 
int searchMAX(int u)
{
	if (!a[u << 1] && !a[u << 1 | 1])
		return u;
	if (a[u << 1] > a[u << 1 | 1])
		return searchMAX(u << 1);
	return searchMAX(u << 1 | 1);
}
 
void f(int u)
{
	if (!a[u << 1] && !a[u << 1 | 1])
	{
		a[u] = 0;
		return;
	}
	if (a[u << 1] > a[u << 1 | 1])
	{
		a[u] = a[u << 1];
		f(u << 1);
	}
	else
	{
		a[u] = a[u << 1 | 1];
		f(u << 1 | 1);
	}
}
 
void solve(int u)
{
	if (!a[u])
		return;
	while (d[searchMAX(u)] > m)
	{
		ans -= a[u];
		ANS.push_back(u);
		f(u);
	}
	solve(u << 1);
	solve(u << 1 | 1);
}
 
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ANS.clear();
		scanf("%d%d",&n,&m);
		ans = 0;
		for (int i = 1;i <= (1 << (n + 1)) - 1;i++)
		    a[i] = 0;
		for (int i = 1;i <= (1 << n) - 1;i++)
		{
			scanf("%d",&a[i]);
			ans += a[i];
			d[i] = d[i >> 1] + 1;
		}
		solve(1);
		printf("%lld\n",ans);
		for (int i = 0;i < ANS.size();i++)
			printf("%d ",ANS[i]);
		printf("\n");
	}
	return 0;
}