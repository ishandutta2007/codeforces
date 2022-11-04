#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n;
int a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			a[i] = abs(a[i]);
		}
		for (int i = 1;i <= n;i++)
			printf("%d ",(i & 1) ? -a[i] : a[i]);
		printf("\n");
	}
	return 0;
}