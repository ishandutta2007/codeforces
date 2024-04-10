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
 
ll ans;
ll a[MAXN];
 
map<ll,bool> vis;
 
int Rand()
{
	return rand() << 15 | rand();
}
 
void work(ll v)
{
	if (vis[v])
		return;
	vis[v] = 1;
	ll cnt = 0;
	for (int i = 1;i <= n && cnt <= ans;i++)
	{
		ll low = a[i] / v * v,high = low + v;
		if (!low)
			cnt += high - a[i];
		else
			cnt += min(high - a[i],a[i] - low);
	}
	ans = min(ans,cnt);
}
 
void solve(ll g)
{
	for (ll i = 2;i * i <= g;i++)
	{
		if (g % i == 0)
			work(i);
		while (g % i == 0)
			g /= i;
	}
	if (g > 1)
		work(g);
}
 
int main()
{
	srand((unsigned long long)new char);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	ans = n;
	int T = 30;
	while (T--)
	{
		int u = Rand() % n + 1;
		for (int i = -1;i <= 1;i++)
			solve(a[u] + i);
	}
	printf("%lld\n",ans);
	return 0;
}