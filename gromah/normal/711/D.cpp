#include <cstdio>
typedef long long LL;
#define N 200000 + 5
#define Mod 1000000007

int n, cnt, ans, l = 1, r = 0, Out[N], Deg[N], Pow[N], q[N];
bool Flag[N];

int main()
{
	scanf("%d", &n);
	Pow[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", Out + i);
		Deg[Out[i]] ++;
		Pow[i] = Pow[i - 1] * 2 % Mod;
	}
	for (int i = 1; i <= n; i ++)
		if (!Deg[i]) q[++ r] = i;
	while (l <= r)
	{
		int z = q[l ++];
		Flag[z] = 1;
		Deg[Out[z]] --;
		if (!Deg[Out[z]])
			q[++ r] = Out[z];
	}
	ans = Pow[r];
	for (int i = 1; i <= n; i ++)
	{
		if (Flag[i]) continue ;
		int cnt = 1;
		Flag[i] = 1;
		for (int j = Out[i]; j != i; j = Out[j])
			Flag[j] = 1, cnt ++;
		ans = (LL) ans * (Pow[cnt] - 2 + Mod) % Mod;
	}
	printf("%d\n", ans);
	return 0;
}