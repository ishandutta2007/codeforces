#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define maxn 505
using namespace std;
const int mo = 998244353;
int n;
int type[maxn], a[maxn];
char s[10];
int f[maxn][maxn];//ij 
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		if(s[1] == '+') type[i] = 1;
		else type[i] = 0;
		if(type[i]) scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if(!type[i]) continue;
		f[0][0] = 1;
		for (int j = 1; j <= n; j++)
		{
			if(j == i)
			{
				for (int k = 0; k <= n; k++)
				{
					f[j][k] = f[j - 1][k];
				}
				continue;
			}
			if(type[j])
			{
				if(a[j] > a[i] || ( a[j] == a[i] && j > i))
				{
					for (int k = 0; k <= n; k++)
					{
						f[j][k] = f[j - 1][k] * 2 % mo;
					}
				}
				else
				{
					for (int k = 0; k <= n; k++)
					{
						if(k == 0) f[j][k] = f[j - 1][k] % mo;
						else f[j][k] = (f[j - 1][k - 1] + f[j - 1][k])% mo;
					}
				}
			}
			else
			{
				for (int k = 0; k <= n; k++)
				{
					f[j][k] = (f[j - 1][k] + f[j - 1][k + 1]) % mo;
				}
				if(j < i) f[j][0] = (f[j - 1][0] * 2 % mo + f[j - 1][1]) % mo;
			}
		}
		int cnt = 0;
		for (int j = 0; j <= n; j++)
		{
			cnt = (cnt + f[n][j]) % mo;
//			printf("%d %d %d\n", i, j, f[n][j]);
		}
		ans = (ans + (ll)cnt * a[i] % mo) % mo;
	}
	printf("%d", ans);
	return 0;
}