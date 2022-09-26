#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int T,n;
int cnta[MAXN << 1];
int cntb[MAXN << 1];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 0;i <= 200;i++)
			cnta[i] = cntb[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			int a;
			scanf("%d",&a);
			cnta[a + 100]++;
		}
		for (int i = 1;i <= n;i++)
		{
			int b;
			scanf("%d",&b);
			cntb[b + 100]++;
		}
		bool ok = 1;
		for (int i = 200;i >= 0;i--)
			while (cnta[i])
			{
				if (cntb[i + 1])
					cntb[i + 1]--;
				else if (cntb[i])
					cntb[i]--;
				else
					ok = 0;
				cnta[i]--;
			}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}