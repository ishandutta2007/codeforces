#include <bits/stdc++.h>

using namespace std;

int n;

long long ans;

map<pair<int,int>,int> cnt;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		cnt.clear();
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			int x,y,u,v;
			scanf("%d%d%d%d",&x,&y,&u,&v);
			x -= u;
			y -= v;
			int g = __gcd(abs(x),abs(y));
			x /= g;
			y /= g;
			ans += cnt[make_pair(-x,-y)];
			cnt[make_pair(x,y)]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}