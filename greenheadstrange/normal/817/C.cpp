#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 20 
#define maxs 200
using namespace std;
int num[maxn];
ll ans[maxn][maxs], hard[maxn][maxs];
ll solve(ll a, int x)
{	// <= a x 
	int ns = 0;
	while(a)	
		num[ns++] = a % 10, a /= 10;
	memset(ans, 0, sizeof(ans)); 
	memset(hard, 0, sizeof(hard));
	for(int i = 0; i < ns; i++)
	{
		if(!i)
		{
			for(int j = 0; j <= 9; j++)
				ans[i][j] = 1;
			for(int j = 0; j <= num[i]; j++)
				hard[i][j] = 1;
			continue;
		}
		for(int j = 0; j <= x; j++)
			for(int k = 0; k <= min(j, 9); k++)
				ans[i][j] += ans[i - 1][j - k];
		for(int j = 0; j <= x; j++)
			for(int k = 0; k <= min(j, num[i]); k++)
				if(k == num[i]) hard[i][j] += hard[i - 1][j - k];
				else hard[i][j] += ans[i - 1][j - k];
	}
	return hard[ns - 1][x];
}
int main()
{
	ll n, s;
	scanf("%I64d%I64d", &n, &s);
	ll ans = 0;
	for(int i = 1; i <= 180; i++)
		if(s + i - 1 <= n) ans += solve(n, i) - solve(s + i - 1, i);
	printf("%I64d\n", ans);
	return 0;
 }