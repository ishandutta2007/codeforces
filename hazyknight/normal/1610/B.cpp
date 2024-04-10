#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int T,n;
int a[MAXN];
int b[MAXN];

bool work(int v)
{
	int m = 0;
	for (int i = 1;i <= n;i++)
		if (a[i] != v)
			b[++m] = a[i];
	for (int i = 1,j = m;i <= j;i++,j--)
		if (b[i] != b[j])
			return 0;
	return 1; 
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		int ok = -1;
		for (int i = 1,j = n;i <= j;i++,j--)
			if (a[i] != a[j])
			{
				if (work(a[i]) || work(a[j]))
				{
					ok = 1;
					puts("YES");
					break;
				}
				ok = 0;
				break;
			}
		if (!ok)
			puts("NO");
		if (ok == -1)
			puts("YES");
	}
	return 0;
}