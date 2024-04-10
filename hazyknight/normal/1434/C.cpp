#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T,a,b,c,d;

ll getval(int t)
{
	/*
	ll h = 0,cnt = 0;
	queue<int> p;
	for (int i = 0;;i++)
	{
		h -= cnt * b;
		if (p.size() && p.front() == i)
		{
			cnt--;
			p.pop();
		}
		if (i % d == 0)
		{
			h += a;
			cnt++;
			p.push(i + c);
			t--;
			if (!t)
				return h;
		}
	}
	*/
	ll res = (a - (ll)b * c) * t;
	int tt = c - min(t - 1,c / d) * d;
	res += (ll)b * (tt + c) * ((c - tt) / d + 1) / 2;
	return res;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (a > (ll)b * c)
		{
			puts("-1");
			continue;
		}
		int low = 1,high = 1e6;
		while (low < high)
		{
			int mid = low + high >> 1;
			if (getval(mid) == getval(mid + 1))
			{
				low = mid;
				break;
			}
			if (getval(mid) > getval(mid + 1))
				high = mid;
			else
				low = mid + 1;
		}
		printf("%lld\n",getval(low));
	}
	return 0;
}