#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
#define ll long long
using namespace std;
int a[maxn], b[maxn];
int n, k, p; 
bool hv[maxn];
int dis[maxn][maxn];
int ndis[maxn]; 
bool check(ll x)
{
	memset(hv, 0, sizeof(hv));
	for(int i = 1; i <= n; i++)
	{
		bool flag = false;
		for(int j = 1; j <= k; j++)
		{
			if(hv[j]) continue;
			if(dis[i][j] + ndis[j] <= x)
			{
				flag = 1, hv[j] = 1;
				break;
			}
		}
		if(!flag) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d", &n, &k, &p);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= k; i++)
		scanf("%d", &b[i]);

	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
			dis[i][j] = abs(a[i] - b[j]);
	for(int j = 1; j <= k; j++)
		ndis[j] = abs(b[j] - p);
	ll l = 0, r = 1000000000 * 2;
	while(l < r)
	{	
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
		
	}
	printf("%I64d\n", l);
	
	return 0;
}