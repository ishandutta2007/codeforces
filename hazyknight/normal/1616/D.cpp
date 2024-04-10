#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 50005;

int T,n,x,top;
int L[MAXN];
int a[MAXN];
int S[MAXN];

ll sum[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&x);
		for (int i = 1;i <= n;i++)
			a[i] -= x;
		for (int i = 1;i <= n;i++)
			sum[i] = sum[i - 1] + a[i];
		top = 0;
		for (int i = 1;i <= n;i++)
		{
			L[i] = -1;
			for (int j = top;j >= 1;j--)
				if (sum[S[j]] > sum[i])
				{
					L[i] = S[j] + 1;
					break;
				}
			while (top >= 1 && sum[S[top]] <= sum[i - 1])
				top--;
			S[++top] = i - 1;
		}
		int MX = 0;
		for (int i = 1;i <= n;i++)
			if (~L[i])
			{
				if (L[i] <= MX)
					L[i] = -1;
				else
					MX = L[i];
			}
		int MN = n + 1,cnt = 0;
		for (int i = n;i >= 1;i--)
			if (~L[i] && i < MN)
			{
				MN = L[i];
				cnt++;
			}
		printf("%d\n",n - cnt);
	}
	return 0;
}