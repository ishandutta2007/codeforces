#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 500005;

ll n;
int r[MAXN];

char s[MAXN];

set<int> S;
vector<int> p[MAXN];

ll ans;

int main()
{
	scanf("%lld%s",&n,s + 1);
	for (int i = n;i >= 1;i--)
	{
		r[i] = (s[i] == '0' ? 0 : r[i + 1] + 1);
		p[r[i]].push_back(i);
	}
	ll cnt = n * (n + 1) / 2,one = 0;
	ll MAX = 0;
	for (int i = n;i >= 1;i--)
	{
		ll zero = n - one - (n - MAX);
		cnt -= zero;
		for (int j = 0;j < p[i].size();j++)
		{
			ll u = p[i][j];
			set<int>::iterator it = S.lower_bound(u);
			ll nxt = (it == S.end() ? n + 1 : *it);
			ll pre = (it == S.begin() ? 0 : *(--it));
			cnt -= (u - pre) * (min(nxt + i,n + 2) - 1) - (pre + 1 + u) * (u - pre) / 2;
			cnt += (u - pre - 1) * (u + i - 1) - (pre + u) * (u - pre - 1) / 2;
			MAX = max(MAX,u);
			S.insert(u);
			one++;
		}
		ll tot = (ll)n * (n + 1) / 2 - cnt - one * (i - 1);
		ans += tot;
	}
	printf("%lld\n",ans);
	return 0;
}