#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, a, b, k, Ans[N];
char s[N];

int main()
{
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", s);
	for (int i = 0, succ = 0; i < n; i ++)
	{
		if (s[i] == '1') succ = 0;
		else succ ++;
		if (succ == b)
		{
			if (a == 1) Ans[++ Ans[0]] = i + 1;
			else a --;
			succ = 0;
		}
	}
	printf("%d\n", Ans[0]);
	for (int i = 1; i <= Ans[0]; i ++)
		printf("%d%c", Ans[i], i == Ans[0] ? '\n' : ' ');
	return 0;
}