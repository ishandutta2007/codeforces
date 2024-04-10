#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n,q;
int a[MAXN];
int cnt[2];

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for (int i = 1;i <= q;i++)
	{
		int tp,x;
		scanf("%d%d",&tp,&x);
		if (tp == 1)
		{
			cnt[a[x]]--;
			a[x] ^= 1;
			cnt[a[x]]++;
		}
		else
		{
			if (x <= cnt[1])
				puts("1");
			else
				puts("0");
		}
	}
	return 0;
}