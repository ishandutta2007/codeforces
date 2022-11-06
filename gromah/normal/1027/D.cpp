#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define INF 0x3f3f3f3f

int n, cnt, C[N], Next[N], Col[N], Min[N], Stack[N], W[N];
LL ans;
bool Flag[N], Ins[N];

void dfs(int z)
{
	if (Flag[z])
	{
		if (!Ins[z]) return ;
		cnt ++;
		for (int i = Stack[0]; i; i --)
		{
			Col[Stack[i]] = cnt;
			if (Stack[i] == z) break ;
		}
		return ;
	}
	Stack[++ Stack[0]] = z;
	Flag[z] = 1, Ins[z] = 1;
	dfs(Next[z]);
	Ins[z] = 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", C + i);
	for (int i = 1; i <= n; i ++)
		scanf("%d", Next + i);
	for (int i = 1; i <= n; i ++)
		if (!Flag[i])
		{
			Stack[0] = 0;
			dfs(i);
		}
	for (int i = 1; i <= cnt; i ++)
		W[i] = INF;
	for (int i = 1; i <= n; i ++)
		if (Col[i])
			W[Col[i]] = min(W[Col[i]], C[i]);
	for (int i = 1; i <= cnt; i ++)
		ans += W[i];
	printf("%lld\n", ans);
	return 0;
}