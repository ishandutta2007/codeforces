#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXA = 1e5 + 5;
const int B = 50;
const int DIF = MAXA / B + 1;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 1;
	for(int k=-B; k<=B; ++k)
	{
		static int cnt[MAXN * B + MAXA], val[MAXN];
		
		const int C = max(n * k, 0);
		for(int i=1; i<=n; ++i)
			ans = max(ans, ++cnt[val[i] = a[i] - i * k + C]);
		for(int i=1; i<=n; ++i)
			cnt[val[i]] = 0;
	}
	if(DIF+1 > ans)
	{
		for(int i=1; i<=n; ++i)
		{	
			static int cnt[MAXA * 2], val[MAXN];
			const int C = MAXA;
			
			int mnj = max(1, i - DIF);
			for(int j=mnj; j<i; ++j)
			{
				if((a[i] - a[j]) % (i-j) == 0)
				{
					val[j] = (a[i] - a[j]) / (i - j) + C;
					ans = max(ans, ++cnt[val[j]] + 1);
				}
				else
				{
					val[j] = -1;
				}
			}
			for(int j=mnj; j<i; ++j)
				if(val[j] != -1)
					cnt[val[j]] = 0;
		}
	}
	
	printf("%d",n - ans);
	return 0;
}