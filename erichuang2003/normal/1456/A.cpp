#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n,p,k,x,y,ans;
int sum[MAXN];

char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%s%d%d",&n,&p,&k,s + 1,&x,&y);
		for (int i = 0;i <= n - p;i++)
			sum[i] = 0;
		for (int i = p;i <= n;i++)
			if (s[i] == '0')
				sum[i - p] += x;
		for (int i = n - p;i >= k;i--)
			sum[i - k] += sum[i];
		ans = 2e9;
		for (int i = 0;i <= n - p;i++)
			ans = min(ans,i * y + sum[i]);
		printf("%d\n",ans);
	}
	return 0;
}