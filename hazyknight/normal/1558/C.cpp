#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

const int MAXN = 2025;

int T,n;
int v[MAXN];

int getpos(int x)
{
	for (int i = 1;i <= n;i++)
		if (v[i] == x)
			return i;
}

void opr(int t)
{
	printf("%d ",t);
	reverse(v + 1,v + t + 1);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		bool ok = 1;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&v[i]);
			if ((v[i] & 1) != (i & 1))
				ok = 0;
		}
		if (!ok)
		{
			puts("-1");
			continue;
		}
		printf("%d\n",(n / 2) * 5);
		for (int i = n;i >= 3;i -= 2)
		{
			opr(getpos(i));
			opr(getpos(i - 1) - 1);
			opr(getpos(i - 1) + 1);
			opr(3);
			opr(i);
		}
		printf("\n");
	}
	return 0;
}