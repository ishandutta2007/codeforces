#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int T,n,ll,rr,ans;
int l[MAXN];
int r[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&ll,&rr);
		for (int i = 1;i <= n;i++)
			l[i] = r[i] = 0;
		for (int a,i = 1;i <= ll;i++)
		{
			scanf("%d",&a);
			l[a]++;
		}
		for (int a,i = 1;i <= rr;i++)
		{
			scanf("%d",&a);
			r[a]++;
		}
		ans = 0;
		int L = 0,R = 0,tot = 0,ok = 0;
		for (int i = 1;i <= n;i++)
		{
			int t = min(l[i],r[i]);
			l[i] -= t;
			r[i] -= t;
			int cnt = l[i] + r[i];
			tot += cnt;
			if (ll > rr)
				ok += l[i] / 2;
			if (ll < rr)
				ok += r[i] / 2;
		}
		int less = min(ok,(max(ll,rr) - min(ll,rr)) / 2);
		ans += (max(ll,rr) - min(ll,rr)) / 2;
		ans += (tot - less * 2) / 2;
		printf("%d\n",ans);
	}
	return 0;
}