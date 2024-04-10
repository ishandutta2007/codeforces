#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
int a[MAXN];
int pos[MAXN];

ll sum1[MAXN];
ll sum2[MAXN];

ll modify(ll *sum,int p,ll v)
{
	while (p <= n)
	{
		sum[p] += v;
		p += p & -p;
	}
}

ll query(ll *sum,int p)
{
	ll res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]] = i;
	}
	ll ans1 = 0;
	for (int i = 1;i <= n;i++)
	{
		ans1 += i - 1 - query(sum1,pos[i]);
		modify(sum1,pos[i],1);
		modify(sum2,pos[i],pos[i]);
		int low = 1,high = n;
		while (low < high)
		{
			int mid = low + high + 1 >> 1;
			if (query(sum1,mid - 1) * 2 <= i)
				low = mid;
			else
				high = mid - 1;
		}
		ll cnt = query(sum1,low),sum = query(sum2,low);
		ll ans2 = cnt * low - sum - cnt * (cnt - 1) / 2;
		cnt = i - cnt;
		ans2 += query(sum2,n) - sum - cnt * (low + 1) - cnt * (cnt - 1) / 2;
		printf("%lld ",ans1 + ans2);
	}
	printf("\n");
	return 0;
}