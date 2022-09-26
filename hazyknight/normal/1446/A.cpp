#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n,T;

ll W;

pair<ll,int> w[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%lld",&n,&W);
		for (int i = 1;i <= n;i++)
		{
			scanf("%lld",&w[i].first);
			w[i].second = i;
		}
		vector<int> ans;
		sort(w + 1,w + n + 1);
		ll cnt = 0;
		for (int i = n;i >= 1;i--)
		{
			if (cnt + w[i].first <= W)
			{
				cnt += w[i].first;
				ans.push_back(w[i].second);
			}
		}
		if (cnt * 2 < W)
			printf("-1\n");
		else
		{
			printf("%d\n",(int)ans.size());
			for (int i = 0;i < ans.size();i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}