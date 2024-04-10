#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define maxn 305
#define mod 1000000007
#define ll long long
using namespace std;
bool bpr[maxn * maxn];
int prms[maxn * maxn], prcnt = 0;
int a[maxn];
ll dp[maxn][maxn]; //   
ll ldp[maxn][maxn];
int main()
{
	for(int i = 0; i < maxn * maxn; i++) bpr[i] = 1;
	for(int i = 2; i < maxn * maxn; i++)
	{
		if(!bpr[i]) continue;
		for(int j = 2; j * i < maxn * maxn; j++)
			bpr[j * i] = 0;
		prms[prcnt++] = i;
	}
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < prcnt; j++)
			if(!(a[i] % prms[j]))
			{
				int cnt = 0;
				while(!(a[i] % prms[j]))
					a[i] /= prms[j], cnt++;
				cnt &= 1;
				if(cnt) a[i] *= prms[j];
			}
	}
	sort(a + 1, a + n + 1);
	int len = 0;
	dp[0][0] = 1;
	for(int i = 1; i <= n; )
	{
		if(i != 1)
		{
			memset(ldp, 0, sizeof(ldp));
			for(int j = 0; j < maxn; j++)
				for(int k = 0; k < maxn; k++)
					if(dp[j][k])
						ldp[0][j + k] += dp[j][k];
			memset(dp, 0, sizeof(dp));
			for(int j = 0; j < maxn; j++)
				dp[0][j] = ldp[0][j];
		}
		int j = i;
		for(; j <= n && a[j] == a[i]; j++)
		{
		//	cout<<"SOLVE"<<j<<endl;
			memset(ldp, 0, sizeof(ldp));
			for(int j = 0; j < maxn; j++)
				for(int k = 0; k < maxn; k++)
					ldp[j][k] = dp[j][k];
			memset(dp, 0, sizeof(dp));
			int sms = j - i;
			for(int j = 0; j < maxn; j++)
				for(int k = 0; k < maxn; k++)
				{
					if(!ldp[k][j]) continue; 
					if(j) dp[k][j - 1] += j * ldp[k][j], dp[k][j - 1] %= mod;
					int nrs = sms * 2 - k;
					dp[k + 1][j] += nrs * ldp[k][j], dp[k + 1][j] %= mod;
					dp[k][j] += (i + sms - j - nrs) * ldp[k][j], dp[k][j] %= mod;
				}
		//	for(int k = 0; k < maxn; k++)
		//		for(int l = 0; l < maxn; l++)
		//			if(dp[k][l])
		//				cout<<k<<" "<<l<<" "<<dp[k][l]<<endl; 
		}
		i = j; 
	}
	printf("%I64d\n", dp[0][0]);
	return 0;
 }