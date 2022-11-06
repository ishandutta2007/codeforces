#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int n, t_u, t_d, q_u[N], q_d[N];
char s[N];
LL Sum_u[N], Sum_d[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++)
		if (s[i] == 'U')
		{
			q_u[++ q_u[0]] = i;
			Sum_u[q_u[0]] = Sum_u[q_u[0] - 1] + i * 2;
		}
	for (int i = n; i; i --)
		if (s[i] == 'D')
		{
			q_d[++ q_d[0]] = i;
			Sum_d[q_d[0]] = Sum_d[q_d[0] - 1] + i * 2;
		}
	t_u = 0, t_d = q_d[0];
	for (int i = 1; i <= n; i ++)
	{
		LL ans = 0;
		if (s[i] == 'U')
		{
			if (t_d <= t_u)
				ans = Sum_d[t_d] - (Sum_u[t_u] - Sum_u[t_u - t_d]) + n + 1 - i;
			else ans = Sum_d[t_d] - Sum_d[t_d - t_u - 1] - Sum_u[t_u] - i;
			t_u ++;
		}
		else
		{
			t_d --;
			if (t_u <= t_d)
				ans = Sum_d[t_d] - Sum_d[t_d - t_u] - Sum_u[t_u] + i;
			else ans = Sum_d[t_d] - (Sum_u[t_u] - Sum_u[t_u - t_d - 1]) + n + 1 + i;
		}
		printf("%I64d%c", ans, i == n ? '\n' : ' ');
	}
	return 0;
}