#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 55
#define maxm 100005
using namespace std;
const int mo = 998244353;
int n, m, l[maxn], r[maxn]; 
int f[maxn][maxm], sum[maxn][maxm];
int miu[maxm];
int prime[maxm], vis[maxm];
void get()
{
	int num = 0;
    miu[1]=1;
    for(int i=2;i<=m;i++)
    {
        if(!vis[i])prime[++num]=i,miu[i]=-1;
        for(int j=1;j<=num&&i*prime[j]<=m;j++)
        {
            vis[i*prime[j]]=1;
            if((i%prime[j])==0)
            {
                miu[i*prime[j]]=0;
                break;
            }
            miu[i*prime[j]]=-miu[i];
        }
    }
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
	get();
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if(miu[i] == 0) continue;
		int flag = 1;
		for (int j = 1; j <= n; j++)
		{
			if(r[j] / i < (l[j] + i - 1) / i) flag = 0;
		}
		if(flag == 0) continue;
		f[0][0] = 1;
		for (int j = 1; j <= n; j++)
		{
			sum[j - 1][0] = f[j - 1][0];
			for (int k = 1; k <= m / i; k++) sum[j - 1][k] = (f[j - 1][k] + sum[j - 1][k - 1]) % mo;
			for (int k = r[j] / i + 1; k <= m / i; k++) f[j][k] = (sum[j - 1][k - (l[j] + i - 1) / i] - sum[j - 1][k - (r[j] / i) - 1] + mo) % mo;
			for (int k = (l[j] + i - 1) / i; k <= r[j] / i; k++) 
			{
				f[j][k] = sum[j - 1][k - (l[j] + i - 1) / i]; 
			}
//			for (int k = 0; k <= 15; k++)
//			{
//				if(i == 1) printf("%d %d %d\n", j, k, f[j][k]);
//			}
		}
		int res = 0;
		for (int k = 0; k <= m / i; k++) res = (res + f[n][k]) % mo;
		res = (res * miu[i] + mo) % mo;
//		printf("%d %d\n", i, res);
		ans = (ans + res) % mo;
	}
	printf("%d", ans);
	return 0;
}