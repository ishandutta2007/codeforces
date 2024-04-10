#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int T,n,q;
int a[MAXN];
int b[MAXN];

map<int,int> Cnt;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		Cnt.clear();
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			int v = 1;
			for (int j = 2;j * j <= a[i];j++)
				if (a[i] % j == 0)
				{
					int cnt = 0;
					while (a[i] % j == 0)
					{
						a[i] /= j;
						cnt++;
					}
					if (cnt & 1)
						v *= j;
				}
			if (a[i] > 1)
				v *= a[i];
			b[i] = v;
			Cnt[b[i]]++;
		}
		int ans0 = 0,ans1 = 0;
		for (map<int,int>::iterator it = Cnt.begin();it != Cnt.end();it++)
		{
			ans0 = max(ans0,it->second);
			if ((~it->second & 1) || it->first == 1)
				ans1 += it->second;
		}
		ans1 = max(ans1,ans0);
		scanf("%d",&q);
		while (q--)
		{
			ll t = 0;
			scanf("%lld",&t);
			t = min(t,1ll);
			printf("%d\n",t ? ans1 : ans0);
		}
	}
	return 0;
}