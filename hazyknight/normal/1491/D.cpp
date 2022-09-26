#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int T,u,v;
int a[MAXN];
int b[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&u,&v);
		if (u > v)
		{
			puts("NO");
			continue;
		}
		int tota = 0,totb = 0;
		for (int i = 0;i < 30;i++)
		{
			if (u >> i & 1)
				a[++tota] = i;
			if (v >> i & 1)
				b[++totb] = i;
		}
		bool ok = 1;
		for (int i = 1;i <= totb;i++)
		{
			int cnt = 0;
			for (int j = 1;j <= tota;j++)
				if (b[i] >= a[j])
					cnt++;
			if (cnt < i)
				ok = 0;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}