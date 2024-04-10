#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MOD = 1000000007;

int T,n,m,ans;
int a[MAXN];
int r[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		r[n] = n;
		for (int i = n - 1;i >= 1;i--)
			r[i] = (a[i] == a[i + 1] ? r[i + 1] : i);
		int ans = n;
		for (int i = 1;i <= n;i++)
		{
			int st = a[i],lst = a[i],pos = r[i],cnt = r[i] - i + 1;
			while (1)
			{
				int t = lower_bound(a + pos + 1,a + n + 1,lst + lst - st) - a;
				if (t > n)
					break;
				cnt++;
				pos = t;
				lst = a[t];
			}
			ans = min(ans,n - cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}