#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100005
using namespace std;
int T, n, a[maxn];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if(n == 1 && a[1] == 0)
	{
		printf("1 2\n");
		return;
	}
	if(a[1] == 1)
	{
		printf("%d ", n + 1);
		for (int i = 1; i <= n; i++) printf("%d ", i);
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if(a[i] == 1)
			{
				for (int j = 1; j < i; j++) printf("%d ", j);
				printf("%d ", n + 1);
				for (int j = i; j <= n; j++) printf("%d ", j);
				break;
			}
			if(i == n)
			{
				for (int j = 1; j <= n + 1; j++) printf("%d ", j);
			}
		}
	}
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}