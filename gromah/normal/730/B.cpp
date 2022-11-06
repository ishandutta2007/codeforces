#include <cstdio>
#include <algorithm>
using namespace std;
#define N 50 + 5

int T, n, Max[N], Min[N];
char res[9];

inline int Solve(int *p, char op)
{
	if (p[0] == 1) return p[1];
	int tmp = p[0];
	p[0] = 0;
	for (int i = 2; i <= tmp; i += 2)
	{
		printf("? %d %d\n", p[i - 1], p[i]);
		fflush(stdout);
		scanf("%s", res);
		if (res[0] == op)
			p[++ p[0]] = p[i - 1];
		else p[++ p[0]] = p[i];
	}
	if (tmp & 1) p[++ p[0]] = p[tmp];
	return Solve(p, op);
}

int main()
{
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d", &n);
		if (n == 1)
		{
			puts("! 1 1");
			fflush(stdout);
			continue ;
		}
		Max[0] = Min[0] = 0;
		for (int i = 2; i <= n; i += 2)
		{
			printf("? %d %d\n", i - 1, i);
			fflush(stdout);
			scanf("%s", res);
			Max[++ Max[0]] = Min[++ Min[0]] = i;
			if (res[0] == '<')
				Min[Min[0]] --;
			else Max[Max[0]] --;
		}
		if (n & 1) Min[++ Min[0]] = Max[++ Max[0]] = n;
		int _Max = Solve(Max, '>');
		int _Min = Solve(Min, '<');
		printf("! %d %d\n", _Min, _Max);
		fflush(stdout);
	}
	return 0;
}