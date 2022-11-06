#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define M 1000000 + 5

int n, k, l, r, last, ptr;
char s[M], Ans[N][N];

int main()
{
	scanf("%d%d%d", &n, &l, &k);
	scanf("%s", s);
	sort(s, s + n * l);
	last = 1;
	for (r = 1; r <= l && last < k; r ++)
	{
		for (int i = last; i <= k; i ++)
			Ans[i][r] = s[ptr ++];
		for (last = k; last > 1 && Ans[last - 1][r] == Ans[k][r]; last --) ;
	}
	for (; r <= l; r ++)
		Ans[k][r] = s[ptr ++];
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= l; j ++)
			if (Ans[i][j] == '\0')
				Ans[i][j] = s[ptr ++];
		printf("%s\n", Ans[i] + 1);
	}
	return 0;
}