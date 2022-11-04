#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

const int MAXN = 500005;

int n,ans,k,tot,head,tail;
int Q[MAXN];

ll a[MAXN];
ll b[MAXN];
ll c[MAXN];
ll f[MAXN];
ll g[MAXN];
ll K[MAXN];
ll B[MAXN];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&c[i]);
	sort(c + 1,c + n + 1);
	ll ans = 0,score = 0;
	for (int i = n;i >= 1;i--)
	{
		ans += score;
		score += c[i];
		if (score < 0 && k)
		{
			a[1] = score;
			int cur = 2;
			for (int j = i - 1;j >= 1;j--)
			{
				ans += a[cur];
				a[cur] += c[j];
				cur = cur % (k + 1) + 1;
			}
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}