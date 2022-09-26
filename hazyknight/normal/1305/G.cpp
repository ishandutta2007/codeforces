#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
int cnt[1 << 18];
int fa[1 << 18];

ll ans;

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d",&n);
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		cnt[a]++;
		ans -= a;
	}
	cnt[0]++;
	for (int i = 0;i < (1 << 18);i++)
		fa[i] = i;
	for (int i = (1 << 18) - 1;i >= 0;i--)
		for (int S = i;S > (i ^ S);S = (S - 1) & i)
			if (cnt[S] && cnt[i ^ S] && getroot(S) != getroot(i ^ S))
			{
				fa[getroot(S)] = getroot(i ^ S);
				ans += (ll)(cnt[S] + cnt[i ^ S] - 1) * i;
				cnt[S] = cnt[i ^ S] = 1;
			}
	printf("%lld\n",ans);
	return 0;
}